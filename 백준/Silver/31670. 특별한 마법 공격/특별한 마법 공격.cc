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
    for(int i =0; i<N; ++i)
        cin >> v[i];
        
    vector<vector<ll>> dp(2, vector<ll>(N+1));
    
    for(int i = 0 ; i<N; ++i){
        if(i == 0){
            dp[1][i] = v[i];
        }
        else if(i == 1){
            dp[0][i] = dp[1][i-1];
            dp[1][i] = min(v[i]+dp[1][i-1], v[i] + dp[0][i-1]);
        }
        else{
            dp[0][i] = dp[1][i-1];
            dp[1][i] = min(min(v[i] + dp[1][i-2], v[i] + dp[1][i-1]), v[i]+dp[0][i-1]);
        }
    }
    cout << min(dp[0][N-1], dp[1][N-1]);
    
    return 0;
} // DP