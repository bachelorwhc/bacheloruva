import os
import sys

map = dict()
tri = 0
for i in range(1, 50000 + 1):
    tri += i ** 3
    map[i] = tri

for line in sys.stdin:
    n = int(line)
    print(map[n])
exit()