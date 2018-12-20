import numpy as np 

TOL = 1e-6
hmax = 0.5
hmin = 0.05

def y(t):
    return t / (1 + np.log(t))

def f(t, w):
    return w / t - (w / t) ** 2

t, w, h = 1.0, 1.0, hmax
print("t = %.7f, w = %.7f, h = %.7f, y(t) = %.7f" %(t, w, h, y(t)))
while(1):
    k1 = h * f(t, w)
    k2 = h * f(t + h / 6, w + k1 / 6)
    k3 = h * f(t + h * 4/15, w + k1 * 4/75 + k2 * 16/75)
    k4 = h * f(t + h * 2/3, w + k1 * 5/6 - k2 * 8/3 + k3 * 5/2)
    k5 = h * f(t + h * 5/6, w - k1 * 165/64 + k2 * 55/6 - k3 * 425/64 + k4 * 85/96)
    k6 = h * f(t + h, w + k1 * 12/5 - k2 * 8 + k3 * 4015/612 - k4 * 11/36 + k5 * 88/255)
    k7 = h * f(t + h / 15, w - k1 * 8263/15000 + k2 * 124/75 - k3 * 643/680 - k4 * 81/250 + k5 * 2484/10625)
    k8 = h * f(t + h, w + k1 * 3501/1720 - k2 * 300/43 + k3 * 297275/52632 - k4 * 319/2322 + k5 * 24068/84065 + k7 * 3850/26703)
    tmp = w + k1 * 13/160 + k3 * 2375/5984 + k4 * 5/16 + k5 * 12/85 + k6 * 3/44
    w_ = w + k1 * 3/40 + k3 * 875/2244 + k4 * 23/72 + k5 * 264/1955 + k7 * 125/11592 + k8 * 43/616
    R = np.fabs(tmp - w_) / h
    if R <= TOL:
        w = tmp
        t = t + h
        print("t = %.7f, w = %.7f, h = %.7f, y(t) = %.7f" %(t, w, h, y(t)))
    deta = 0.84 * ((TOL / R) ** 0.25)
    if deta <= 0.1:
        h = 0.1 * h
    elif deta >= 4:
        h = 4 * h
    else:
        h = deta * h
    if h >= hmax:
        h = hmax
    if t + h >= 4:
        h = 4 - t
        if np.fabs(h) < TOL:
            break
    elif h < hmin:
        print("minimun h exceeded")
        break