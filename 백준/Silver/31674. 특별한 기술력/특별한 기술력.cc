//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
// Compiler Optimization Options

#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension
// Rope

ll MOD = 1'000'000'007;

ll power(ll n){
    ll ret = 1;
    ll t = 2;
    while(n){
        if(n%2){
            ret *= t;
            ret  %= MOD;
        }
        t *= t;
        t %= MOD;
        n/=2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<ll> v(N);
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll ans = 0;
    for(int i =0; i<N; ++i){
        ans += (v[i] * power(N-i-1)) % MOD;
        ans %= MOD;
    }
    cout << ans;

    return 0;
} // Greedy, Sorting