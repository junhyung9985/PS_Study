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
    
    ll N, M, K;
    
    cin >> N >> M >> K;

    vector<vector<ll>> dp(M, vector<ll>(K));
    vector<ll> chosen(N);
    
    for(int i=0; i<N; ++i){
        cin >> chosen[i];
        if(M == 1 && chosen[i] == 0) continue;
        dp[0][chosen[i]%K]++;    
    }
    vector<ll> ms(M);
    ms[0] = 1;
    for(int i =1; i<M; ++i){
        ms[i] = ms[i-1] * 10;
        ms[i] %= K;
    }
    
    for(int m = 1; m<M; ++m){
        for(int k =0; k<K;++k){
            for(int n = 0; n<N; ++n){
                if(m == M-1 && chosen[n] == 0) continue;
                dp[m][(k+chosen[n]*ms[m])%K]+=dp[m-1][k];
                dp[m][(k+chosen[n]*ms[m])%K]%= 1000000007;
            }
        }
    }
    
    ll ans = dp[M-1][0];
    cout << ans;
    
    return 0;
}
/*

dp[M][0]

*/