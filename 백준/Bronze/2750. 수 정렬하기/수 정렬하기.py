n = int(input())
answer = []
for i in range(n):
    tmp = int(input())
    answer.append(tmp)

answer = sorted(answer)
for i in answer:
    print(i)