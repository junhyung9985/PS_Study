import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    a, b = map(int,input().split())
    print("Scenario #{}:".format(_+1))
    if a < 0 and b < 0:
        a *= -1; b *= -1;
        ans = (a*(a+1))//2 - (b *(b-1))//2;
        print(-ans);
    elif a < 0 and b >=0 : 
        a *= -1;
        ans = (b*(b+1))//2 - (a*(a+1))//2;
        print(ans)
    else :
        ans = (b*(b+1))//2 - (a*(a-1))//2;
        print(ans)
    print("\n",end="")