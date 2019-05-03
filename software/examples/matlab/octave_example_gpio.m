function octave_example_gpio()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your XMC1400 Breakout Bricklet

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    xb = javaObject("com.tinkerforge.BrickletXMC1400Breakout", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
    for i = 0:4
        pause(1);
        xb.setGPIOConfig(1, 0, xb.GPIO_MODE_OUTPUT_PUSH_PULL, 0, false);
        pause(1);
        xb.setGPIOConfig(1, 0, xb.GPIO_MODE_OUTPUT_PUSH_PULL, 0, true);
    end

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
