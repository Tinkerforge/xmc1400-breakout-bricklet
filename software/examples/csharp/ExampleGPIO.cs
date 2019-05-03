using System;
using System.Threading;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your XMC1400 Breakout Bricklet

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletXMC1400Breakout xb =
		  new BrickletXMC1400Breakout(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
		for(int i = 0; i < 5; i++)
		{
			Thread.Sleep(1000);
			xb.SetGPIOConfig(1, 0, BrickletXMC1400Breakout.GPIO_MODE_OUTPUT_PUSH_PULL, 0, false);
			Thread.Sleep(1000);
			xb.SetGPIOConfig(1, 0, BrickletXMC1400Breakout.GPIO_MODE_OUTPUT_PUSH_PULL, 0, true);
		}

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
