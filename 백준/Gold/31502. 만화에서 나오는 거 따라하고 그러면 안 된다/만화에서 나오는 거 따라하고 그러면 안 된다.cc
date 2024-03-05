#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    ll A, B, C;

    cin >> N >> M;
    cin >> A >> B >> C;

    vector<vector<pair<ll,ll>>> E(N+1);
    vector<ll> dist1(N+1, 1'000'000'000'000'000'000);
    vector<ll> dist2(N+1, 1'000'000'000'000'000'000);
    vector<bool> able(N+1, false);
    vector<bool> visited(N+1, false);
    
    for(int i = 0 ; i < M ; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({c,b});
        E[b].push_back({c,a});
    }
    
    for(int i = 1; i <= N; ++i)
        sort(E[i].begin(), E[i].end());

    // BFS
    visited[C] = true;
    dist1[C] = 0;
    
    deque<ll> q;
    q.push_back(C);
    
    while(!q.empty()){
        
        ll n = q.front();
        q.pop_front();
        
        for(auto itr : E[n]){
            
            if(visited[itr.second]) continue;
            
            visited[itr.second] = true;
            dist1[itr.second] = dist1[n]+ 1;
            q.push_back(itr.second);
            
        }
    }
    
    // for(int i =1 ;i<=4; ++i) cout << dist1[i]<<" : " << E[i].size()<<"\n";
    // cout<<"\n";
    
    // Backtracking
    ll n = B;
    able[B] = true;
    while(n != C){
        //cout << n <<"\n";
        able[n] = true;
        vector<pair<ll,ll>> cand;
        
        for(auto itr : E[n]){
            if(dist1[n] == dist1[itr.second] + 1){
                cand.push_back({E[itr.second].size(), itr.second});
            }
        }
        
        sort(cand.begin(), cand.end());
        n = cand.back().second;
    }
    able[C] = true;
    
    
    // Dijkstra
    dist2[A] = 0;
    priority_queue<pair<ll,ll>> pq;
    pq.push({0,A});
    
    while(!pq.empty()){
        ll d, n;
        tie(d, n) = pq.top();
        pq.pop();
        
        d *= -1;
        if(dist2[n] < d) continue;
        
        for(auto itr : E[n]){
            if(dist2[itr.second] > d + itr.first){
                dist2[itr.second] = d + itr.first;
                pq.push({-d-itr.first, itr.second});
            }
        }
        
    }
    
    ll ans = 0, minn = 1'000'000'000'000'000'000; 
    for(int i =1; i<=N; ++i){
        assert(dist2[i] < 1'000'000'000'000'000'000);
        if(able[i]){
            if(minn > dist2[i]) ans = i;
            minn = min(minn, dist2[i]);
        }
    }
    
    cout << ans;
    return 0;
} // Dijkstra