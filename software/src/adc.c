/* xmc1400-breakout-bricklet
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * adc.c: Example for ADC configuration and usage
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

#include "adc.h"

#include "configs/config_adc.h"
#include "bricklib2/hal/system_timer/system_timer.h"
#include "xmc_vadc.h"

// Here we demonstrate a simple driver for the ADC.
// The user can enable one of 8 channels and a 12-bit value 
// will calculated every 10ms by averaging.

ADC adc;

void adc_tick(void) {
	// Get ADC values and sum them up as soon as they are available
	for(uint8_t channel = 0; channel < ADC_CHANNEL_NUM; channel++) {
		if(adc.enable[channel]) {
			uint32_t result = XMC_VADC_GROUP_GetDetailedResult(VADC_G0, channel);
			if(result & (1 << 31)) { // Valid result available
				adc.sum[channel] += (result & 0xFFFF);
				adc.count[channel]++;
			}
		}
	}

	// Every 10ms use ADC value sums and calculate average
	if(system_timer_is_time_elapsed_ms(adc.last_average_time, 10)) {
		adc.last_average_time = system_timer_get_ms();
		for(uint8_t channel = 0; channel < ADC_CHANNEL_NUM; channel++) {
			if(adc.enable[channel] && (adc.count[channel] > 0)) {
				adc.values[channel] = adc.sum[channel] / (adc.count[channel]*4); // *4 because of 4x accumulation mode
			} else {
				adc.values[channel] = 0;
			}

			adc.sum[channel] = 0;
			adc.count[channel] = 0;
		}

	}
}

// Initialize the specified channel.
// Here we assume that the user configured the pin to input before the ADC channel was enabled.
void adc_init_channel(const uint8_t channel) {
	const uint8_t result_reg = channel; // To keep it simple we just use the channel number as result reg.

	XMC_VADC_CHANNEL_CONFIG_t  channel_config = {
		.input_class                =  XMC_VADC_CHANNEL_CONV_GLOBAL_CLASS0,    // Global ICLASS 0 selected
		.lower_boundary_select 	    =  XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
		.upper_boundary_select 	    =  XMC_VADC_CHANNEL_BOUNDARY_GROUP_BOUND0,
		.event_gen_criteria         =  XMC_VADC_CHANNEL_EVGEN_NEVER,           // Channel Event disabled
		.sync_conversion  		    =  0,                                      // Sync feature disabled
		.alternate_reference        =  XMC_VADC_CHANNEL_REF_INTREF,            // Internal reference selected
		.result_reg_number          =  result_reg,                             // GxRES[x] selected
		.use_global_result          =  0, 				                       // Use Group result register
		.result_alignment           =  XMC_VADC_RESULT_ALIGN_RIGHT,            // Result alignment - Right Aligned
		.broken_wire_detect_channel =  XMC_VADC_CHANNEL_BWDCH_VAGND,           // No Broken wire mode select
		.broken_wire_detect		    =  0,    		                           // No Broken wire detection
		.bfl                        =  0,                                      // No Boundary flag
		.channel_priority           =  0,                   		           // Lowest Priority 0 selected
		.alias_channel              =  -1                                      // Channel is not aliased
	};

	XMC_VADC_RESULT_CONFIG_t channel_result_config = {
		.data_reduction_control = 0b11,                         // Accumulate 4 result values
		.post_processing_mode   = XMC_VADC_DMM_REDUCTION_MODE,  // Use reduction mode
		.wait_for_read_mode  	= 1,                            // Enabled
		.part_of_fifo       	= 0,                            // No FIFO
		.event_gen_enable   	= 0                             // Disable Result event
	};

	// Initialize for configured channels
	XMC_VADC_GROUP_ChannelInit(VADC_G0, channel, &channel_config);

	// Initialize for configured result registers
	XMC_VADC_GROUP_ResultInit(VADC_G0, result_reg, &channel_result_config);

	XMC_VADC_GLOBAL_BackgroundAddChannelToSequence(VADC, 0, channel);
	XMC_VADC_GLOBAL_BackgroundTriggerConversion(VADC);
}

// Initialize the non-channel-specfic ADC hardware unit.
void adc_init(void) {
	memset(&adc, 0, sizeof(ADC));

	// This structure contains the Global related Configuration.
	const XMC_VADC_GLOBAL_CONFIG_t adc_global_config = {
		.boundary0 = 0, // Lower boundary value for Normal comparison mode
		.boundary1 = 0, // Upper boundary value for Normal comparison mode

		.class0 = {
			.sample_time_std_conv     = 31,                      // The Sample time is (2*tadci)
			.conversion_mode_standard = XMC_VADC_CONVMODE_12BIT, // 12bit conversion Selected
		},
		.class1 = {
			.sample_time_std_conv     = 31,                      // The Sample time is (2*tadci)
		},

		.data_reduction_control       = 0b11, // Accumulate 4 result values
		.wait_for_read_mode           = 0, // GLOBRES Register will not be overwritten until the previous value is read
		.event_gen_enable             = 0, // Result Event from GLOBRES is disabled
		.disable_sleep_mode_control   = 0  // Sleep mode is enabled
	};

	// Global iclass0 configuration
	const XMC_VADC_GLOBAL_CLASS_t adc_global_iclass_config = {
		.conversion_mode_standard = XMC_VADC_CONVMODE_12BIT,
		.sample_time_std_conv	  = 31,
	};

	// LLD Background Scan Init Structure
	const XMC_VADC_BACKGROUND_CONFIG_t adc_background_config = {
		.conv_start_mode   = XMC_VADC_STARTMODE_CIR,       // Conversion start mode selected as cancel inject repeat
		.req_src_priority  = XMC_VADC_GROUP_RS_PRIORITY_1, // Priority of the Background request source in the VADC module
		.trigger_signal    = XMC_VADC_REQ_TR_A,            // If Trigger needed then this denotes the Trigger signal
		.trigger_edge      = XMC_VADC_TRIGGER_EDGE_NONE,   // If Trigger needed then this denotes Trigger edge selected
		.gate_signal       = XMC_VADC_REQ_GT_A,			   // If Gating needed then this denotes the Gating signal
		.timer_mode        = 0,							   // Timer Mode Disabled
		.external_trigger  = 0,                            // Trigger is Disabled
		.req_src_interrupt = 0,                            // Background Request source interrupt Enabled 
		.enable_auto_scan  = 1,
		.load_mode         = XMC_VADC_SCAN_LOAD_OVERWRITE
	};

	const XMC_VADC_GROUP_CONFIG_t group_init_handle = {
		.emux_config = {
			.stce_usage                  = 0, 					           // Use STCE when the setting changes
			.emux_mode                   = XMC_VADC_GROUP_EMUXMODE_SWCTRL, // Mode for Emux conversion
			.emux_coding                 = XMC_VADC_GROUP_EMUXCODE_BINARY, // Channel progression - binary format
			.starting_external_channel   = 0,                              // Channel starts at 0 for EMUX
			.connected_channel           = 0                               // Channel connected to EMUX
		},
		.class0 = {
			.sample_time_std_conv        = 31,                             // The Sample time is (2*tadci)
			.conversion_mode_standard    = XMC_VADC_CONVMODE_12BIT,        // 12bit conversion Selected
			.sampling_phase_emux_channel = 0,                              // The Sample time is (2*tadci)
			.conversion_mode_emux        = XMC_VADC_CONVMODE_12BIT         // 12bit conversion Selected
		},
		.class1 = {
			.sample_time_std_conv        = 31,                             // The Sample time is (2*tadci)
			.conversion_mode_standard    = XMC_VADC_CONVMODE_12BIT,        // 12bit conversion Selected
			.sampling_phase_emux_channel = 0,                              // The Sample time is (2*tadci)
			.conversion_mode_emux        = XMC_VADC_CONVMODE_12BIT         // 12bit conversion Selected
		},

		.boundary0                       = 0,                              // Lower boundary value for Normal comparison mode
		.boundary1	                     = 0,                              // Upper boundary value for Normal comparison mode
		.arbitration_round_length        = 0,                              // 4 arbitration slots per round selected (tarb = 4*tadcd) */
		.arbiter_mode                    = XMC_VADC_GROUP_ARBMODE_ALWAYS,  // Determines when the arbiter should run.
	};

	XMC_VADC_GLOBAL_Init(VADC, &adc_global_config);

	XMC_VADC_GROUP_Init(VADC_G0, &group_init_handle);
	XMC_VADC_GROUP_SetPowerMode(VADC_G0, XMC_VADC_GROUP_POWERMODE_NORMAL);
	XMC_VADC_GLOBAL_SHS_EnableAcceleratedMode(SHS0, XMC_VADC_GROUP_INDEX_0);
	XMC_VADC_GLOBAL_SHS_SetClockDivider(SHS0, 0);
	XMC_VADC_GLOBAL_SHS_SetAnalogReference(SHS0, XMC_VADC_GLOBAL_SHS_AREF_EXTERNAL_VDD_UPPER_RANGE);

	XMC_VADC_GLOBAL_StartupCalibration(VADC);

	// Initialize the Global Conversion class 0
	XMC_VADC_GLOBAL_InputClassInit(VADC, adc_global_iclass_config, XMC_VADC_GROUP_CONV_STD, 0);

	// Initialize the Background Scan hardware
	XMC_VADC_GLOBAL_BackgroundInit(VADC, &adc_background_config);
}
