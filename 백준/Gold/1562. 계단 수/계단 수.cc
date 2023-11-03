#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    ll mod = 1'000'000'000;
    cin >> N;

    vector<vector<vector<ll>>> dp(1024, vector<vector<ll>>(10, vector<ll>(N)));
    // dp[idx][k][i] -> i번째 turn에 마지막으로 k가 나왔으며 binary로 표현하여 현재까지 0 ~ 9중 어느 수들이 들어갔는지를 저장하는 테이블
    for(int i =1; i<10; ++i){
        ll idx =  ((ll)1 << (i));
        dp[idx][i][0] = 1;
    }

    for(int i=1; i<N; ++i){
        for(int j =1; j<1024; ++j){
            for(int k =0; k<10; ++k){
                ll idx = j | (1<<k);
                if(k > 0) {
                    dp[idx][k][i] += dp[j][k-1][i-1];
                    dp[idx][k][i] %= mod;
                }
                if(k < 9) {
                    dp[idx][k][i] += dp[j][k+1][i-1];
                    dp[idx][k][i] %= mod;
                }
            }
        }
    }

    ll ans = 0;
    for(int i =0; i<10; ++i) {
        ans += dp[1023][i][N-1];
        ans %= mod;
    }

    cout << ans;

    return 0;
} // DP, Bitmasking