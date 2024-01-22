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
    
    ll N;
    cin >> N;
    
    vector<vector<ll>> dist(N, vector<ll>(N, INT_MAX));
    vector<pair<ll,ll>> v(N);
    
    for(int i =0; i<N; ++i){
        cin >> v[i].first >> v[i].second;
        for(int j =0; j<i; ++j){
            if(v[i].second < v[j].first || v[i].first > v[j].second) continue;
            dist[i][j] = dist[j][i] = 1;
        }
    }
    
    for(int k=0;k<N; ++k){
        for(int i =0; i<N; ++i){
            for(int j =0;j<N; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    
    ll Q;
    cin >> Q;
    while(Q--){
        ll a,b;
        cin >> a >> b;
        if(dist[a-1][b-1] == INT_MAX) cout << -1<<"\n";
        else cout << dist[a-1][b-1]<<"\n";
    }
    

    return 0;
} // Geometry(?), Floyd-Warshall