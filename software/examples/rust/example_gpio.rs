use std::{error::Error, io, thread, time::Duration};
use tinkerforge::{ip_connection::IpConnection, xmc1400_breakout_bricklet::*};

const HOST: &str = "localhost";
const PORT: u16 = 4223;
const UID: &str = "XYZ"; // Change XYZ to the UID of your XMC1400 Breakout Bricklet.

fn main() -> Result<(), Box<dyn Error>> {
    let ipcon = IpConnection::new(); // Create IP connection.
    let xb = Xmc1400BreakoutBricklet::new(UID, &ipcon); // Create device object.

    ipcon.connect((HOST, PORT)).recv()??; // Connect to brickd.
                                          // Don't use device before ipcon is connected.

    // Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
    for _i in 0..5 {
        thread::sleep(Duration::from_millis(1000));
        xb.set_gpio_config(1, 0, XMC1400_BREAKOUT_BRICKLET_GPIO_MODE_OUTPUT_PUSH_PULL, 0, false).recv()?;
        thread::sleep(Duration::from_millis(1000));
        xb.set_gpio_config(1, 0, XMC1400_BREAKOUT_BRICKLET_GPIO_MODE_OUTPUT_PUSH_PULL, 0, true).recv()?;
    }

    println!("Press enter to exit.");
    let mut _input = String::new();
    io::stdin().read_line(&mut _input)?;
    ipcon.disconnect();
    Ok(())
}
