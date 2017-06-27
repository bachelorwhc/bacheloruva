import os
import sys

for line in sys.stdin:
    line = line.replace('\n', '')
    n = int(line)
    if n == 0:
        break
    d = 0
    count = 0
    is9 = True
    while d != 9:
        d = 0
        for c in line:
            d += int(c)
        line = str(d)
        count += 1
        d = int(line)
        if len(line) == 1 and line != '9':
            is9 = False
            break
    if is9:
        print(str(n) + " is a multiple of 9 and has 9-degree " + str(count) + ".")
    else:
        print(str(n) + " is not a multiple of 9.")
exit()