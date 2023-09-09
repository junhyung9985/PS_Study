#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<vector<ll>> tr(100001, vector<ll>());
vector<vector<ll>> parent(100001, vector<ll>(20,-1));
vector<ll> depth(100001,0);

ll LCA(ll a, ll b){
    if(depth[a] < depth[b]){
        ll tmp = a;
        a = b;
        b = tmp;
    }
    ll diff = depth[a] - depth[b];
    ll cnt = 0;
    while(diff > 0){
        if(diff%2) {
            a = parent[a][cnt];
        }
        cnt++;
        diff/=2;
    }
    
    while(a!=b){
        bool can  = false;
        for(int i = 19; i>-1; i--){
            if(parent[a][i] == -1 || parent[b][i] == -1) continue;
            if(parent[a][i] != parent[b][i]){
                a = parent[a][i];
                b = parent[b][i];
                can = true;
                break;
            }
        }
        if(!can){
            a = parent[a][0];
            b = parent[b][0];
        }
    }

    return a;
}

void DFS(ll n, ll d){
    depth[n] = d;
    for(int child : tr[n]){
        if(depth[child]) continue;
        parent[child][0] = n;
        DFS(child, d+1);
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    cin >> N;
    for(int i =0 ;i<N-1; i++){
        ll a, b;
        cin >> a >> b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }

    DFS(1, 1);

    for(int i =1 ; i<20; i++){
        for(int j =1 ;j<=N; j++){
            if(parent[j][i-1] == -1) continue;
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    } // LCA Table created

    // for(int i =0; i<20; i++){
    //     for(int j =1; j<=N; j++){
    //         cout << parent[j][i]<<" ";
    //     }
    //     cout<<"\n";
    // }


    cin >> M;

    for(int i =0; i<M ;i++){
        ll a, b;
        cin >> a >> b;
        cout << LCA(a, b)<<"\n";
    }

    return 0;
}

// LCA 기본 문제