#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MOD = 1'000'000'007;

ll inverse(ll n){
    ll p = MOD -2;
    ll ret = 1;
    while(p){
        if(p%2){
            ret *= n;
            ret %= MOD;
        }
        n *= n;
        n %= MOD;
        p/=2;
    }
    return ret;
}

ll fact[4000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    fact[0] = 1;
    for(ll i = 1; i<= 4000000; ++i){
        fact[i] = i * fact[i-1];
        fact[i] %= MOD;
    }
    
    ll Q;
    cin >> Q;
    while(Q--){
        ll n, k;
        cin >> n >> k;
        cout << (((fact[n] * inverse(fact[k])) % MOD) * inverse(fact[n-k])) % MOD<<"\n";
    }
    
    return 0;
} // Modular Inverse, Combinatorics, Math