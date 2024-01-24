#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll V, E;
    ll a, b;
    ll dist_a[801];
    ll dist_b[801];
    vector<vector<pair<int,ll>>> g;

    cin >> V >> E;
    
    for(int i =0; i <=V ; i++){
        g.push_back(vector<pair<int,ll>>());
        dist_a[i] = 987654321;
        dist_b[i] = 987654321;
    }
    
    for(int i =0; i<E ; i++){
        int u , v, w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin >> a >> b;
    
    priority_queue<pair<ll, int>> q;
    
    dist_a[a] = 0;
    q.push({-dist_a[a], a});
    while(!q.empty()){
        ll d = (-1)*q.top().first;
        ll u = q.top().second;
        q.pop();
        for(int i =0; i<g[u].size(); i++){
            int v = g[u][i].first;
            int w = g[u][i].second;
            
            if(dist_a[v] > dist_a[u]+w){
                dist_a[v] = dist_a[u]+w;
                q.push({-dist_a[v], v});
            }
        }
    }
    
    dist_b[b] = 0;
    q.push({-dist_b[b], b});
    while(!q.empty()){
        ll d = (-1)*q.top().first;
        ll u = q.top().second;
        q.pop();
        for(int i =0; i<g[u].size(); i++){
            int v = g[u][i].first;
            int w = g[u][i].second;
            
            if(dist_b[v] > dist_b[u]+w){
                dist_b[v] = dist_b[u]+w;
                q.push({-dist_b[v], v});
            }
        }
    }
    
    ll a_1 = dist_a[1];
    ll b_1 = dist_b[1];
    ll a_b = dist_a[b];
    ll a_n = dist_a[V];
    ll b_n = dist_b[V];
    ll dist_1 = a_1+a_b+b_n;
    ll dist_2 = b_1 + a_b + a_n;
    
    bool can_d1 = true, can_d2 = true;
    
    
    if(a_1 == 987654321 || a_b == 987654321 || b_n == 987654321){
        can_d1 = false;
    }
    
    if(b_1 == 987654321 || a_b == 987654321 || a_n == 987654321){
        can_d2 = false;
    }
    
    if(can_d1 && can_d2){
        cout << min(dist_1, dist_2);
    }
    else if(can_d1){
        cout << dist_1;
    }
    else if(can_d2){
        cout << dist_2;
    }
    else cout << -1;
    
    
    return 0;
}

/*
NlogN - binary search
*/