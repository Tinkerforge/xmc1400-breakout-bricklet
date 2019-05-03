var Tinkerforge = require('tinkerforge');

var HOST = 'localhost';
var PORT = 4223;
var UID = 'XYZ'; // Change XYZ to the UID of your XMC1400 Breakout Bricklet

var ipcon = new Tinkerforge.IPConnection(); // Create IP connection
var xb = new Tinkerforge.BrickletXMC1400Breakout(UID, ipcon); // Create device object

ipcon.connect(HOST, PORT,
    function (error) {
        console.log('Error: ' + error);
    }
); // Connect to brickd
// Don't use device before ipcon is connected

ipcon.on(Tinkerforge.IPConnection.CALLBACK_CONNECTED,
    function (connectReason) {
        // Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
        for(var i = 0; i < 5; ++i) {
            setTimeout(function () {
                xb.setGPIOConfig(1, 0,
                                 Tinkerforge.BrickletXMC1400Breakout.GPIO_MODE_OUTPUT_PUSH_PULL,
                                 0, false);
            }, 2000 * i + 1000);
            setTimeout(function () {
                xb.setGPIOConfig(1, 0,
                                 Tinkerforge.BrickletXMC1400Breakout.GPIO_MODE_OUTPUT_PUSH_PULL,
                                 0, true);
            }, 2000 * i + 2000);
        }
    }
);

console.log('Press key to exit');
process.stdin.on('data',
    function (data) {
        ipcon.disconnect();
        process.exit(0);
    }
);
