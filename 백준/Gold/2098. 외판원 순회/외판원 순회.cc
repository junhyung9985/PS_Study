
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;
ll dp[65536][16];
ll w[16][16];

ll ret(ll n, ll contains){
    if(dp[contains][n]) return dp[contains][n];
    ll c = contains;
    dp[contains][n] = 1'000'000'000'000'000'000;
    for(int k = 0; k<N; ++k){
        if(c == 0) break;
        if(c&1){
            if(w[k][n]) dp[contains][n] = min(dp[contains][n], ret(k, contains^(1<<k)) + w[k][n]);
        } 
        c/=2;
    }
    return dp[contains][n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    ll sz = pow(2,N);
    
    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            cin >> w[i][j]; 
        }
        dp[0][i] = w[0][i];
    }

    ll ans = ret(0, (sz-1) ^ 1);
    
    // for(int i = 0; i<sz; ++i){
    //     cout << i <<" : ";
    //     for(int j =0; j<N; ++j){
    //         cout << dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    cout << ans;
    
    return 0;
} 
// DP (Memoization)
// https://en.wikipedia.org/wiki/Held%E2%80%93Karp_algorithm