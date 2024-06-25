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
    
    vector<ll> v(N);
    vector<vector<ll>> dp(3, vector<ll>(N, -1));
    for(int i = 0; i<N; ++i)
        cin >> v[i];
    
    dp[0][0] = 0;
    for(int i = 0; i<N-1; ++i){
        if(dp[0][i] == -1) continue;
        if(i + v[i] >= N) continue;
        dp[0][i+v[i]] = max(dp[0][i+v[i]], dp[0][i]+1);
    }
    for(int i = N-2; i>-1; --i){
        if(i-v[i] < 0) continue;
        if(dp[0][i] != -1) dp[1][i-v[i]] = max(dp[1][i-v[i]], dp[0][i] + 1);
        if(dp[1][i] != -1) dp[1][i-v[i]] = max(dp[1][i-v[i]], dp[1][i] + 1);
    }
    
    for(int i = 0; i<N-1; ++i){
        if(i + v[i] >= N) continue;
        if(dp[1][i] != -1) dp[2][i+v[i]] = max(dp[2][i+v[i]], dp[1][i] + 1);
        if(dp[2][i] != -1) dp[2][i+v[i]] = max(dp[2][i+v[i]], dp[2][i] + 1);
    }
    
    ll ans = max(dp[0][N-1], dp[2][N-1]);
    cout << ans;
    
    return 0;
} // DP