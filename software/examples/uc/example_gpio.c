#include "bindings/hal_common.h"
#include "bindings/bricklet_xmc1400_breakout.h"

#define UID "XYZ" // Change XYZ to the UID of your XMC1400 Breakout Bricklet

void check(int rc, const char* msg);

TF_XMC1400Breakout xb;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_xmc1400_breakout_create(&xb, UID, hal), "create device object");

	// Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
	int i;
	for(i = 0; i < 5; ++i) {
		tf_hal_sleep_us(hal, 1000 * 1000);
		check(tf_xmc1400_breakout_set_gpio_config(&xb, 1, 0,
		                                          TF_XMC1400_BREAKOUT_GPIO_MODE_OUTPUT_PUSH_PULL,
		                                          0, false), "call set_gpio_config");
		tf_hal_sleep_us(hal, 1000 * 1000);
		check(tf_xmc1400_breakout_set_gpio_config(&xb, 1, 0,
		                                          TF_XMC1400_BREAKOUT_GPIO_MODE_OUTPUT_PUSH_PULL,
		                                          0, true), "call set_gpio_config");
	}
}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
