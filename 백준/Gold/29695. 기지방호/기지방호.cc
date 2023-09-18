#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, L, t, N, M;
    cin >> T >> L >> t >> N >> M;

    if(t > T) {
        t = T; 
    } 
    vector<vector<vector<int>>> tactics(T, vector<vector<int>>(N, vector<int>(M)));
    vector<vector<vector<ll>>> dp(T, vector<vector<ll>>(T, vector<ll>(t))); 
    vector<ll> to_do(L);
    
    for(int tactic = 0; tactic <T; tactic++){
        for(int row = 0; row<N; row++){
            for(int col =0; col<M; col++){
                cin >> tactics[tactic][row][col];
            }
        }
    } 
    
    for(int i =0; i<L; i++){
        cin >> to_do[i];
        --to_do[i];
    } 
    
    for(int i =0; i<T; i++){
        for(int j=i+1; j<T; j++){
            ll diffs = 0;
            for(int row = 0; row<N; row++){
                for(int col =0; col<M; col++){
                    if(tactics[i][row][col] != tactics[j][row][col]) diffs++;
                }
            }
            dp[i][j][0] = dp[j][i][0] = diffs*diffs;
        }
    } 
    if(t == T){
        for(int i = 0; i<T; i++){
            for(int j =0 ;j<T; j++){
                for(int k =0; k<T; k++){
                    dp[j][k][0] = min(dp[j][k][0], dp[j][i][0]+dp[i][k][0]);
                }
            }
        }
        t = 1;
    }
    else {
        for(int turn = 1; turn < t; ++turn){
            for(int i = 0; i<T; i++){
                for(int j =0; j<T; j++){
                    dp[i][j][turn] = dp[i][j][turn-1];
                    for(int k =0; k<T; k++){
                        dp[i][j][turn] = min(dp[i][j][turn], dp[i][k][turn-1]+dp[k][j][0]);
                    }
                }
            }
        }
    }

    int curr_tactic = 0;
    ll ans = 0;
    for(int i =0; i<L; i++){
        ll next_tactic = to_do[i];
        ans += dp[curr_tactic][next_tactic][t-1];
        curr_tactic = next_tactic;
    }
    cout << ans;
    return 0;
}