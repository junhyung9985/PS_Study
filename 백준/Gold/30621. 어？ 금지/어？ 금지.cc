#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> v;
vector<ll> q;
    

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<vector<ll>> dp(2, vector<ll>(N));
    vector<ll> t(N),b(N),c(N);
    
    for(int i =0; i<N; ++i)
        cin >> t[i];
    for(int i =0; i<N; ++i)
        cin >> b[i];
    for(int i =0; i<N; ++i)
        cin >> c[i];
        
    dp[0][0] = 0;
    dp[1][0] = c[0];    
    for(int i =1; i<N; ++i){
        dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
        ll tmp = t[i]-b[i];
        ll idx = lower_bound(t.begin(), t.end(), t[i]-b[i]) - t.begin();
        if(idx == 0){
            dp[1][i] = c[i];
        }
        else{
            dp[1][i] = c[i]+max(dp[1][idx-1], dp[0][idx-1]);
        }
    }
    
    cout << max(dp[0][N-1], dp[1][N-1]);
    
    return 0;
}
/*

Binary Search, DP

*/
