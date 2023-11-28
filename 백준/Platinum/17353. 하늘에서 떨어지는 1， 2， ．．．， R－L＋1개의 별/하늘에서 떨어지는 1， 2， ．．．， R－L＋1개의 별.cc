#include <bits/stdc++.h>
#define ll long long
#define INF 987654321
using namespace std;

ll org[100001];
ll tree[400004];
ll lazy[400004];


void push(ll n, ll s, ll e){
    tree[n] += (e-s+1) * lazy[n];
    if(s != e){
        lazy[2*n] += lazy[n];
        lazy[2*n+1] += lazy[n];
    }
    lazy[n] = 0;
}

ll update(ll n, ll s ,ll e, ll l, ll r){
    if(lazy[n]) push(n, s, e);
    if(r < s || e < l) return tree[n];
    if(l <= s && e <= r){
        ++lazy[n];
        push(n, s, e);
        return tree[n];
    }
    ll mid = (s+e)/2;
    return tree[n] = update(2*n, s, mid, l, r) + update(2*n+1, mid+1, e, l, r);
}

ll update2(ll n, ll s, ll e, ll idx, ll val){
    if(lazy[n]) push(n, s, e);
    if(e < idx || idx < s) return tree[n];
    if(s == e) return tree[n] += val;
    ll mid = (s+e)/2;
    return tree[n] = update2(n*2, s, mid, idx, val) + update2(n*2+1, mid+1, e, idx, val);
}

ll query(ll n, ll s, ll e, ll x){
    if(lazy[n]) push(n, s, e);
    if(e <= x) return tree[n];
    if(x < s) return 0;
    ll mid = (s+e)/2;
    return query(2*n, s, mid, x) + query(2*n+1, mid+1, e, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll N, Q;
	cin >> N;
	for(int i =0; i<N; ++i)
	    cin >> org[i];
	
	cin >> Q;
	while(Q--){
	    ll q;
	    cin >> q;
	    if(q == 1){
	        ll l, r;
	        cin >> l >> r;
	        update(1,0,N-1,l-1,r-1);
	        if(r < N){
	            update2(1,0,N-1,r, l-r-1);
	        }
	    }
	    else{
	        ll x;
	        cin >> x;
	        cout << query(1,0,N-1,x-1) + org[x-1]<<"\n";
	    }
	}

	return 0;
} // Segment Tree, Lazy Propagation, Difference Array
// 수열과 쿼리 21번 비슷하게 풀 수 있음!