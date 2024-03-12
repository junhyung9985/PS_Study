N = int(input())
l = -1; r = 10 ** 18

while(l+1 < r):
    mid = (l+r)//2
    if(mid*mid >= N) : r = mid
    else : l = mid
print(r)