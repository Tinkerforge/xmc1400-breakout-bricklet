import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletXMC1400Breakout;

public class ExampleGPIO {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your XMC1400 Breakout Bricklet
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletXMC1400Breakout xb =
		  new BrickletXMC1400Breakout(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
		for(int i = 0; i < 5; i++) {
			Thread.sleep(1000);
			xb.setGPIOConfig(1, 0, BrickletXMC1400Breakout.GPIO_MODE_OUTPUT_PUSH_PULL, 0, false);
			Thread.sleep(1000);
			xb.setGPIOConfig(1, 0, BrickletXMC1400Breakout.GPIO_MODE_OUTPUT_PUSH_PULL, 0, true);
		}

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
