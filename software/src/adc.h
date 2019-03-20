/* xmc1400-breakout-bricklet
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * adc.h: Example for ADC configuration and usage
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

#ifndef ADC_H
#define ADC_H

#include <stdint.h>
#include <stdbool.h>

#define ADC_CHANNEL_NUM 8

// Usually each driver will have a struct that contains all of the working memory
// of the driver. The communication.c may directly use something from the struct.

// In this case, the get_adc_values API function can directly use the data stored
// in "adc.values[]".
typedef struct {
    bool enable[ADC_CHANNEL_NUM];
    uint16_t values[ADC_CHANNEL_NUM];

    uint32_t sum[ADC_CHANNEL_NUM];
    uint32_t count[ADC_CHANNEL_NUM];

    uint32_t last_average_time;

	uint32_t period;
	bool value_has_to_change;
} ADC;

extern ADC adc;

void adc_tick(void);
void adc_init(void);
void adc_init_channel(const uint8_t channel);

#endif