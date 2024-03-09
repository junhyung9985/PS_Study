#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll arr[100001];
ll tr[400004];

ll init(ll n, ll s, ll e){
    if(s == e) return tr[n] = arr[s];
    return tr[n] = init(2*n, s, (s+e)/2) + init(2*n+1, (s+e)/2+1, e);
}

ll query(ll n, ll s, ll e, ll l, ll r){
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) return tr[n];
    return query(2*n, s, (s+e)/2, l, r) + query(2*n+1, (s+e)/2+1, e,l,r);
}

ll update(ll n, ll s, ll e, ll idx){
    if(idx < s || idx > e) return tr[n];
    if(s == e) return tr[n] = arr[s];
    return tr[n] = update(2*n, s, (s+e)/2, idx) + update(2*n+1, (s+e)/2+1, e, idx);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q;
    cin >> N >> Q;
    for(int i =0; i<N; ++i){
        cin >> arr[i];
    }
    init(1,0,N-1);
    
    while(Q--){
        ll x,y,a,b;
        cin >> x >> y >> a >> b;
        if(y < x) swap(x,y);
        cout << query(1,0,N-1,x-1,y-1)<<"\n";
        arr[a-1] = b;
        update(1,0,N-1, a-1);
    }
    
    return 0;
} // Segment Tree