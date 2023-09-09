#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    double ans = 0.0;
    cin >> N >> M;
    
    vector<vector<tuple<ll,ll,ll>>> E;
    
    E.resize(N+1, vector<tuple<ll,ll,ll>>());
    for(int i =0; i<M; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        E[a].push_back({b,c,d});
        E[b].push_back({a,c,d});
    }


    for(int f =1 ;f<=1000; f++){
        vector<ll> dist(N+1, INT_MAX);
        dist[1] = 0;
        priority_queue<pair<ll,ll>> q; // - dist_now, curr
        q.push({0,1});
        
        while(!q.empty()){
            ll d, node;
            tie(d, node) = q.top();
            q.pop();
            d = -d;
            if(d > dist[N] || d > dist[node]) continue;
            
            dist[node] = d;
            for(int i=0; i<E[node].size(); i++){
                ll next, cost, limit;
                tie(next, cost, limit) = E[node][i];
                if(limit < f) continue;
                if(dist[next] <= cost+ d) continue;
                dist[next] = cost+d;
                q.push({-cost-d, next});
            }
        }
        
        double curr_max = (f * 1.0) / (dist[N] * 1.0);
        ans = max(ans ,curr_max);
        
    }
    
    ans *= 1000000;
    ll ans2 = ans;
    cout << ans2;

    return 0;
}

/*

fNlogM

Dijkstra

*/