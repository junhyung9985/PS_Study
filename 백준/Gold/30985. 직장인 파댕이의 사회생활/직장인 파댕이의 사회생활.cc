#include <bits/stdc++.h>
#define ll long long
#define INF 1'000'000'000'000'000'000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M, K;
    cin >> N >> M >> K;
    
    vector<ll> elevate(N+1);
    vector<vector<pair<ll,ll>>> E(N+1);
    for(int i =0; i<M; ++i){
        ll s,e,c;
        cin >> s >> e >> c;
        E[s].push_back({e,c});
        E[e].push_back({s,c});
    }
    
    for(int i =1; i<=N; ++i){
        cin >> elevate[i];
    }
    
    vector<ll> dist1(N+1, INF);
    vector<ll> dist2(N+1, INF);
    priority_queue<pair<ll,ll>> pq;
    dist1[1] = 0, dist2[N] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        ll d,n;
        tie(d,n) = pq.top();
        pq.pop();
        d *= -1;
        if(dist1[n] < d) continue;
        for(auto itr : E[n]){
            ll next, cost;
            tie(next, cost) = itr;
            if(dist1[next] > cost+ d){
                dist1[next] = cost+d;
                pq.push({-cost-d, next});
            }
        }
    }
    pq.push({0,N});
    while(!pq.empty()){
        ll d,n;
        tie(d,n) = pq.top();
        pq.pop();
        d *= -1;
        if(dist2[n] < d) continue;
        for(auto itr : E[n]){
            ll next, cost;
            tie(next, cost) = itr;
            if(dist2[next] > cost+ d){
                dist2[next] = cost+d;
                pq.push({-cost-d, next});
            }
        }
    }
    
    ll minn = INF;
    for(int i =1; i<=N; ++i){
        if(elevate[i] == -1) continue;
        if(dist1[i] == INF || dist2[i] == INF) continue;
        minn = min(minn, dist1[i]+dist2[i]+elevate[i]*(K-1));
    }
    if(minn == INF) minn = -1;
    cout << minn;
    
    return 0;
} // Dijkstra
/* 

엘레베이터를 중간에 다른 층에서 환승하는게 더 빠를 수가 없음.
-> 1번에서 i번 방 -> 몇 층 오르고 -> i번 방에서 j번 방 -> K층 도달하기
-> 이건 그냥 1번 방에서 j번방까지 움직였다가 K층까지 오르는 것과 동일함.
-> 모든 층들의 구조가 똑같아서 이게 됨.

따라서 그냥 1번 방부터의 모든 최단거리, N번 방으로부터 모든 최단거리 구하고
각 방에서 K층까지 오를 때 해당 방로부터 1번, N번방의 최단거리를 더해서 비교하면 됨.

O(N+(N+M)logM)
*/