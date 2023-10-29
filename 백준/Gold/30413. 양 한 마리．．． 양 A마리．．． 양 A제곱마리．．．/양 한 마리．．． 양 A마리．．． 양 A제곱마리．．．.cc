#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll A, B;
    ll mod = 1'000'000'007;
    cin >> A >> B;

    
    if(A == 1){
        cout << B%mod;
        return 0;
    }

    ll val = A;
    ll ans = 1;
    while(B){
        if(B%2){
            ans *= val;
            ans %= mod;
        }
        val = val * val;
        val %= mod;
        B/=2;
    }
    ans = ans+mod-1;
    ans %= mod;
    

    ll p = mod-2;
    ll div = 1;
    val = A-1;
    while(p){
        if(p%2){
            div *= val;
            div %= mod;
        }
        val = val * val;
        val %= mod;
        p/=2;
    }
    ans = ans * div;
    ans %= mod;
    cout << ans;

    return 0;
}/*

A^4 = A^2 A^2 + A

1+A+A^2 + A^3 +... +A^B-1

A^B-1 / (A-1)

Modular Inverse, Number Theory, DnC

*/