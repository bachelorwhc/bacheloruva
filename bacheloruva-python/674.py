import os
import sys

coin = [1, 5, 10, 25, 50]
change = [0] * 30001
change[0] = 1

for c in coin:
    for i in range(c, 30001):
        change[i] += change[i - c]

for line in sys.stdin:
    n = int(line)
    if change[n] == 1:
        print("There is only " + str(change[n]) + " way to produce " + str(n) + " cents change.")
    else:
        print("There are " + str(change[n]) + " ways to produce " + str(n) + " cents change.")
exit()