#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

ll tree[800008];
ll tree2[800008];
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

ll update2(ll n, ll s ,ll e, ll idx, ll w){
    if(e < idx || idx < s) return tree2[n];
    if(s == e){
        return tree2[n] += w;
    }
    return tree2[n] = update2(2*n,s,(s+e)/2, idx, w) + update2(2*n+1, (s+e)/2+1, e, idx, w);
}

ll query(ll n, ll s, ll e, ll l, ll r){
    if(r < s ||  e < l) return 0;
    if(l <= s && e <= r) return tree[n];
    return query(2*n,s,(s+e)/2, l, r) + query(2*n+1, (s+e)/2+1, e, l, r);
}

ll query2(ll n, ll s, ll e, ll l, ll r){
    if(r < s ||  e < l) return 0;
    if(l <= s && e <= r) return tree2[n];
    return query2(2*n,s,(s+e)/2, l, r) + query2(2*n+1, (s+e)/2+1, e, l, r);
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
    
    int flag = 1;
    while(Q--){
        ll q, i;
        cin >> q;
        if(q == 1){
            ll w;
            cin >> i;
            cin >> w;
            if(!flag) update(1, 0, idx, b[i], w);
            else {
                update2(1,0,idx, b[i], w);
                update2(1,0,idx, e[i]+1, -w);
            }
        }
        else if( q== 3){
            flag=  1 - flag;
        }
        else {
            cin >> i;
            cout << query(1,0,idx, b[i], e[i]) + query2(1,0,idx, 0, b[i])<<"\n";
        }
    }

    return 0;
} // Segment Tree, Euler Tour