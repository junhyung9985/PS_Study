#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

ll tree[800008];
ll b[100001];
ll e[100001];
vector<vector<ll>> E(100001);
ll idx = 0;

void DFS(ll n){
    b[n] = idx++;
    for(auto itr :E[n]){
        DFS(itr);
    }
    e[n] = idx++;
}

ll update(ll n, ll s ,ll e, ll idx, ll w){
    if(e < idx || idx < s) return tree[n];
    if(s == e){
        return tree[n] += w;
    }
    return tree[n] = update(2*n,s,(s+e)/2, idx, w) + update(2*n+1, (s+e)/2+1, e, idx, w);
}

ll query(ll n, ll s, ll e, ll idx){
    if(idx < s) return 0;
    if(e <= idx) return tree[n];
    return query(2*n,s,(s+e)/2, idx) + query(2*n+1, (s+e)/2+1, e, idx);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q;
    cin >> N >> Q;
    for(int i = 1; i<=N; ++i){
        ll p;
        cin >> p;
        if(p == -1) continue;
        E[p].push_back(i);
    }
    DFS(1);
    
    while(Q--){
        ll q, i;
        cin >> q >> i;
        if(q == 1){
            ll w;
            cin >> w;
            update(1, 0, idx, b[i], w);
            update(1,0,idx, e[i]+1, -w);
        }
        else {
            cout << query(1,0,idx, b[i]) <<"\n";
        }
    }

    return 0;
} // Segment Tree, Euler Tour