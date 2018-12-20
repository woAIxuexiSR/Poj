import numpy as np 

TOL = 1e-6
iterations = 10000
w = 1.5

def a(i, j):
    if j == i:
        return 2 * i
    elif j == i + 2 or j == i - 2:
        return 0.5 * i
    elif j == i + 4 or j == i - 4:
        return 0.25 * i
    else:
        return 0
    
def norm(x, y):
    m = 0.0
    for i in range(80):
        if m < np.fabs(x[i] - y[i]):
            m = np.fabs(x[i] - y[i])
    return m

x = np.zeros((80))
pre = np.zeros((80))
k = 1
while(k <= iterations):
    for i in range(1, 81):
        sum1, sum2 = 0.0, 0.0
        for j in range(1, i):
            sum1 += a(i, j) * x[j - 1]
        for j in range(i + 1, 81):
            sum2 += a(i, j) * pre[j - 1]
        x[i - 1] = (1 - w) * pre[i - 1] + w * (np.pi - sum1 - sum2) / a(i, i)
    if norm(x, pre) < TOL:
        print(x)
        break
    k = k + 1
    pre = x   

