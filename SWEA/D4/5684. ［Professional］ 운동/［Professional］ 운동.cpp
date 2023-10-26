#include<bits/stdc++.h>
#define ll long long
#define INF 987654321
using namespace std;
// Default

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    for(int tc = 1; tc<=T; ++tc){
        ll N, M;
        cin >> N >> M;
        vector<vector<pair<ll,ll>>> v(N, vector<pair<ll,ll>>());
        for(int i =0;i <M; i++){
            ll a, b, c;
            cin >> a >> b >> c;
            v[a-1].push_back({ b-1, c});
        }
        ll minn = INF;
        
        for(ll i =0; i<N; i++){
            vector<ll> dist(N, INF);
            ll start = i;
            priority_queue<pair<ll,ll>> pq;
            for(pair<ll,ll> next : v[start]){
                pq.push({-next.second, next.first});
            }

            while(!pq.empty()){
                ll d = pq.top().first, n = pq.top().second;
                d *= -1;
                pq.pop();

                if(dist[n] < d) continue;
                dist[n] = d;
                if(n == start) break; // shortest cycle found from start
                for(pair<ll,ll> next : v[n]){
                    if(dist[next.first] > next.second + d){
                        dist[next.first] = next.second+d;
                        pq.push({-dist[next.first], next.first}); 
                    }
                }
            }
            minn = min(minn, dist[start]);
        }
        
        if(minn == INF) minn = -1;
        cout << "#"<<tc<<" "<<minn<<"\n";
    }
    return 0;
}