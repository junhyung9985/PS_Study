#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll _N;
    string s;
    
    cin >> _N;
    cin >> s;
    
    vector<ll> vals;
    vector<char> ops;
    for(auto ch : s){
        if(ch == '+' || ch == '-' || ch == '*') ops.push_back(ch);
        else vals.push_back(ch-'0');
    }
    
    ll N = vals.size();
    vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(N, vector<ll>(N, INT_MIN)));
    
    for(int i =0; i<N; ++i){
        for(int j=0; j<N; ++j){
            dp[1][i][j] = INT_MAX;       
        }
    }
    
    for(int i =0; i<N; ++i){
        dp[0][i][i] = dp[1][i][i] = vals[i];
    }
    
    
    for(int k =1; k<N; ++k){
        for(int i =0; i<N-k; ++i){
            for(int j =i; j<i+k;++j){
                
                if(ops[j] == '+'){
                    dp[0][i][i+k] = max(dp[0][i][i+k], dp[0][i][j]+dp[0][j+1][i+k]);
                    dp[1][i][i+k] = min(dp[1][i][i+k], dp[1][i][j]+dp[1][j+1][i+k]);
                }
                if(ops[j] == '-'){
                    dp[0][i][i+k] = max(dp[0][i][i+k], dp[0][i][j]-dp[1][j+1][i+k]);
                    dp[1][i][i+k] = min(dp[1][i][i+k], dp[1][i][j]-dp[0][j+1][i+k]);
                }
                if(ops[j] =='*'){
                    dp[0][i][i+k] = max(dp[0][i][i+k], dp[0][i][j]*dp[0][j+1][i+k]);
                    dp[1][i][i+k] = min(dp[1][i][i+k], dp[1][i][j]*dp[0][j+1][i+k]);
                    dp[0][i][i+k] = max(dp[0][i][i+k], dp[1][i][j]*dp[1][j+1][i+k]);
                    dp[1][i][i+k] = min(dp[1][i][i+k], dp[0][i][j]*dp[1][j+1][i+k]);
                }
            }
        }
    }
    
    // for(int i =0; i<N; ++i){
    //     for(int j =0; j<N; ++j){
    //         cout << dp[0][i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    cout << dp[0][0][N-1];
    return 0;
} // MCM DP
// O(N^3)