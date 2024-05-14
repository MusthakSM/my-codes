# Computing lab 08
# E/19/247

import matplotlib.pyplot as plt
import numpy as np


C = 0.0001  # 100 micro Farrate
R = 2000   # 2 kilo ohm
R1 = 1000  # 1 kilo ohm
V = 5  # 5 volts

t = np.linspace(0,1,200)            

Q = C*V*(1-np.e**(-t/(R*C)))  # Q refers to Q(t) for 2 kilo ohm

I = (V/R)*np.e**(-t/(R*C))  # I refers to I(t) for 2 kilo ohm

Q1 = C*V*(1-np.e**(-t/(R1*C)))  # Q1 refers to Q(t) for 1 kilo ohm

I1 = (V/R1)*np.e**(-t/(R1*C))  # I1 refers to I(t) for 1 kilo ohm

plt.plot(t,Q,"g")       # Q(t) graph for 2 kilo ohm
plt.plot(t,I,'--g')     # I(t) graph for 2 kilo ohm

plt.plot(t,Q1,"r")    # Q(t) graph for 1 kilo ohm
plt.plot(t,I1,'--r')   # I(t) graph for 1 kilo ohm

plt.title("Variation of Q(t) and I(t) with t(s)", fontsize = 18 )

plt.xlabel("time/t(s)", fontsize = 14)

plt.ylabel("Q(t) and I(t)", fontsize = 14)

plt.legend(["Q(t){2kohm}","I(t){2kohm}","Q(t){1kohm}","I(t){1kohm}"], fontsize = 10 )

plt.grid()
plt.show()
