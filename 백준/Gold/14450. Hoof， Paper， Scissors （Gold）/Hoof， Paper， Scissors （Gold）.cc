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

ll win(ll a, ll b){
    if((a+1)%3 == b) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, K;
    cin >> N >> K;
    vector<vector<vector<ll>>> dp(K+1,vector<vector<ll>>(3, vector<ll>(N)));
    vector<ll> which(N);
    for(int i =0; i<N; ++i){
        char ch;
        cin >> ch;
        if(ch == 'P') which[i] = 0;
        if(ch == 'S') which[i] = 1;
        if(ch == 'H') which[i] = 2;
    }
    dp[0][0][0] = win(0, which[0]);
    dp[0][1][0] = win(1, which[0]);
    dp[0][2][0] = win(2, which[0]);
    
    ll ans = 0;
    for(int k = 0; k<=K; ++k){
        for(int i = 1; i<N; ++i){
            for(ll j =0;j<3; ++j){
                dp[k][j][i] = dp[k][j][i-1] + win(j, which[i]);
                if(k > 0){
                    for(int l = 0; l<3; ++l){
                        dp[k][j][i] = max(dp[k][j][i], dp[k-1][l][i] + win(j,which[i]));
                    }
                }
                ans = max(ans, dp[k][j][i]);
            }    
        }        
    }
    cout << ans;
    return 0;
}

