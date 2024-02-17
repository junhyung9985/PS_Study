#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<vector<ll>> v;
vector<bool> visited;
vector<vector<ll>> dp;

void DFS(ll n){
    visited[n] = true;
    dp[n][0] = 0;
    dp[n][1] = 1;
    for(int i : v[n]){
        if(visited[i]) continue;
        DFS(i);
        dp[n][0] += dp[i][1];
        dp[n][1] += min(dp[i][1], dp[i][0]);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    ll N;
    cin >> N;
    v.resize(N+1);
    visited.resize(N+1, 0);
    dp.resize(N+1, vector<ll>(2,0));
    
    for(int i =0; i<N-1; i++){
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(1);
    ll ans = min(dp[1][0], dp[1][1]);
    cout << ans ;
    

    return 0;
}

/*

Tree DP 기본 문제 2

=> 트리 DP 연습해야할듯 ㅇㅇ

*/


