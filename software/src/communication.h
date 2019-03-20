/* xmc1400-breakout-bricklet
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * communication.h: TFP protocol message handling
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

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdint.h>
#include <stdbool.h>

#include "bricklib2/protocols/tfp/tfp.h"
#include "bricklib2/bootloader/bootloader.h"

// Default functions
BootloaderHandleMessageResponse handle_message(const void *data, void *response);
void communication_tick(void);
void communication_init(void);

// Constants
#define XMC1400_BREAKOUT_GPIO_MODE_INPUT_TRISTATE 0
#define XMC1400_BREAKOUT_GPIO_MODE_INPUT_PULL_DOWN 1
#define XMC1400_BREAKOUT_GPIO_MODE_INPUT_PULL_UP 2
#define XMC1400_BREAKOUT_GPIO_MODE_INPUT_SAMPLING 3
#define XMC1400_BREAKOUT_GPIO_MODE_INPUT_INVERTED_TRISTATE 4
#define XMC1400_BREAKOUT_GPIO_MODE_INPUT_INVERTED_PULL_DOWN 5
#define XMC1400_BREAKOUT_GPIO_MODE_INPUT_INVERTED_PULL_UP 6
#define XMC1400_BREAKOUT_GPIO_MODE_INPUT_INVERTED_SAMPLING 7
#define XMC1400_BREAKOUT_GPIO_MODE_OUTPUT_PUSH_PULL 8
#define XMC1400_BREAKOUT_GPIO_MODE_OUTPUT_OPEN_DRAIN 9

#define XMC1400_BREAKOUT_GPIO_INPUT_HYSTERESIS_STANDARD 0
#define XMC1400_BREAKOUT_GPIO_INPUT_HYSTERESIS_LARGE 4

#define XMC1400_BREAKOUT_THRESHOLD_OPTION_OFF 'x'
#define XMC1400_BREAKOUT_THRESHOLD_OPTION_OUTSIDE 'o'
#define XMC1400_BREAKOUT_THRESHOLD_OPTION_INSIDE 'i'
#define XMC1400_BREAKOUT_THRESHOLD_OPTION_SMALLER '<'
#define XMC1400_BREAKOUT_THRESHOLD_OPTION_GREATER '>'

#define XMC1400_BREAKOUT_BOOTLOADER_MODE_BOOTLOADER 0
#define XMC1400_BREAKOUT_BOOTLOADER_MODE_FIRMWARE 1
#define XMC1400_BREAKOUT_BOOTLOADER_MODE_BOOTLOADER_WAIT_FOR_REBOOT 2
#define XMC1400_BREAKOUT_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_REBOOT 3
#define XMC1400_BREAKOUT_BOOTLOADER_MODE_FIRMWARE_WAIT_FOR_ERASE_AND_REBOOT 4

#define XMC1400_BREAKOUT_BOOTLOADER_STATUS_OK 0
#define XMC1400_BREAKOUT_BOOTLOADER_STATUS_INVALID_MODE 1
#define XMC1400_BREAKOUT_BOOTLOADER_STATUS_NO_CHANGE 2
#define XMC1400_BREAKOUT_BOOTLOADER_STATUS_ENTRY_FUNCTION_NOT_PRESENT 3
#define XMC1400_BREAKOUT_BOOTLOADER_STATUS_DEVICE_IDENTIFIER_INCORRECT 4
#define XMC1400_BREAKOUT_BOOTLOADER_STATUS_CRC_MISMATCH 5

#define XMC1400_BREAKOUT_STATUS_LED_CONFIG_OFF 0
#define XMC1400_BREAKOUT_STATUS_LED_CONFIG_ON 1
#define XMC1400_BREAKOUT_STATUS_LED_CONFIG_SHOW_HEARTBEAT 2
#define XMC1400_BREAKOUT_STATUS_LED_CONFIG_SHOW_STATUS 3

// Function and callback IDs and structs
#define FID_SET_GPIO_CONFIG 1
#define FID_GET_GPIO_INPUT 2
#define FID_SET_ADC_CHANNEL_CONFIG 3
#define FID_GET_ADC_CHANNEL_CONFIG 4
#define FID_GET_ADC_CHANNEL_VALUE 5
#define FID_GET_ADC_VALUES 6
#define FID_SET_ADC_VALUES_CALLBACK_CONFIGURATION 7
#define FID_GET_ADC_VALUES_CALLBACK_CONFIGURATION 8
#define FID_GET_COUNT 10
#define FID_SET_COUNT_CALLBACK_CONFIGURATION 11
#define FID_GET_COUNT_CALLBACK_CONFIGURATION 12

#define FID_CALLBACK_ADC_VALUES 9
#define FID_CALLBACK_COUNT 13

typedef struct {
	TFPMessageHeader header;
	uint8_t port;
	uint8_t pin;
	uint8_t mode;
	uint8_t input_hysteresis;
	bool output_level;
} __attribute__((__packed__)) SetGPIOConfig;

typedef struct {
	TFPMessageHeader header;
	uint8_t port;
	uint8_t pin;
} __attribute__((__packed__)) GetGPIOInput;

typedef struct {
	TFPMessageHeader header;
	bool value;
} __attribute__((__packed__)) GetGPIOInput_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
	bool enable;
} __attribute__((__packed__)) SetADCChannelConfig;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
} __attribute__((__packed__)) GetADCChannelConfig;

typedef struct {
	TFPMessageHeader header;
	bool enable;
} __attribute__((__packed__)) GetADCChannelConfig_Response;

typedef struct {
	TFPMessageHeader header;
	uint8_t channel;
} __attribute__((__packed__)) GetADCChannelValue;

typedef struct {
	TFPMessageHeader header;
	uint16_t value;
} __attribute__((__packed__)) GetADCChannelValue_Response;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetADCValues;

typedef struct {
	TFPMessageHeader header;
	uint16_t values[8];
} __attribute__((__packed__)) GetADCValues_Response;

typedef struct {
	TFPMessageHeader header;
	uint32_t period;
	bool value_has_to_change;
} __attribute__((__packed__)) SetADCValuesCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
} __attribute__((__packed__)) GetADCValuesCallbackConfiguration;

typedef struct {
	TFPMessageHeader header;
	uint32_t period;
	bool value_has_to_change;
} __attribute__((__packed__)) GetADCValuesCallbackConfiguration_Response;

typedef struct {
	TFPMessageHeader header;
	uint16_t values[8];
} __attribute__((__packed__)) ADCValues_Callback;


// Function prototypes
BootloaderHandleMessageResponse set_gpio_config(const SetGPIOConfig *data);
BootloaderHandleMessageResponse get_gpio_input(const GetGPIOInput *data, GetGPIOInput_Response *response);
BootloaderHandleMessageResponse set_adc_channel_config(const SetADCChannelConfig *data);
BootloaderHandleMessageResponse get_adc_channel_config(const GetADCChannelConfig *data, GetADCChannelConfig_Response *response);
BootloaderHandleMessageResponse get_adc_channel_value(const GetADCChannelValue *data, GetADCChannelValue_Response *response);
BootloaderHandleMessageResponse get_adc_values(const GetADCValues *data, GetADCValues_Response *response);
BootloaderHandleMessageResponse set_adc_values_callback_configuration(const SetADCValuesCallbackConfiguration *data);
BootloaderHandleMessageResponse get_adc_values_callback_configuration(const GetADCValuesCallbackConfiguration *data, GetADCValuesCallbackConfiguration_Response *response);

// Callbacks
bool handle_adc_values_callback(void);
bool handle_count_callback(void);

#define COMMUNICATION_CALLBACK_TICK_WAIT_MS 1
#define COMMUNICATION_CALLBACK_HANDLER_NUM 2
#define COMMUNICATION_CALLBACK_LIST_INIT \
	handle_adc_values_callback, \
	handle_count_callback, \


#endif
