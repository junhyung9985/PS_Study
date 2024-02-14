
#include <bits/stdc++.h>
#define ll long long

using namespace std;

deque<char> s;

set<deque<char>> m;

void can(deque<char> k){
    if(m.find(k) != m.end()) return;
    if(k.size() == s.size()) {
        bool ret = true;
        for(int i =0; i<s.size(); ++i){
            ret = ret && (s[i] == k[i]);
        }
        if(ret){
            cout << 1;
            exit(0);
        }
        m.insert(k);
    }
    if(k.front() == 'B' && k.back() == 'B'){
        k.pop_front();
        reverse(k.begin(), k.end());
        can(k);
    }
    else if(k.front() == 'A' && k.back() == 'A'){
        k.pop_back();
        can(k);
    }
    else if(k.front() == 'B' && k.back() == 'A'){
        deque<char> nk = k;
        nk.pop_front();
        reverse(nk.begin(), nk.end());
        k.pop_back();
        can(nk);
        can(k);
    }
    m.insert(k);
    return;
}

int main()
{   
    deque<char> t;
    string tmp;
    string tmp2;
    cin >> tmp ;
    cin >> tmp2 ;
    for(char ch : tmp) s.push_back(ch);
    for(char ch : tmp2) t.push_back(ch);
    
    can(t);
    cout << 0;
    
    return 0;
}