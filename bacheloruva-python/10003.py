import os
import math
while True:
    wood_len = int(input().replace("\n", ""))
    if wood_len == 0:
        break
    number_of_marks = int(input().replace("\n", ""))
    marks = [0]
    for mark in input().replace("\n", "").split(' '):
        marks.append(int(mark))
    marks.append(wood_len)
    score = []
    number_of_marks = len(marks)
    for r in range(number_of_marks):
        row = [0] * (number_of_marks)
        score.append(row)
    for start in range(2, number_of_marks):
        for x in range(start, number_of_marks):
            score[x - start][x] = math.inf
            diff = marks[x] - marks[x - start]
            prev = math.inf
            for i in range(1, start):
                prev = min([(score[x - start][x - start + i] + score[x - start + i][x]), prev])
            score[x - start][x] = min([prev + diff, score[x - start][x]])
    print("The minimum cutting is " + str(score[0][len(marks) - 1]) + ".")
exit()