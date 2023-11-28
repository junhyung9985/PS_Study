#include <bits/stdc++.h>
#define ll long long
#define INF 987654321
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> c(402, vector<ll>(402));
    vector<vector<ll>> f(402, vector<ll>(402));
    vector<vector<ll>> E(402, vector<ll>());

    for(int i = 0; i<M; ++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
        ++c[a][b];
    }

    ll s = 1;
    ll e = 2;
    ll total = 0;
    while(true){
        vector<ll> visited(402, -1);
        deque<ll> q;
        q.push_back(1);
        while(!q.empty()){
            ll n =  q.front();
            q.pop_front();
            for(auto itr : E[n]){
                if(c[n][itr] - f[n][itr] > 0 && visited[itr] == -1){
                    visited[itr] = n;
                    q.push_back(itr);
                    if(itr == e) break;
                }    
            }
        } // BFS
        
        if(visited[e] == -1) break; // 더 이상 얘로 못 보낼 때.
        
        ll min_flow = INT_MAX;
        ll curr = e;
        while(curr != 1){
            min_flow = min(min_flow, c[visited[curr]][curr] - f[visited[curr]][curr]);
            curr = visited[curr];
        } // Minimum flow
        
        curr = e;
        while(curr != 1){
            f[visited[curr]][curr] += min_flow;
            f[curr][visited[curr]] -= min_flow;
            curr = visited[curr];
        }
        total += min_flow;
    }
    
    cout << total;
	return 0;
} // Maximum Flow , Edmond-Karp