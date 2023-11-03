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

    ll N, M, Q;
    cin >> N >> M >> Q;
    
    vector<ll> tease_org(N);
    vector<pair<ll,ll>> tease(N);
    vector<vector<pair<ll,ll>>> E(N);
    vector<vector<ll>> dist(N, vector<ll>(N, -1));
    vector<bool> excluded(N, false);
    
    
    for(int i =0; i<N; ++i){
        cin >> tease[i].first;
        tease[i].second = i;
        tease_org[i] = tease[i].first;
    }
    sort(tease.begin(), tease.end(), greater<pair<ll,ll>>());

    for(int i =0; i<M; ++i){
        ll a, b, d;
        cin >> a >> b >> d;
        E[a-1].push_back({b-1, d});
        E[b-1].push_back({a-1, d});
    }

    for(int i =0; i<N; ++i){
        ll city = tease[i].second;
        dist[city][city] = 0;
        priority_queue<pair<ll,ll>> pq;
        pq.push({0, city});
        while(!pq.empty()){
            ll d, n;
            tie(d, n) = pq.top();
            pq.pop();
            d *= -1;
            if(dist[city][n] < d) continue;
            for(auto itr: E[n]){
                ll next_city, cost;
                tie(next_city, cost) = itr;
                if(excluded[next_city]) continue;
                if(dist[city][next_city] > cost + d || dist[city][next_city] == -1){
                    dist[city][next_city] = cost + d;
                    pq.push({-cost-d, next_city});
                }    
            }
        }
        excluded[city] = true;
    }
    
    while(Q--){
        ll s, t;
        cin >> s >> t;
        --s; --t;
        ll ans = -1;
        for(int i =0; i<N; ++i){
            ll d1 = dist[i][s], d2 = dist[i][t];
            if(d1 == -1 || d2 == -1) continue;
            if(ans == -1)  ans = d1+d2+tease_org[i];
            ans = min(ans ,d1+d2+tease_org[i]);
        }
        cout << ans <<"\n";
    }


    return 0;
} // Sorting, Dijkstra, Offline_Query(?)
// -> 각 도시를 포함하여 다익을 돌렸을 때 나오는 결과물
// 값이 큰 도시부터 순서대로 다익을 돌리고, 제거
// Time complexity : O(NMlogM + QN) = 5,000,000 log M + 20,000,000