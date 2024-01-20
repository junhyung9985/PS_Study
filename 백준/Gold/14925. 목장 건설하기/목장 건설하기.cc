#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> M >> N;
    
    vector<vector<ll>> v(M, vector<ll>(N));
    vector<vector<ll>> dp(M, vector<ll>(N));
    
    for(int i =0; i<M; ++i){
        for(int j =0; j<N; ++j){
            cin >> v[i][j];
        }
    }
    
    ll maxx = 0;
    for(int i =0; i<M; ++i){
        for(int j =0; j<N; ++j){
            if(v[i][j] == 0){
                dp[i][j] = 1;
                if(i > 0 && j > 0) {
                    if(!v[i-1][j] && !v[i][j-1] && !v[i-1][j-1]){
                        ll smallest = dp[i-1][j];
                        smallest = min(smallest, dp[i-1][j]);
                        smallest = min(smallest, dp[i][j-1]);
                        smallest = min(smallest, dp[i-1][j-1]);
                        dp[i][j] += smallest;
                    }
                }
                maxx = max(maxx, dp[i][j]);
            }
            //cout << dp[i][j] <<" ";
        }
        //cout<<"\n";
    }
    
    cout << maxx;

    return 0;
} // 2D Prefix Sum