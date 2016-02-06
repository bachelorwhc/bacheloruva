import os
import sys

map = dict()
map['A'] = 2
map['B'] = 2
map['C'] = 2
map['D'] = 3
map['E'] = 3
map['F'] = 3
map['G'] = 4
map['H'] = 4
map['I'] = 4
map['J'] = 5
map['K'] = 5
map['L'] = 5
map['M'] = 6
map['N'] = 6
map['O'] = 6
map['P'] = 7
map['Q'] = 7
map['R'] = 7
map['S'] = 7
map['T'] = 8
map['U'] = 8
map['V'] = 8
map['W'] = 9
map['X'] = 9
map['Y'] = 9
map['Z'] = 9

for line in sys.stdin:
    result = ""
    for c in line:
        if c in map:
            result += str(map[c])
        elif c is not '\n':
            result += c
    print(result)
exit()