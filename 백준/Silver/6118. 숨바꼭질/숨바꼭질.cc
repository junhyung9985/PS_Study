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
    vector<ll> visited(N+1, -1);
    deque<ll> q;
    
    for(int i =0 ;i<M; ++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    
    q.push_back(1);
    visited[1] = 0;
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        for(auto itr : E[n]){
            if(visited[itr] == -1){
                visited[itr] = visited[n]+1;
                q.push_back(itr);
            }
        }
    }
    ll idx = 0;
    ll ans = -1;
    ll cnt = 0;
    for(int i =1; i<=N; ++i){
        if(visited[i] > ans){
            ans = visited[i];
            idx = i;
            cnt = 1;
        }
        else if (visited[i] == ans){
            ++cnt;
        }
    }
    
    cout << idx <<" "<<ans <<" "<<cnt<<"\n";

    return 0;
} // BFS