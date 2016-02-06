import sys

def is_increase(pancakes):
    pp = pancakes[0]
    for ip in range(1, len(pancakes)):
        if pp > pancakes[ip]:
            return False
        pp = pancakes[ip]
    return True

def last_common(src, comp):
    for index, op in enumerate(pancakes):
            for gp in goal:
                if gp == op:
                    return index
    return 

for line in sys.stdin:
    steps = []
    pancakes = line.replace("\n", "").split(' ')
    for index, p in enumerate(pancakes):
        pancakes[index] = int(p)
    goal = sorted(pancakes)
    size = len(pancakes)
    count = 1
    max_r = goal[-1]
    max_index = pancakes.index(max_r)
    result = ""
    for p in pancakes:
        result += str(p) + " "
    print(result)
    while(pancakes != goal):
        if max_index > 0:
            steps.append(size - max_index)
        rp = reversed(pancakes[0:max_index + 1])
        for index, op in enumerate(rp):
            pancakes[index] = op
        steps.append(count)
        pancakes.reverse()
        count += 1
        goal.pop()
        pancakes.pop()
        max_r = goal[-1]
        max_index = pancakes.index(max_r)
    result = ""
    for s in steps:
        result += str(s) + " "
    print(result + "0")
exit()