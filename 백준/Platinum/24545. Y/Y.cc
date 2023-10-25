#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<vector<ll>> par;
vector<ll> depth;
    
ll LCA(ll a, ll b){
    if(depth[a] < depth[b]){
        ll tmp = a;
        a = b;
        b = tmp;
    }
    int cnt = 0;
    ll cng = depth[a] - depth[b];
    while(cng){
        if(cng%2){
            a = par[cnt][a];
        }
        ++cnt;
        cng /= 2;
    }

    while(a!=b){
        bool flag = true;
        for(int i= 19; i>-1; --i){
            if(par[i][a] == -1 || par[i][b] == -1) continue;
            if(par[i][a] == par[i][b]) continue;
            a = par[i][a];
            b = par[i][b];
            flag = false;
        }
        if(flag){
            a = par[0][a];
            b = par[0][b];
        }
    }

    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    
    vector<vector<ll>> E(N+1);
    vector<ll> f_depth(N+1, -1);
    depth.resize(N+1, -1);
    par.resize(20, vector<ll>(N+1,-1));

    for(int i =0; i<N-1; ++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    ll f, e;
    deque<pair<ll, ll>>q;
    q.push_back({1, 1});
    f_depth[1] = 1;
    while(!q.empty()){
        ll n, d;
        tie(n,d) = q.front();
        q.pop_front();
        f = n;
        for(int next : E[n]){
            if(f_depth[next] == -1){
                f_depth[next] = d+1;
                q.push_back({next, d+1});
            }
        }
    } // BFS O(N)

    q.push_back({f, 1});
    depth[f] = 1;
    while(!q.empty()){
        ll n, d;
        tie(n,d) = q.front();
        q.pop_front();
        e = n;
        for(int next : E[n]){
            if(depth[next] == -1){
                depth[next] = d+1;
                q.push_back({next, d+1});
                par[0][next] = n;
            }
        }
    } // BFS O(N)

    for(int i =1 ;i<20; ++i){
        for(int j =1; j<=N; ++j){
            if(par[i-1][j] == -1) continue;
            par[i][j] = par[i-1][par[i-1][j]];
        }
    } // LCA - Sparse Table O(NlogN)

    ll ans = depth[e];
    ll maxx = 0;
    for(int i =1; i<=N; ++i){
        if(E[i].size() == 1){
            if(i == e || i == f) continue;
            ll lca = LCA(e, i);
            maxx = max(maxx , depth[i]-depth[lca]);
        }
    }
    if(maxx == 0) ans = 0;
    cout << ans + maxx<<"\n";

    return 0;
}
/*
트리의 지름 + 이를 포함 안하는 선들 중 제일 긴 거 (LCA)
*/