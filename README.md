# STM32_LED_POT_BRIGHTNESS

The potentiometer acts as a voltage divider, giving a value between 0 V and 3.3 V to the analog pin.

pot.read() converts this into a float between 0.0 and 1.0.

This value is written directly to the PWM output using led.write(), controlling brightness.

The serial monitor displays the brightness percentage in real time.
