#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll MOD = 1'000'000'009;
    ll N;
    cin >> N;
    
    vector<vector<ll>> dp(2, vector<ll>(N));
    dp[0][0] = 1;
    dp[1][0] = 0;
    for(int i =0; i<N; ++i){
        if(i+1 < N) {dp[0][i+1] += dp[0][i] + dp[1][i]; dp[0][i+1]%= MOD;};
        if(i+2 < N) {dp[1][i+2] += dp[0][i]; dp[1][i+2] %= MOD;};
    }
    cout << (dp[0][N-1] + dp[1][N-1])%MOD;
    
    
    return 0;
} // DP