import sys
input = sys.stdin.readline
s = input().rstrip().split('-')
ans = ""
for i in s:
    ans = ans + i[0]
print(ans)