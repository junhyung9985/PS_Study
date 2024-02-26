#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;
vector<vector<ll>> p;
vector<ll> c;
vector<ll> depth;
vector<vector<pair<ll,ll>>> E;

void DFS(ll n){
    for(auto itr : E[n]){
        if(depth[itr.first] == -1){
            depth[itr.first] = depth[n]+1;
            p[0][itr.first] = n;
            c[itr.first] = c[n]+itr.second;
            DFS(itr.first);
        }
    }
    return ;
}

ll LCA(ll a, ll b){
    
    if(depth[a] < depth[b]) swap(a,b);
    
    ll diff = depth[a] - depth[b];
    ll idx = 0;
    while(diff){
        if(diff%2) a = p[idx][a];
        diff/=2;
        ++idx;
    }
    
    idx = 0;
    while(a != b){
        bool flag = true;
        for(int i = 19; i>-1; --i){
            if(p[i][a] != p[i][b]){
                a = p[i][a];
                b = p[i][b];
                flag = false;
                break;
            }
        }
        if(flag){
            a = p[0][a];
            b = p[0][b];
        }
    }
    
    return a;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    p.resize(20, vector<ll>(N+1));
    c.resize(N+1);
    depth.resize(N+1, -1);
    E.resize(N+1);
    
    for(int i =0; i<N-1; ++i){
        ll a, b, cost;
        cin >> a >> b >> cost;
        E[a].push_back({b,cost});
        E[b].push_back({a,cost});
    }
    depth[1] = 0;
    DFS(1);
    
    for(int i = 1; i<20; ++i){
        for(int j = 1; j<=N; ++j){
            if(p[i-1][j] == 0) continue;
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
    
    ll Q;
    cin >> Q;
    while(Q--){
        ll q, a, b, lca;
        cin >> q >> a >> b;
        lca = LCA(a,b);
        if(q == 1){
            cout << c[a]+c[b]-2*c[lca]<<"\n";
        }
        else{
            
            ll d, start = a, idx = 0;
            cin >> d;
            --d;
            //cout << start << " " << depth[a] + depth[b] - 2*depth[lca] - d << " ";
            if(lca == b) ;
            else if(lca == a || d > depth[a] - depth[lca]){
                start = b;
                d = depth[a] + depth[b] - 2*depth[lca]- d;
            }
            //cout << start << " " << depth[a] + depth[b] - 2*depth[lca] - d << " ";
            while(d){
                if(d%2) start=p[idx][start];
                d/=2;
                ++idx;
            }
            cout << start<<"\n";
        }
    }
    
    return 0;
} // LCA, DFS