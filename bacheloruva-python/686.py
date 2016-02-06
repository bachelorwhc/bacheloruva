import os
import sys

MAX = 2**15+1
prime = [True] * MAX
table = []
for index, p in enumerate(prime):
    if index == 0 or index == 1:
        prime[index] = False
        continue
    if not p:
        continue
    else:
        table.append(index)
        i = 2
        while index * i < MAX:
            prime[index * i] = False
            i+=1

for line in sys.stdin:
    n = int(line)
    if n == 0:
        break;
    count = 0
    for p in table:
        if p > n / 2:
            break
        if prime[n - p]:
            count += 1
    print(count)
exit()