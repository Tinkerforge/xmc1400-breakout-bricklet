#!/usr/bin/perl

use strict;
use Tinkerforge::IPConnection;
use Tinkerforge::BrickletXMC1400Breakout;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your XMC1400 Breakout Bricklet

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $xb = Tinkerforge::BrickletXMC1400Breakout->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
for (my $i = 0; $i < 5; $i++)
{
    sleep(1);
    $xb->set_gpio_config(1, 0, $xb->GPIO_MODE_OUTPUT_PUSH_PULL, 0, 0);
    sleep(1);
    $xb->set_gpio_config(1, 0, $xb->GPIO_MODE_OUTPUT_PUSH_PULL, 0, 1);
}

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
