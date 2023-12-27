#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    vector<vector<ll>> E(N+1);
    vector<vector<ll>> E2(N+1);
    while(M--){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E2[b].push_back(a);
    }
    ll ans = 0;
    for(int i = 1; i<=N; ++i){
        deque<ll> q;
        vector<bool> visited(N+1, false);
        vector<bool> visited2(N+1, false);
        
        visited[i] = true;
        q.push_back(i);
        while(!q.empty()){
            ll n = q.front();
            q.pop_front();
            for(auto itr : E[n]){
                if(visited[itr]) continue;
                visited[itr] = true;
                q.push_back(itr);
            }
        }
        
        visited2[i] = true;
        q.push_back(i);
        while(!q.empty()){
            ll n = q.front();
            q.pop_front();
            for(auto itr : E2[n]){
                if(visited2[itr]) continue;
                visited2[itr] = true;
                q.push_back(itr);
            }
        }
        ll cnt = 0;
        for(int j =1; j<=N; ++j)
            if(visited[j] || visited2[j]) ++cnt;
        if(cnt == N) ++ans;
    }
    cout << ans;
    
    return 0;
} // BFS