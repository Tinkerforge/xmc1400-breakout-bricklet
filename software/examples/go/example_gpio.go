package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
	"github.com/Tinkerforge/go-api-bindings/xmc1400_breakout_bricklet"
	"time"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your XMC1400 Breakout Bricklet.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	xb, _ := xmc1400_breakout_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	// Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
	for i := 0; i < 5; i++ {
		time.Sleep(1000 * time.Millisecond)
		xb.SetGPIOConfig(1, 0, xmc1400_breakout_bricklet.GPIOModeOutputPushPull, 0, false)
		time.Sleep(1000 * time.Millisecond)
		xb.SetGPIOConfig(1, 0, xmc1400_breakout_bricklet.GPIOModeOutputPushPull, 0, true)
	}

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
