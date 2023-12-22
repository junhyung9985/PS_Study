import sys
input = sys.stdin.readline
n = int(input())
ls = input().rstrip()

cnt = [0 for _ in range(26)]
for i in range(n):
    idx = ord(ls[i]) - ord('a')
    if idx >= 0 and idx < 26:
        cnt[idx] += 1
print(max(cnt))