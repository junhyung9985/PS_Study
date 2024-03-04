#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> dp;
vector<bool> visited;
vector<vector<pair<ll,ll>>> E;

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
    if(flag && n != 1) dp[n] = INT_MAX;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    
    while(T--){
        ll N, M;
        cin >> N >> M;
        E.resize(N+1);
        visited.resize(N+1, false);
        dp.resize(N+1);
        for(int i =0; i<M; ++i){
            ll a,b,c;
            cin >> a >> b >> c;
            E[a].push_back({b,c});
            E[b].push_back({a,c});
        }
        visited[1] = true;
        DFS(1);
        cout << dp[1]<<"\n";
        E.clear();
        visited.clear();
        dp.clear();
    }
    return 0;
} // DFS, Tree DP