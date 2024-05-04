ls = ['l','k','p']
l = 0; k = 0; p = 0
for i in range(3):
    a = input()
    if a[0] == ls[0] : l+=1
    if a[0] == ls[1] : k += 1
    if a[0] == ls[2] : p+=1

if l == 1 and k == 1 and p == 1: print("GLOBAL")
else : print("PONIX")