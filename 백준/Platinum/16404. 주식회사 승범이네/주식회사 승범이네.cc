#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int cnt = 0;
ll tr[800005];
ll lazy[800005];
vector<vector<ll>> E;
vector<ll> in, out;

void DFS(ll n){
    in[n] = cnt;
    ++cnt;
    for(auto itr : E[n]){
        DFS(itr);
    }
    out[n] = cnt;
    ++cnt;
    return;
}

ll update(ll n, ll s ,ll e ,ll idx, ll val){
    if(e < idx || idx < s) return tr[n];
    if(s == e) return tr[n] += val;
    ll mid = (s+e)/2;
    return tr[n] = update(2*n, s, mid, idx, val) + update(2*n+1, mid+1, e, idx, val);
}

ll query(ll n, ll s, ll e, ll idx){
    if(idx < s) return 0;
    if(e <= idx) return tr[n];
    ll mid = (s+e)/2;
    return query(n*2, s, mid, idx) + query(n*2+1, mid+1, e, idx);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    cin >> N >> M;
    E.resize(N+1);
    in.resize(N+1);
    out.resize(N+1);
    for(int i = 1; i<=N; ++i){
        ll p;
        cin >> p;
        if(p == -1) continue;
        E[p].push_back(i);
    }

    DFS(1);

    while(M--){
        ll q, idx, val;
        cin >> q >> idx;

        ll l = in[idx] , r = out[idx];
        if(q == 1){
            cin >> val;
            update(1,0,cnt-1,l, val);
            if(r < cnt-1)
            update(1,0,cnt-1, r+1,-val);
        }
        else{
            cout << query(1,0,cnt-1,l)<<"\n";
        }
    }

    return 0;
} // Euler Tour Technique, Segment Tree