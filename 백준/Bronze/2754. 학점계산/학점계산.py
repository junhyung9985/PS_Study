dic = {'A': 4.0, 'B' : 3.0, 'C' : 2.0, 'D': 1.0, 'F' : 0.0}
s = input()
ans = dic[s[0]]
if(len(s) > 1):
    if s[1] == '+' : ans += 0.3
    if s[1] == '-' : ans -= 0.3

print(ans)