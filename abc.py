import numpy as np
import matplotlib.pyplot as plt 

a = np.arange(1, 5, 0.5)
plt.plot(a, a ** 2)
plt.axis([-1, 6, 0, 27])
plt.show()