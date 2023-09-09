def func():
  n = int(input()); tmp = n %6
  ans = []
  if tmp not in [2,3]:
    for i in range(1,n+1):
      if i%2 == 0: ans.append(i)
    for i in range(1,n+1):
      if i%2 == 1: ans.append(i)
  else:
    a1 = [i for i in range(1,n+1) if i%2 == 0]
    a2 = [i for i in range(1,n+1) if i%2 == 1]
    if tmp == 2:
      a2[0],a2[1] = a2[1],a2[0]
      del(a2[2]); a2.append(5)
    if tmp == 3:
      del(a1[0]); a1.append(2)
      del(a2[0]); del(a2[0]);
      a2.extend((1,3))
    ans = a1+a2
  for i in ans:
    print(i)
func()