from pyfirmata import Arduino, PWM
import time

board = Arduino("COM6")

led_pin1 = 3  # Use a pin that supports digital output
led_pin2 = 5

# Set the mode of the digital pin to OUTPUT
board.digital[led_pin1].mode = PWM
board.digital[led_pin2].mode = PWM

count = 0
while True:
    if (count == 15): break
    
    print("Fade in")
    
    for i in range(10):
        board.digital[led_pin1].write(i/10.00)
        board.digital[led_pin2].write(1 - i/10.00)
        time.sleep(0.3)
        
    print("Fade out")
    
    for i in range(10):
        board.digital[led_pin2].write(i/10.00)
        board.digital[led_pin1].write(1 - i/10.00)
        time.sleep(0.3)
    count += 1
