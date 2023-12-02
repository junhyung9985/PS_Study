#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

ll tree[400004];
ll lazy[400004];

void push(ll n, ll s, ll e){
    if(lazy[n]%2){
        tree[n] = (e-s+1)-tree[n];
    }
    if(s != e){
        lazy[2*n] += lazy[n];
        lazy[2*n+1] += lazy[n];
    }
    lazy[n] = 0;
}

ll update(ll n, ll s ,ll e, ll l, ll r){
    if(lazy[n]) push(n, s, e);
    if(e < l || r < s) return tree[n];
    if(l <= s && e <= r){
        ++lazy[n];
        push(n, s, e);
        return tree[n];
    }
    return tree[n] = update(2*n,s,(s+e)/2, l, r) + update(2*n+1, (s+e)/2+1, e, l, r);
}

ll query(ll n, ll s, ll e, ll l, ll r){
    if(lazy[n]) push(n,s,e);
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) return tree[n];
    return query(2*n,s,(s+e)/2, l, r) + query(2*n+1, (s+e)/2+1, e, l, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q;
    cin >> N >> Q;
    while(Q--){
        ll q, l, r;
        cin >> q >> l >> r;
        --l; --r;
        if(q == 0){
            update(1,0,N-1, l, r);
        }
        else {
            cout << query(1,0,N-1,l,r)<<"\n";
        }
    }

    return 0;
} // Segment Tree