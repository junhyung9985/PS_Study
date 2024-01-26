#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<ll> s;
    vector<int> ans(2);
    for(string ops : operations){
        if(ops[0] == 'I'){
            ll tmp = 0;
            ll times = 1;
            int start = 2;
            if(ops[start] == '-'){
                times = -1;
                start++;
            }
            for(; start < ops.size(); ++start){
                tmp *= 10;
                tmp += ops[start]-'0';
            }
            tmp *= times;
            s.insert(tmp);
        }
        else {
            if(s.begin() == s.end()) continue;
            if(ops[2] =='-'){
                auto itr = s.begin();
                s.erase(itr);
            }
            else {
                auto itr = s.end();
                itr--;
                s.erase(itr);
            }
        }
    }
    if(s.begin() == s.end()) return ans;

    auto st = s.begin();
    auto e = s.rbegin();
    ans[0] = *e; ans[1] = *st;
    return ans;
}