from pyfirmata import Arduino, INPUT, util, OUTPUT
import time

board = Arduino("COM3")

btn_pin = 5
board.digital[btn_pin].mode = INPUT

led_pin = 9
board.digital[led_pin].mode = OUTPUT


it = util.Iterator(board)
it.start()

board.digital[btn_pin].enable_reporting()

while True:
    
    print("BUTTON STATE")
    btn_state = board.digital[btn_pin].read()
    print("BUTTON STATE =", btn_state)

    if btn_state == True:
        board.digital[led_pin].write(1)
        time.sleep(0.5)

        board.digital[led_pin].write(0)
        time.sleep(0.5)

    

    

    
    
        
