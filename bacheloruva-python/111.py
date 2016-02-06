import os
import sys
n_of_q = input()
n_of_q = int(n_of_q)
answer_no = input().replace("\n", "").split(' ')

def get_sequence(ans_no, n):
    ret = [0] * n
    for i in range(n):
        ret[int(ans_no[i]) - 1] = i
    return ret

answer = get_sequence(answer_no, n_of_q)

for line in sys.stdin:
    student = line.replace("\n", "").split(' ')
    student = get_sequence(student, n_of_q)
    score = []
    for r in range(n_of_q + 1):
        row = [0] * (n_of_q + 1)
        score.append(row)
    for si in range(1, n_of_q + 1):
        for ai in range(1, n_of_q + 1):
            if answer[ai-1] == student[si-1]:
                score[si][ai] = score[si-1][ai-1] + 1
            else:
                score[si][ai] = max([score[si-1][ai], score[si][ai-1]])

    print(score[si][ai])
exit()