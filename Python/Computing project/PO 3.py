from pyfirmata import Arduino, INPUT, util, OUTPUT
import time

board = Arduino("COM3")

btn_pin1 = 3
btn_pin2 = 7

board.digital[btn_pin1].mode = INPUT
board.digital[btn_pin2].mode = INPUT

led_pin = 11
board.digital[led_pin].mode = OUTPUT

it = util.Iterator(board)
it.start()

board.digital[btn_pin1].enable_reporting()
board.digital[btn_pin2].enable_reporting()

knock_patrn = ""
while True:
    btn1_val = board.digital[btn_pin1].read()
    btn2_val = board.digital[btn_pin2].read()
  
    print(btn1_val,btn2_val)