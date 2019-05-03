#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_xmc1400_breakout'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your XMC1400 Breakout Bricklet

ipcon = IPConnection.new # Create IP connection
xb = BrickletXMC1400Breakout.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
for _ in 0..4
  sleep 1
  xb.set_gpio_config 1, 0, BrickletXMC1400Breakout::GPIO_MODE_OUTPUT_PUSH_PULL, 0, false
  sleep 1
  xb.set_gpio_config 1, 0, BrickletXMC1400Breakout::GPIO_MODE_OUTPUT_PUSH_PULL, 0, true
end

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
