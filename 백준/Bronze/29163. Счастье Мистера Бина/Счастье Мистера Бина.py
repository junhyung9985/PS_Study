n = int(input())
ls = list(map(int,input().split()))
cnt = 0
for i in ls :
    cnt += i%2
if(cnt >= len(ls)-cnt): print("Sad")
else : print("Happy")
