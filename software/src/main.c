/* xmc1400-breakout-bricklet
 * Copyright (C) 2017-2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * main.c: Initialization for XMC1400 Breakout Bricklet
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

#include <stdio.h>
#include <stdbool.h>

#include "configs/config.h"

#include "bricklib2/bootloader/bootloader.h"
#include "bricklib2/hal/system_timer/system_timer.h"
#include "bricklib2/logging/logging.h"
#include "communication.h"

#include "adc.h"
#include "example.h"

// The main function of a Bricklet is usually just a bunch of *_init() calls
// and while-true loop with ticks.

// Usually there is one init and tick function per driver. Example: For a
// temperature sensor IC XXX there would usually be a xxx.c and xxx.h that
// implement a xxx_init and xxx_tick function. Additionally there will be
// a XXX struct that contains all the relevant values that may be used
// in the communication.c

// A tick can not do any busy-waiting or similar, it is supposed to return as fast
// as possible. 
// We do have cooperative, non-preemtive tasks. In these you can use a never-returning
// while-true loop. The example_tick uses such a coop-task.
int main(void) {
	logging_init();
	logd("Start XMC1400 Breakout Bricklet\n\r");

	communication_init();
	adc_init();
	example_init();

	while(true) {
		bootloader_tick();
		communication_tick();
		adc_tick();
		example_tick();
	}
}
