#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your XMC1400 Breakout Bricklet

# Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
for i in 0 1 2 3 4; do
	sleep 1
	tinkerforge call xmc1400-breakout-bricklet $uid set-gpio-config 1 0 gpio-mode-output-push-pull gpio-input-hysteresis-standard false
	sleep 1
	tinkerforge call xmc1400-breakout-bricklet $uid set-gpio-config 1 0 gpio-mode-output-push-pull gpio-input-hysteresis-standard true
done
