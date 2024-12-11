import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n, m = map(int, input().rstrip().split())
    ans = 0 
    while pow(2,ans) <= n:
        ans+= 1 
    ans += m 
    print(ans)