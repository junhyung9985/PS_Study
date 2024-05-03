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
    
    ll N ;
    ll mod = 9901;
    cin >> N;
    
    vector<vector<ll>> dp(3, vector<ll>(N));
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][0] = 1;
    
    for(int i = 1; i<N; ++i){
        dp[0][i] = (dp[0][i-1] + dp[1][i-1] + dp[2][i-1])%9901;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1])%mod;
        dp[2][i] = (dp[0][i-1] + dp[1][i-1])%mod;
    }
    cout << (dp[0][N-1] + dp[1][N-1]+dp[2][N-1])% mod;
    
    return 0;
}
