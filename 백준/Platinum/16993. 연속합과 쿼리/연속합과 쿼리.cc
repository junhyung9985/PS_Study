#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS


struct node{
    ll g, l, r, s;
    node operator+(node b){
        return {max(max(b.g, g), r+b.l), max(l, s+b.l), max(r+b.s, b.r), s+b.s};
    }
};

node tr[400004];
ll arr[100001];

node init(ll n, ll s, ll e){
    if(s == e){
        return tr[n] = {arr[s], arr[s], arr[s], arr[s]};   
    }
    ll mid = (s+e)/2;
    return tr[n] = init(2*n, s, mid) + init(2*n+1, mid+1, e);
}

node query(ll n, ll s, ll e, ll l, ll r){
    if(r < s || e < l) return {INT_MIN,INT_MIN, INT_MIN, INT_MIN};
    if(l <= s && e <= r) return tr[n];
    ll mid = (s+e)/2;
    return query(2*n, s, mid, l, r)+query(2*n+1, mid+1, e, l, r);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    for(int i =0; i<N; ++i){
        cin >> arr[i];
    }
    init(1,0,N-1);

    ll Q;
    cin >> Q;
    while(Q--){
        ll l , r;
        cin >> l >> r;
        cout<<query(1,0,N-1, l-1, r-1).g<<"\n";
    }

    return 0;
} // Prefix Sum, Segtree
// https://usaco.guide/plat/segtree-ext?lang=cpp#solution---subarray-sum-queries
// 좀 더 공부해봐야 감이 올듯;;