// This example is not self-contained.
// It requires usage of the example driver specific to your platform.
// See the HAL documentation.

#include "src/bindings/hal_common.h"
#include "src/bindings/bricklet_xmc1400_breakout.h"

void check(int rc, const char *msg);
void example_setup(TF_HAL *hal);
void example_loop(TF_HAL *hal);

static TF_XMC1400Breakout xb;

void example_setup(TF_HAL *hal) {
	// Create device object
	check(tf_xmc1400_breakout_create(&xb, NULL, hal), "create device object");

	// Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
	int i;
	for (i = 0; i < 5; ++i) {
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

void example_loop(TF_HAL *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
