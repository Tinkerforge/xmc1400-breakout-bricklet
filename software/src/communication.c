/* xmc1400-breakout-bricklet
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * communication.c: TFP protocol message handling
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "communication.h"

#include "bricklib2/utility/communication_callback.h"
#include "bricklib2/protocols/tfp/tfp.h"

#include "xmc_gpio.h"
#include "example.h"
#include "adc.h"

// The type of the callback has to be defined before the include. 
// In this case of the example-count we use uint32.
#define CALLBACK_VALUE_TYPE CALLBACK_VALUE_TYPE_UINT32
#include "bricklib2/utility/callback_value.h"
CallbackValue_uint32_t callback_value_count;

// The handle_messages function that calls functions according to the function id is auto-generated
BootloaderHandleMessageResponse handle_message(const void *message, void *response) {
	switch(tfp_get_fid_from_message(message)) {
		case FID_SET_GPIO_CONFIG: return set_gpio_config(message);
		case FID_GET_GPIO_INPUT: return get_gpio_input(message, response);
		case FID_SET_ADC_CHANNEL_CONFIG: return set_adc_channel_config(message);
		case FID_GET_ADC_CHANNEL_CONFIG: return get_adc_channel_config(message, response);
		case FID_GET_ADC_CHANNEL_VALUE: return get_adc_channel_value(message, response);
		case FID_GET_ADC_VALUES: return get_adc_values(message, response);
		case FID_SET_ADC_VALUES_CALLBACK_CONFIGURATION: return set_adc_values_callback_configuration(message);
		case FID_GET_ADC_VALUES_CALLBACK_CONFIGURATION: return get_adc_values_callback_configuration(message, response);
		case FID_GET_COUNT: return get_callback_value_uint32_t(message, response, &callback_value_count);
		case FID_SET_COUNT_CALLBACK_CONFIGURATION: return set_callback_value_callback_configuration_uint32_t(message, &callback_value_count);
		case FID_GET_COUNT_CALLBACK_CONFIGURATION: return get_callback_value_callback_configuration_uint32_t(message, response, &callback_value_count);
		default: return HANDLE_MESSAGE_RESPONSE_NOT_SUPPORTED;
	}
}

// Each of the generated function-stubs has to be implemented.
// Usually a function here will call a function in a driver.
//
// Example: For IC XXX we write a driver in xxx.c/xxx.h. In the API function in
//          the communication.c we will call xxx_do_something() according to the function call.
//
// If the API function does something simple (e.g. turn an LED on/off) the
// functionality can be implemented directly in the API call.


BootloaderHandleMessageResponse set_gpio_config(const SetGPIOConfig *data) {
	// For each function call we have to check all the incoming parameters.
	// If they are not in a valid range we return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER
	if(data->port > 4) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	if(((data->port == 0) && (data->pin > 15)) ||
	   ((data->port == 1) && (data->pin > 6))  ||
	   ((data->port == 2) && (data->pin > 13)) ||
	   ((data->port == 3) && (data->pin > 0))  ||
	   ((data->port == 4) && (data->pin < 4 || data->pin > 7))) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	if(data->mode > XMC1400_BREAKOUT_GPIO_MODE_OUTPUT_OPEN_DRAIN) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	if(data->input_hysteresis != XMC1400_BREAKOUT_GPIO_INPUT_HYSTERESIS_STANDARD ||
	   data->input_hysteresis != XMC1400_BREAKOUT_GPIO_INPUT_HYSTERESIS_LARGE) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}


	// For the set_gpio_config function call we just use XMC_GPIO_Init directly in the API call.
	XMC_GPIO_CONFIG_t config = {
		.mode = data->mode <= 7 ? data->mode << PORT0_IOCR0_PC0_Pos : (data->mode == 8 ? XMC_GPIO_MODE_OUTPUT_PUSH_PULL : XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN),
		.input_hysteresis = data->input_hysteresis,
		.output_level = data->output_level ? XMC_GPIO_OUTPUT_LEVEL_HIGH : XMC_GPIO_OUTPUT_LEVEL_LOW
	};

	XMC_GPIO_PORT_t *const ports[] = {XMC_GPIO_PORT0, XMC_GPIO_PORT1, XMC_GPIO_PORT2, XMC_GPIO_PORT3, XMC_GPIO_PORT4};
	XMC_GPIO_Init(ports[data->port], data->pin, &config);

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_gpio_input(const GetGPIOInput *data, GetGPIOInput_Response *response) {
	if(data->port > 4) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	if(((data->port == 0) && (data->pin > 15)) ||
	   ((data->port == 1) && (data->pin > 6))  ||
	   ((data->port == 2) && (data->pin > 13)) ||
	   ((data->port == 3) && (data->pin > 0))  ||
	   ((data->port == 4) && (data->pin < 4 || data->pin > 7))) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	// In each API function that returns something, the length field in the header has to be set.
	response->header.length = sizeof(GetGPIOInput_Response);

	// Additionaly all of the response values have to be set.
	XMC_GPIO_PORT_t *const ports[] = {XMC_GPIO_PORT0, XMC_GPIO_PORT1, XMC_GPIO_PORT2, XMC_GPIO_PORT3, XMC_GPIO_PORT4};
	response->value = XMC_GPIO_GetInput(ports[data->port], data->pin);

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_adc_channel_config(const SetADCChannelConfig *data) {
	if(data->channel >= ADC_CHANNEL_NUM) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	adc.enable[data->channel] = data->enable;

	// Initialize the ADC channel if it got enabled. 
	if(data->enable) {
		adc_init_channel(data->channel);
	}

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_adc_channel_config(const GetADCChannelConfig *data, GetADCChannelConfig_Response *response) {
	if(data->channel >= ADC_CHANNEL_NUM) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	response->header.length = sizeof(GetADCChannelConfig_Response);
	response->enable        = adc.enable[data->channel];

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_adc_channel_value(const GetADCChannelValue *data, GetADCChannelValue_Response *response) {
	if(data->channel >= ADC_CHANNEL_NUM) {
		return HANDLE_MESSAGE_RESPONSE_INVALID_PARAMETER;
	}

	response->header.length = sizeof(GetADCChannelValue_Response);
	response->value         = adc.values[data->channel];

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse get_adc_values(const GetADCValues *data, GetADCValues_Response *response) {
	response->header.length = sizeof(GetADCValues_Response);
	for(uint8_t channel = 0; channel < ADC_CHANNEL_NUM; channel++) {
		response->values[channel] = adc.values[channel];
	}

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}

BootloaderHandleMessageResponse set_adc_values_callback_configuration(const SetADCValuesCallbackConfiguration *data) {
	adc.period              = data->period;
	adc.value_has_to_change = data->value_has_to_change;

	return HANDLE_MESSAGE_RESPONSE_EMPTY;
}

BootloaderHandleMessageResponse get_adc_values_callback_configuration(const GetADCValuesCallbackConfiguration *data, GetADCValuesCallbackConfiguration_Response *response) {
	response->header.length       = sizeof(GetADCValuesCallbackConfiguration_Response);
	response->period              = adc.period;
	response->value_has_to_change = adc.value_has_to_change;

	return HANDLE_MESSAGE_RESPONSE_NEW_MESSAGE;
}


// Example for a typical hand-implemented callback. We support a period and the
// "value_has_to_change"-configuration
bool handle_adc_values_callback(void) {
	static bool is_buffered = false;
	static ADCValues_Callback cb;
	static uint16_t last_values[ADC_CHANNEL_NUM] = {0};
	static uint32_t last_time = 0;

	if(!is_buffered) {
		// Check if period is enabled and if period is lapsed
		if(adc.period == 0 || !system_timer_is_time_elapsed_ms(last_time, adc.period)) {
			return false;
		}

		// Check if value_has_to_change is enabled and if value has changed
		bool values_equal = true;
		for(uint8_t channel = 0; channel < ADC_CHANNEL_NUM; channel++) {
			if(last_values[channel] != adc.values[channel]) {
				values_equal = false;
			}
		}

		if(adc.value_has_to_change && values_equal) {
			return false;
		}

		// Create callback
		tfp_make_default_header(&cb.header, bootloader_get_uid(), sizeof(ADCValues_Callback), FID_CALLBACK_ADC_VALUES);
		for(uint8_t channel = 0; channel < ADC_CHANNEL_NUM; channel++) {
			cb.values[channel]   = adc.values[channel];
			last_values[channel] = adc.values[channel];
		}
		last_time = system_timer_get_ms();
	}

	if(bootloader_spitfp_is_send_possible(&bootloader_status.st)) {
		bootloader_spitfp_send_ack_and_message(&bootloader_status, (uint8_t*)&cb, sizeof(ADCValues_Callback));
		is_buffered = false;
		return true;
	} else {
		is_buffered = true;
	}

	return false;
}

// auto-generated callback
bool handle_count_callback(void) {
	return handle_callback_value_callback_uint32_t(&callback_value_count, FID_CALLBACK_COUNT);
}

void communication_tick(void) {
	communication_callback_tick();
}

void communication_init(void) {
	// Simple measurement getter (like get_temperature) that only return one value can be
	// auto-generated. A getter as well as a corresponding callback with all of the
	// configuration possibilities will be generated. We only have to supply a function
	// that returns the actual value, in this case "example_get_count"
	callback_value_init_uint32_t(&callback_value_count, example_get_count);

	communication_callback_init();
}
