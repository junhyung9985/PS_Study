#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MOD = 1'000'000'007;

ll power(ll idx){
    ll t = 2;
    ll ret = 1;
    while(idx){
        if(idx%2){
            ret *= t;
            ret %= MOD;
        }
        t *= t;
        t %= MOD;
        idx/=2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<ll> dp(N);
    vector<ll> ans(4);
    
    string s;
    cin >> s;
    
    for(int i =0; i<N; ++i){
        if(s[i] == 'R'){
            ans[0] += power(i);
            ans[0] %= MOD;
        }
        if(s[i] == 'O'){
            ans[1] += ans[0];
            ans[1] %= MOD;
        }
        if(s[i] == 'C'){
            ans[2] += ans[1];
            ans[2] %= MOD;
        }
        if(s[i] == 'K'){
            ans[3] += ans[2];
            ans[3] %= MOD;
        }
    }
    
    cout << ans[3];
    return 0;
}