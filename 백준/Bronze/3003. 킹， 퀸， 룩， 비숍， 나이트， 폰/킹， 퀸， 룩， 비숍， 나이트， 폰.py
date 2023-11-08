l = [1,1,2,2,2,8]
ls = list(map(int,input().split()))
ans = [l[i]-ls[i] for i in range(6)]
for i in ans:
    print(i, end=" ")