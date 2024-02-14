ls =list(map(int,input().split()))
ls.sort()

while ls[2]>=ls[1]+ls[0]:ls[2]-=1
print(sum(ls))