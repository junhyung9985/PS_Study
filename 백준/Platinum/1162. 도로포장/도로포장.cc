#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<ll>> dist(K+1, vector<ll>(N+1, 1'000'000'000'000));
    vector<vector<pair<ll,ll>>> E(N+1);
    for(int i =0; i<M; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({c,b});
        E[b].push_back({c,a});
    }
    for(int i =1; i<=N ;++i){
        sort(E[i].begin(), E[i].end());
    }
    
    for(int i =0; i<=K; ++i)
        dist[i][1] = 0;
        
    priority_queue<tuple<ll,ll,ll>> pq;
    pq.push({0,1,0});
    while(!pq.empty()){
        ll d, node, cost;
        tie(d, node, cost) = pq.top();
        pq.pop();
        d *= -1;
        if(dist[cost][node] < d) continue;
        for(auto itr : E[node]){
            ll t, n;
            tie(t,n) = itr;
            if(cost < K){
                if(dist[cost+1][n] > d){
                    dist[cost+1][n] = d;
                    for(int l = cost+2; l<=K; ++l) dist[l][n] = min(dist[l][n], dist[cost+1][n]);
                    pq.push({-d, n, cost+1});
                }
            }
            if(dist[cost][n] > d+t){
                dist[cost][n] = d+t;
                for(int l = cost+1; l<=K; ++l) dist[l][n] = min(dist[l][n], dist[cost][n]);
                pq.push({-d-t, n, cost});
            }
        }
    }
    ll ans = dist[0][N];
    for(int i = 1; i<=K; ++i)
        ans = min(ans ,dist[i][N]);
    cout << ans;
    return 0;
} // Dijkstra + DP 
// Cost가 존재하는 Dijkstra 문제