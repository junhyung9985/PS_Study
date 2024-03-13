n = int(input())
words = ['WELCOME','TO','CCC','GOOD','LUCK','TODAY']

idx = 0
while(idx < 6):
    ls = []
    cnt = 0
    act_cnt = 0
    flag = 0
    while(True):
        if(idx == 6):
            break;
        if(len(words[idx]) + cnt + flag <= n):
            ls.append(words[idx]);
            cnt += len(words[idx])+flag
            act_cnt += len(words[idx])
            idx += 1
            flag = 1
        else : break;
    dots = n - act_cnt;
    ans = ""
    if(len(ls) == 1) :
        ans = ls[0];
        for i in range(dots): ans += '.'
        print(ans)
    else:
        between = dots // (len(ls)-1)
        left_overs = dots % (len(ls)-1)
        for index, i in enumerate(ls):
            ans += i
            if(index == len(ls)-1) : continue
            for _ in range(between):
                ans += '.'
            if(index < left_overs):
                ans += '.'
        print(ans)


