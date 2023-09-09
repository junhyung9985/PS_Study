#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll parent[20][40005];
ll cost[40005];
ll depth[40005];
vector<vector<pair<ll,ll>>> E;

ll LCA(ll a, ll b){
    ll a_t = a, b_t = b;
    ll idx = 0;

    if(depth[a] < depth[b]){
        ll tmp = a;
        a = b;
        b = tmp;
    }
    ll diff = depth[a] - depth[b];
    while(diff){
        if(diff%2){
            a = parent[idx][a];
        }
        ++idx;
        diff/=2;
    }

    while(a != b){
        bool flag = true;
        for(int i = 19; i>-1; --i){
            if(parent[i][a] == -1) continue;
            if(parent[i][a] != parent[i][b]){
                a = parent[i][a];
                b = parent[i][b];
                flag = false;
            }
        }

        if(flag){
            a = parent[0][a];
            b = parent[0][b];
        }
    }

    return cost[b_t]+cost[a_t]-2*cost[a];
}

void DFS(ll n, ll d, ll c){
    depth[n] = d;
    cost[n] = c;
    for(auto node:  E[n]){
        ll next, cost;
        tie(next, cost) = node;
        if(depth[next] > 0) continue;
        parent[0][next] = n;
        DFS(next, d+1, c+cost);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(parent, -1, sizeof(parent));
    memset(depth, 0, sizeof(depth));

    ll N;
    cin >> N;
    E.resize(N+1);
    for(int i =0; i<N-1; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b,c});
        E[b].push_back({a,c});
    }

    DFS(1, 1, 0);

    for(int p=1 ;p<20; ++p){
        for(int j =1; j<=N; ++j){
            if(parent[p-1][j] == -1) continue;
            parent[p][j] = parent[p-1][parent[p-1][j]];
        }
    }

    ll Q;
    cin >> Q;
    while(Q--){
        ll a, b;
        cin >> a >> b;
        cout << LCA(a,b)<<"\n";
    }

    return 0;
}