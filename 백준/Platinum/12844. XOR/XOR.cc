#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[500000];
ll tree[2000000];
ll lazy[2000000];

void push(ll n, ll s, ll e){
    if((e-s)%2 == 0)
        tree[n] ^= lazy[n];
    if(s != e){
        lazy[2*n] ^= lazy[n];
        lazy[2*n+1] ^= lazy[n];
    }
    lazy[n] = 0;
    return;
}

ll update(ll n, ll s, ll e, ll l, ll r , ll k){
    if(lazy[n] != 0){
        push(n, s, e);
    }
    if(e < l || r < s) return tree[n];
    if(l <= s && e <= r){
        //cout << s << " "<< e << " "<<tree[n]<<" ";
        lazy[n] ^= k;
        push(n, s, e);
        //cout<<tree[n]<<"\n";
        return tree[n];
    }
    return tree[n] = update(2*n, s, (s+e)/2, l, r, k) ^ update(2*n+1, (s+e)/2+1,e, l, r, k);
}

ll query(ll n, ll s, ll e, ll l ,ll r){
    if(lazy[n] != 0) push(n, s, e);
    if(e < l || r < s) return 0;
    if(l <= s && e <= r){
        return tree[n];
    }
    return query(2*n, s, (s+e)/2, l, r) ^ query(2*n+1, (s+e)/2+1, e, l, r);
}


ll init(ll n, ll s, ll e){
    if(s == e){
        return tree[n] = arr[s];
    }
    return tree[n] = init(2*n, s, (s+e)/2) ^ init(2*n+1, (s+e)/2+1, e);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N;
    for(int i =0; i<N; ++i){
        cin >> arr[i];
    }
    
    init(1,0,N-1);
    
    cin >> M;
    while(M--){
        ll cmd ;
        cin >> cmd;
        if(cmd == 1){
            ll l, r, k;
            cin >> l >> r >> k;
            update(1,0,N-1, l, r, k);
        }
        else {
            ll l ,r;
            cin >> l >> r;
            cout << query(1,0,N-1,l,r)<<"\n";
        }
    }
    
    return 0;
} // lazy propagation + segment tree