import sys

input = sys.stdin.readline
N = int(input())
K, m1, m2 = map(int, input().split())

ans = 0

for _ in range(N):
    h, k, *ls = map(int,input().split())

    for sz in ls:
        if K * h < m2 * sz or m1 * sz < h:
            ans += 1
print(ans)