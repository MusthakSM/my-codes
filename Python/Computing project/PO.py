from pyfirmata import Arduino, INPUT, util, OUTPUT
import time
from math import ln

board = Arduino("COM3")

therm_pin = 0
board.analog[therm_pin].mode = INPUT

led_pin = 11
board.digital[led_pin].mode = OUTPUT

it = util.Iterator(board)
it.start()

board.analog[therm_pin].enable_reporting()

while True:
    therm_val = therm_pin.read()  # (V0)
    therm_val *= 5  # analog input reading is in between 0 to 1. so, to get actual voltage (V0)

    # R = V0*10000/(5-V0)
    resistance = therm_val*10000/(5-therm_val)

    # T = 1/(1/T0 + 1/B *ln(R/R0))  ; Here R0 : resistance @ room temperature = 1 kilo ohm = 1000 ohm
    # T is in Kelvin
    temp = 1/(1/300.15 + 1/B * ln(resistance/1000) )   

    temp = temp - 273.15  # getting the temperature in celcius
    
    try:
        if temp > 80 :
            board.digital[led_pin].write(1)

    except:
        pass
    
        
