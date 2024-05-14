

# Exercise 3
# Lab 5
# 16/09/2021

import matplotlib.pyplot as plt
import numpy as np

np.seterr(divide='ignore', invalid='ignore')

x = np.arange(-2 * np.pi, +2 * np.pi, np.pi/24)
y = np.cos(x)/ (np.sin(x)+1)

plt.plot(x,y,'g')
plt.title("cos(x)/(1+sin(x)) in range[-2pi,+2pi]")
plt.xlabel("angle(radians)")
plt.ylabel("cos(x)/(1+sin(x))")
plt.grid()
plt.show()
