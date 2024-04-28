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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    
    
    vector<vector<ll>> a(30, vector<ll>(N));
    for(int i =0; i<N; ++i){
        ll tmp;
        cin >> tmp;
        for(int j = 0; j<30 ;++j){
            a[j][i] = tmp%2;
            tmp/=2;
            
        }
    }

    ll MOD = 998244353;
    ll AND = 0, OR = 0, XOR = 0;
    ll val = 1;
    for(int i = 0; i<30; ++i){
        
        ll xor_odd = 0, xor_even = 1;
        ll last_one = -1;
        ll consecutive_one = 0;
        ll sum = 0;
        for(int j = 0; j<N; ++j){
            sum += a[i][j];
            if(a[i][j] == 1){
                last_one = j;
                ++consecutive_one;
            }
            else {
                consecutive_one = 0;
            }
            AND += (val * consecutive_one) % MOD;
            AND %= MOD;
            OR += (val * (last_one+1)) % MOD;
            OR %= MOD;
            if(sum%2){
                XOR += (val * xor_even) % MOD;
                ++xor_odd;
            }
            else{
                XOR += (val * xor_odd) % MOD;
                ++xor_even;
            }
            
            XOR %= MOD;
        }
        //cout << OR <<"\n";
        val *= 2;
        val %= MOD;
    }
    
    cout << AND <<" "<<OR <<" "<<XOR<<"\n";
    return 0;
} // Bitmasking, Combinatorics, Prefix Sum...?