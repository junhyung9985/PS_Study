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

    vector<ll> dp(1001, -1);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;

    for(int i =4; i<=1000; ++i){
        for(int k= 1; k<=3; ++k){
            if(k == 2) continue;
            if(dp[i-k] == 1) {
                dp[i] = 0;
                break;
            }
        }
        if(dp[i] == -1) dp[i] = 1;
    }

    ll N;
    cin >> N;
    if(dp[N]) cout <<"CY";
    else cout<<"SK";
    
    return 0;
}