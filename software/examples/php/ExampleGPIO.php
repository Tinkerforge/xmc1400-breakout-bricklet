<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletXMC1400Breakout.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletXMC1400Breakout;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your XMC1400 Breakout Bricklet

$ipcon = new IPConnection(); // Create IP connection
$xb = new BrickletXMC1400Breakout(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
for($i = 0; $i < 5; $i++) {
    sleep(1);
    $xb->setGPIOConfig(1, 0, BrickletXMC1400Breakout::GPIO_MODE_OUTPUT_PUSH_PULL, 0,
                       FALSE);
    sleep(1);
    $xb->setGPIOConfig(1, 0, BrickletXMC1400Breakout::GPIO_MODE_OUTPUT_PUSH_PULL, 0,
                       TRUE);
}

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
