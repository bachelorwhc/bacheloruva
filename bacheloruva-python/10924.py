import os
import sys
import math

MAX = (2 ** 11) * 10 + 1
prime = [True] * MAX
for index, p in enumerate(prime):
    if index == 0 or index == 1:
        prime[index] = True
        continue
    if not p:
        continue
    else:
        i = 2
        while index * i < MAX:
            prime[index * i] = False
            i+=1

for line in sys.stdin:
    n = 0
    for c in line.replace('\n', ''):
        if ord(c) <= ord('z') and ord(c) >= ord('a'):
            n += ord(c) - ord('a') + 1
        else:
            n += ord(c) - ord('A') + 27

    if prime[n]:
        print("It is a prime word.")
    else:
        print("It is not a prime word.")
exit()