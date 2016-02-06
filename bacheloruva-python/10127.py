import os
import sys

for line in sys.stdin:
    n = int(line)
    i = 1
    while int('1' * i) % n != 0:
        i += 1
    print(i)
exit()