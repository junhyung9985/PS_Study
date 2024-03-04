#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;
vector<ll> dp(100001);
vector<bool> visited(100001, false);
vector<vector<pair<ll,ll>>> E(100001);

void DFS(ll n){
    bool flag = true;
    for(auto itr : E[n]){
        if(!visited[itr.first]){
            visited[itr.first] = true;
            DFS(itr.first);
            dp[n] += min(itr.second, dp[itr.first]);
            flag = false;
        }
    }
    if(flag) dp[n] = INT_MAX;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i =0; i<N-1; ++i){
        ll a,b,c;
        cin >> a >> b >> c;
        E[a].push_back({b,c});
        E[b].push_back({a,c});
    }
    visited[1] = true;
    DFS(1);
    cout << dp[1];

    return 0;
} // DFS, Tree DP