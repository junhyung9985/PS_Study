#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll compute(char ch, ll a, ll b){
    if(ch =='+') return a+b;
    else if(ch == '-') return b-a;
    else if(ch =='*') return a * b;
    else  return b/a;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    bool flag = true;
    vector<vector<ll>> dp(2,vector<ll>(N+1));
    dp[0][0] = dp[1][0] = 1;
    for(int i =1; i<=N; ++i){
        char ch_1, ch_2;
        int o1, o2;
        cin >> ch_1 >>o1 >>ch_2 >> o2;
        if(dp[0][i-1] > 0) dp[0][i] = max(compute(ch_1, o1, dp[0][i-1]),compute(ch_2, o2, dp[0][i-1]));
        if(dp[1][i-1] > 0) dp[1][i] = max(compute(ch_1,o1,dp[1][i-1]), compute(ch_2,o2, dp[1][i-1]));
        if(dp[0][i-1] > 0) dp[1][i] = max(dp[1][i], dp[0][i-1]);
    }
    ll ans = max(dp[0][N], dp[1][N]);
    if(!ans) cout << "ddong game";
    else cout <<ans; 

    return 0;
}