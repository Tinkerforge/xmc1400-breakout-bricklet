/* xmc1400-breakout-bricklet
 * Copyright (C) 2019 Olaf Lüke <olaf@tinkerforge.com>
 *
 * example.c: Example for a coop task
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

#include "example.h"

#include "configs/config_example.h"

#include "bricklib2/logging/logging.h"
#include "bricklib2/os/coop_task.h"

// Example of a simple driver that uses a coop task.

// Coop tasks a cooperative non-preemtive tasks. In such a task you
// can use coop_task_yield() to yield back to other ticks or you can
// also use coop_task_sleep_ms(time). This will sleep for the specified
// time in ms in yield to other ticks in this time.
// Several coop tasks can be used in parallel.

Example example;
CoopTask example_task;

void example_task_tick(void) {
    // In the coop task we can now have a while-true loop.
    // Note: In the wile-true loop there has to be a call to either
    // coop_task_yield or coop_task_sleep_ms.
    while(true) {
        // Here we just sleep for 1s and increase a counter
        coop_task_sleep_ms(1000);
        example.count++;

        // The logging functions (logd/w/e) print (uart) to a pin that is specified in the config.h.
        // You can use any pin that supports output, the logging is implemented with bit-banging.

        // if your prototype does not have a specific debug pad, you can for example solder a wire
        // to the status LED and use it for debugging.
        logd("Count: %d\n\r", example.count);
    }
}

void example_tick(void) {
    // The normal tick will now call the coop task.
    coop_task_tick(&example_task);
}

void example_init(void) {
    memset(&example, 0, sizeof(Example));

    // A coop task needs to be initialized with coop_task_init
    coop_task_init(&example_task, example_task_tick);
}

// Return the current count of the example counter.
// This is used to demonstrate the getter/callback generation support in
// the generator.
uint32_t example_get_count(void) {
    return example.count;
}