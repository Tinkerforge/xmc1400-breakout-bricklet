Imports System
Imports System.Threading
Imports Tinkerforge

Module ExampleGPIO
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your XMC1400 Breakout Bricklet

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim xb As New BrickletXMC1400Breakout(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Set Port 1, Pin 0 alternating high/low for 5 times with 1s delay
        Dim i As Integer
        For i = 0 To 4
            Thread.Sleep(1000)
            xb.SetGPIOConfig(1, 0, BrickletXMC1400Breakout.GPIO_MODE_OUTPUT_PUSH_PULL, _
                             0, False)
            Thread.Sleep(1000)
            xb.SetGPIOConfig(1, 0, BrickletXMC1400Breakout.GPIO_MODE_OUTPUT_PUSH_PULL, _
                             0, True)
        Next i

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
