#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll maxx = 1000000;
    vector<ll> dp(maxx+1,INT_MAX);
    dp[1] = 0;
    for(int i =1; i<=maxx; ++i){
        if(i+1 <= maxx) dp[i+1] = min(dp[i]+1,dp[i+1]);
        if(i*2 <= maxx) dp[2*i] = min(dp[i]+1, dp[2*i]);
        if(i*3 <= maxx) dp[3*i] = min(dp[i]+1, dp[3*i]);
    }
    
    ll N;
    cin >> N;
    cout << dp[N];
    
    return 0;
} // DP