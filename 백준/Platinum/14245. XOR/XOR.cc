#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int tr[2000004];
int lazy[2000004];
int arr[500000];

int init(ll n, ll s, ll e){
    if(s == e) return tr[n] = arr[s];
    ll mid = (s+e)/2;
    return tr[n] = init(n*2, s, mid) ^ init(n*2+1, mid+1, e);
}

void push(int n, int s, int e){
    
    int val = lazy[n];
    tr[n] ^= val;
    lazy[n] = 0;

    if(s != e){
        lazy[2*n] ^= val;
        lazy[2*n+1] ^= val;
    }

    return;
}

int update(ll n ,ll s, ll e, ll l, ll r, ll val){
    if(r < s || e < l) return tr[n];
    if(l <= s && e <= r){
        lazy[n] ^=  val;
        push(n, s, e);   
        return tr[n];
    }
    ll mid = (s+e)/2;

    return tr[n] = update(n*2, s, mid, l, r, val) ^ update(n*2+1, mid+1, e, l, r, val);
}

int query(ll n, ll s, ll e, ll idx){
    if(idx < s || e < idx) return 0;
    push(n, s, e);
    if(s == e) return tr[n];
    ll mid = (s+e)/2;
    return query(n*2, s, mid, idx) ^ query(n*2+1, mid+1, e, idx);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    for(int i =0; i<N; ++i)
        cin >> arr[i];
    
    init(1,0,N-1);

    ll Q;
    cin >> Q;
    while(Q--){
        ll q;
        cin >> q;
        if(q == 1){
            ll a, b, c;
            cin >> a >> b >> c;
            update(1,0,N-1,a,b,c);
        }
        else{
            ll idx;
            cin >> idx;
            cout << query(1,0,N-1, idx)<<"\n";
        }
    }

    return 0;
} // Segment Tree, Lazy Propagation