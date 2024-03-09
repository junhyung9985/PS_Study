
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    vector<vector<ll>> p(M+1, vector<ll>(N+1));
    vector<vector<ll>> dp(M+1, vector<ll>(N+1));
    
    for(int i =1 ;i <=M; ++i){
        for(int j =1; j<=N; ++j){
            cin >> p[i][j];
        }
    }

    for(int i = 1; i<=M; ++i){
        for(int j =0; j<=N; ++j){
            for(int k =0; k<=j; ++k){
                dp[i][j] = max(dp[i][j], dp[i-1][j-k]+p[i][k]);
            }
        }
    }
    
    cout << dp[M][N];
    
    return 0;
}/*

State 정의 -> b번째 상인까지 총 a개를 더 팔때 최대 이득.
dp[b][a] = max(dp[b-1][a-c] + p[b][c]);


*/