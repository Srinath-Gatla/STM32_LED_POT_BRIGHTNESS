#include "mbed.h"

// PWM output pin for LED brightness control
PwmOut led(D2);

// Analog input pin for potentiometer
AnalogIn pot(A0);  // Connect middle pin of potentiometer to A0

// Serial interface (for debugging or display)
UnbufferedSerial pc(USBTX, USBRX, 9600);   // TX=PA_2, RX=PA_3 (USB)

int main()
{
    const char msg[] = "Potentiometer-based LED brightness control\r\n";
    pc.write(msg, sizeof(msg) - 1);

    // Set PWM period (e.g., 1 kHz frequency)
    led.period(0.001f);

    while (1)
    {
        // Read analog value (0.0 to 1.0)
        float potValue = pot.read();

        // Write the same value to LED (brightness control)
        led.write(potValue);

        // Convert to percentage for display
        int brightness = (int)(potValue * 100);

        // Display brightness value via serial
        char msg1[40];
        int n = sprintf(msg1, "Brightness: %d%%\r\n", brightness);
        pc.write(msg1, n);

        // Small delay for stable reading
        ThisThread::sleep_for(200ms);
    }
}
