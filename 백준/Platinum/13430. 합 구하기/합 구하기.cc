#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll mod = 1'000'000'007;

ll power(ll n){
    ll ret = 1;
    ll v = n;
    ll p = mod-2;
    while(p){
        if(p%2) {
            ret *= v;
            ret %= mod;
        }
        v *= v;
        v%=mod;
        p/=2;
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, K;
    cin >> K >> N;
    
    ll ans = 1;
    for(ll i =0;i <=K; ++i){
        ans *= (N+i);
        ans %= mod;
    }

    ll div = 1;
    for(ll i =1; i<=K+1; ++i){
        div *= i;
        div %= mod;
    }

    div = power(div);
    ans = ans * div;
    ans %= mod;

    cout << ans;

    return 0;
}
// https://math.stackexchange.com/questions/234304/sum-of-the-sum-of-the-sum-of-the-first-n-natural-numbers
// Math, Combinatorics, Modular Inverse, Number Theory, 페르마 소정리, DnC
// 이걸 이렇게 표현이 가능하구나...