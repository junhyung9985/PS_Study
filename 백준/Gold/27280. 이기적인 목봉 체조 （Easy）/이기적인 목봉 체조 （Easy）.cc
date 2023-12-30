#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    ll N, M;
    cin >> N >> M;
    
    vector<pair<ll,ll>> v(N);
    for(int i =0; i<N; ++i)
        cin >> v[i].first >> v[i].second;
    
    vector<vector<ll>> f(N, vector<ll>(N));
    
    for(int i =0; i<N; ++i){
        ll maxx = -1, power = 0;
        for(int j =i; j<N; ++j){
            if(v[j].first > maxx){
                maxx = v[j].first;
                power = v[j].second;
            }
            else if(v[j].first == maxx) power += v[j].second;
            f[i][j] = power;
        }    
    } // f[i][j] -> [i,j] 인 구간의 힘의 합 (전처리)
    
    vector<vector<ll>> dp(M, vector<ll>(N));
    
    for(int i =0; i<N; ++i)
        dp[0][i] = f[0][i]; // 초기화
    
    for(int i = 1; i<M; ++i){
        for(int j = 0; j<N; ++j){
            for(int k =0; k<j; ++k){
                dp[i][j] = max(dp[i][j], dp[i-1][k]+f[k+1][j]); 
                // j가 i번째 그룹일 때 -> i-1번째 그룹까지 k, [k+1,j]는 i번째 그룹 
            }
        }
    }
    cout << dp[M-1][N-1];
    
    return 0;
} // DP : O(N^2M)