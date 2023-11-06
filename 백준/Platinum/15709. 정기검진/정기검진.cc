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
    ll N, M, B, K, Q;
    cin >> N >> M >> B >> K >> Q;

    vector<vector<pair<ll,ll>>> E(N+M+B);
    vector<vector<ll>> dist(B, vector<ll>(N+M+B, -1));

    for(int i =0; i<K; ++i){
        ll a, b, k;
        cin >> a >> b >> k;
        E[a-1].push_back({b-1, k});
        E[b-1].push_back({a-1, k});
    }

    for(int start = 0; start<B; ++start){
        int n = start+N+M;
        dist[start][n] = 0;
        priority_queue<pair<ll,ll>> pq;
        pq.push({0,n});
        while(!pq.empty()){
            ll d, n;
            tie(d,n) = pq.top();
            pq.pop();
            d *= -1;
            if(dist[start][n] < d) continue;
            for(auto itr : E[n]){
                if(dist[start][itr.first] > d + itr.second || dist[start][itr.first] == -1){
                    dist[start][itr.first] = d+ itr.second;
                    pq.push({-dist[start][itr.first], itr.first});
                }
            }
        }
    }

    while(Q--){
        ll s, e;
        cin >> s >> e;
        --s; --e;
        ll ans = -1;
        for(int i =0; i<B; ++i){
            if(dist[i][s] == -1 || dist[i][e] == -1) continue;
            if(ans == -1) ans = dist[i][s] + dist[i][e];
            ans = min(ans, dist[i][s] + dist[i][e]);
        }
        cout << ans<<"\n";
    }

    return 0;
} // B->N, B, E
// 사실상 O(B)만에 모든 쿼리에 대해서 대답을 할 수 있을듯?
// 모든 도시들은 특정 다리를 지나가야 하므로 해당 다리가 최단경로에 포함되어 있으면 그 다리에서의 시작점과 목적지 간의 거리의 합이 최소일 것임!
// O(BKlogK + QB)
// Dijkstra