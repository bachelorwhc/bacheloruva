import os
import sys

i = 0
n1 = 0
n2 = 0
for line in sys.stdin:
    if (i % 2) == 0:
        n1 = int(line)
    else:
        n2 = int(line)
        print(n1 * n2)
    i += 1
exit()