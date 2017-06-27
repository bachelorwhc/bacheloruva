import os
import sys

for line in sys.stdin:
    line = line.replace("\n","").replace(" ","")
    n = int(line)
    if n == 0:
        break
    m = (n % 11 == 0)
    if m:
        print(line + " is a multiple of 11.")
    else:
        print(line + " is not a multiple of 11.")

exit()