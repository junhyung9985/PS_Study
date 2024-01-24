
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m, s, e;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> E(n+1, vector<pair<ll,ll>>());
    vector<vector<pair<ll,ll>>> RE(n+1, vector<pair<ll,ll>>());
    deque<ll> reverse;
    
    vector<ll> dist(n+1, INT_MAX);
    
    for(int i =0; i<m; i++){
        ll a, b, d;
        cin >> a >> b >> d;
        E[a].push_back({b,d});
        RE[b].push_back({a,d});
    }
    
    cin >> s >> e;
    
    dist[s] = 0;
    priority_queue<pair<ll, ll>> q;
    q.push({0,s});
    while(!q.empty()){
        ll node, d;
        tie(d, node) = q.top();
        q.pop();
        d = -d;
        if(d > dist[e] || d > dist[node]) continue;
        dist[node] = d;
        
        for(pair<ll,ll> a : E[node]){
            ll new_d = d+a.second;
            ll next = a.first;
            if(dist[next] > new_d){
                dist[next] = new_d;
                q.push({-new_d, next});
            }
        }
    }
    
    ll node = e;
    while(node!=s){
        reverse.push_front(node);
        for(pair<ll,ll> a : RE[node]){
            if(dist[a.first] == dist[node]-a.second){
                node= a.first;
            }
        }
    }
    reverse.push_front(s);
    
    cout << dist[e]<<"\n";
    cout << reverse.size()<<"\n";
    for(ll i : reverse)
        cout << i <<" ";
    
    
    return 0;
}
/*

Dijkstra + DP Backtracking 

*/