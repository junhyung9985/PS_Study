#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS


ll E[501][501];
unsigned ll dist[501];


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        ll N, M;
        ll s,e;
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        cin >> s >> e;
        
        memset(E,0,sizeof(E));
        memset(dist, -1, sizeof(dist));

        for(int i =0; i<M; i++){
            ll u,v,p;
            cin >> u >> v >> p;
            E[u][v] = p;
        }

        dist[s] = 0;
        priority_queue<pair<ll,ll>> pq;
        pq.push({0,s});
        while(!pq.empty()){
            ll d, n;
            tie(d,n) = pq.top();
            pq.pop();
            d *= -1;
            if(dist[n] < d) continue;
            for(int i =0; i<N; i++){
                if(E[n][i]>0 && dist[i] > E[n][i]+d){
                    dist[i] = E[n][i]+d;
                    pq.push({-dist[i], i});
                }
            }
        }

        if(dist[e] == -1){
            cout << -1<<"\n";
            continue;
        }


        priority_queue<pair<ll,ll>> q;
        q.push({dist[e],e});
        while(!q.empty()){
            ll d_curr , curr;
            tie(d_curr, curr) = q.top();
            q.pop();
            for(int i =0; i<N; i++){
                if(dist[i]+E[i][curr] == d_curr && dist[i] < dist[curr]){
                    E[i][curr] = 0;
                    q.push({dist[i], i});
                }
            }
        }
        priority_queue<pair<ll,ll>> pq2;
        memset(dist, -1, sizeof(dist));
        pq2.push({0,s});
        while(!pq2.empty()){
            ll d, n;
            tie(d,n) = pq2.top();
            pq2.pop();
            d *= -1;
            if(dist[n] < d) continue;
            if(n == e) break;
            for(int i =0; i<N; i++){
                if(E[n][i]>0 && dist[i] > E[n][i]+d){
                    dist[i] = E[n][i]+d;
                    pq2.push({-dist[i], i});
                }
            }
        }


        int ans = dist[e];
        cout << ans<<"\n";


    }

    return 0;
}