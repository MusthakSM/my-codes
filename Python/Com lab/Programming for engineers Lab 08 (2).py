import matplotlib.pyplot as plt
import numpy as np


C = 0.0001  #  100 micro Farrate
R = 1000   #  1 kilo oam
V = 5      #  5 volts

t = np.linspace(0,1,20)
 

Q = C*V*(1-np.e**(-t/(R*C)))  # Q refers to Q(t)

I = (V/R)*np.e**(-t/(R*C))  # I refers to I(t)

plt.plot(t,Q,"-*r")
plt.plot(t,I,'--y')
plt.title("Variation of Q(t) and I(t) with t(s)", fontsize = 18 )
plt.xlabel("time/t(s)")
plt.ylabel("Q(t) and I(t)")
plt.legend(["Q(t)","I(t)"], fontsize = 10 )
plt.grid()
plt.show()
