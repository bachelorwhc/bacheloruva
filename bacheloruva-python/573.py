import os

while True:
    data = input()
    h, u, d, f = data.split(' ')
    
    high = float(h)
    up = float(u)
    down = float(d)
    fall = (float(f) / 100) * up

    if high == 0 and up == 0 and down == 0 and fall == 0:
        break
    current = 0
    day = 0
    s = False
    while True:
        day += 1
        current += up
        if current > high:
            s = True
            break
        current -= down
        if current < 0.0:
            s = False
            break
        up -= fall
        if up <= 0.0:
            up = 0.0
    result = None
    if s:
        result = "success"
    else:
        result = "failure"
    print(result + " on day " + str(day))
exit();