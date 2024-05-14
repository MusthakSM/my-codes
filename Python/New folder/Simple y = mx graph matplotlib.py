import matplotlib.pyplot as plt
import numpy as np

x = np.arange(100)

y = 0.5 * x

plt.plot(x,y,'*g')
plt.title("y = mx format graph, m = 0.5")
plt.grid()
plt.show()