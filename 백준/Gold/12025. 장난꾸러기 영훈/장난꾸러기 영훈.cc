#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    ll K;
    cin >> K;
    
    vector<ll> idxs;
    vector<bool> does;
    for(int i = s.size()-1; i>-1; --i){
        if(s[i] == '1' || s[i] == '6' || s[i] == '2' || s[i] == '7'){
            idxs.push_back(i);
            does.push_back(false);
        }
    }
    
    --K;
    ll idx = 0;
    while(K){
        if(idx == idxs.size()){
            cout << -1;
            return 0;
        }
        if(K%2){
            does[idx] = true;
        }
        K/=2;
        ++idx;
    }
    
    for(int i =0; i<idxs.size(); ++i){
        if(does[i]){
            if(s[idxs[i]] == '1') s[idxs[i]] = '6';
            if(s[idxs[i]] == '2') s[idxs[i]] = '7';
        }
        else{
            if(s[idxs[i]] == '6') s[idxs[i]] = '1';
            if(s[idxs[i]] == '7') s[idxs[i]] = '2';
        }
    }
    cout << s;

    return 0;
} // Bitmasking, Ad_hoc(?)