#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS
vector<ll> arr;
vector<ll> tr;
vector<ll> lazy;

void push(ll n, ll s, ll e){
    if(lazy[n] != 0){
        tr[n] += (e-s+1)*lazy[n];
        if(s != e){
            lazy[n* 2] += lazy[n];
            lazy[n * 2+1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

void update_range(ll n, ll s, ll e, ll l, ll r, ll val){
    push(n, s, e);
    if(e < l || r < s) return;
    if(s >= l && e <= r){
        lazy[n] += val;
        push(n,s,e);
        return;
    }
    ll mid = (s+e)/2;
    update_range(n*2 , s, mid, l, r, val);
    update_range(n*2+1, mid+1, e, l, r, val);
    tr[n] = tr[n*2]+tr[n*2+1];
}

ll query(ll n, ll s, ll e, ll l, ll r){
    push(n, s, e);
    if(e < l || s > r) return 0;
    if(l <= s && e <= r) return tr[n];
    ll mid = (s+e)/2;
    return query(2*n, s, mid, l, r)+query(2*n+1, mid+1, e, l, r);
}

ll init(ll n, ll s, ll e){
    if(s == e) return tr[n] = arr[s];
    ll mid = (s+e)/2;
    return tr[n] = init(n*2, s, mid)+init(n*2+1, mid+1, e);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M , K;
    cin >> N >> M >> K;
    arr.resize(N);
    tr.resize(4*N);
    lazy.resize(4*N);
    for(int i =0; i<N; i++)
        cin >> arr[i];
    
    init(1,0,N-1);
    
    for(int i =0; i<M+K; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            ll val;
            cin >> val;
            update_range(1,0,N-1, b-1,c-1, val);
        }
        else{
            cout << query(1,0,N-1, b-1,c-1)<<"\n";
        }
    }

    return 0;
}