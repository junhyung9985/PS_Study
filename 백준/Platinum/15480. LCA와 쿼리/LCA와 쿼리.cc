#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<vector<ll>> E;
vector<ll> depth;
vector<vector<ll>> parent;

void DFS(ll n, ll d){
    depth[n] = d;
    for(auto itr : E[n]){
        if(depth[itr] == 0){
            parent[0][itr] = n;
            DFS(itr, d+1);
        }
    }
    return;
}

ll LCA(ll a, ll b){
    if(depth[a] < depth[b]){
        ll tmp = a;
        a = b;
        b = tmp;
    }
    int idx = 0;
    ll diff = depth[a]- depth[b];
    while(diff){
        if(diff%2) a = parent[idx][a];
        diff/=2;
        ++idx;
    }

    while(a != b){
        bool flag = true;
        for(int i= 20; i>-1; --i){
            if(parent[i][a] == -1) continue;
            if(parent[i][a] != parent[i][b]){
                flag = false;
                a = parent[i][a];
                b = parent[i][b];
                break;
            }
        }
        if(flag){
            a = parent[0][a];
            b = parent[0][b];
        }
    }
    return a;
}   


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    depth.resize(N+1);
    parent.resize(21, vector<ll>(N+1, -1));
    E.resize(N+1, vector<ll>());
    for(int i =0; i<N-1; ++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    DFS(1, 1);

    for(int i =1; i<=20; ++i){
        for(int j =1; j<=N; ++j){
            if(parent[i-1][j] == -1) continue;
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
    ll Q;
    cin >> Q;
    while(Q--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll l_1 = LCA(a,b), l_2 = LCA(b,c), l_3 = LCA(c,a);
        if(l_1 == l_2) cout << l_3<<"\n";
        else if (l_2 == l_3) cout <<l_1<<"\n";
        else cout << l_2 <<"\n";
    }


    return 0;
} // lca(d, a), lca(d, b), lca(a, b)
// 이 중에서 다른 거 하나 고르면 될듯?
// https://stackoverflow.com/questions/25371865/find-multiple-lcas-in-unrooted-tree
// LCA