import os
import sys

for line in sys.stdin:
    n = line
    n = int(n)
    if n == 0:
        print("The Fibonacci number for 0 is 0")
        continue
    elif n == 1:
        print("The Fibonacci number for 1 is 1")
        continue
    f = 0
    n1 = 1
    n2 = 0
    for i in range(0, n):
        n2 = n1
        n1 = f
        f = n1 + n2
    print("The Fibonacci number for " + str(n) +" is " + str(f) )

exit()