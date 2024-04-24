//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
// Compiler Optimization Options

#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension
// Rope

#define mid (s+e)/2

ll tr[4000005];
ll arr[1000001];

ll update(ll n, ll s, ll e, ll idx){
    if(idx < s || e < idx) return tr[n];
    if(s == e) return tr[n] = arr[s] % 1000;
    return tr[n] = (update(2*n, s, mid, idx) + update(2*n+1, mid+1, e, idx)) % 1000;
}

ll query(ll n ,ll s, ll e, ll l, ll r){
    if(r < s || e < l) return 0;
    if(l <= s && e <= r) return tr[n];
    return (query(2*n, s, mid, l , r) + query(2*n+1, mid+1, e, l, r)) % 1000;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, d, N;
    cin >> a >> b >> d >> N;
    arr[0] = 1;
    update(1,0,N,0);
    for(ll i =1; i<=N; ++i){
        ll l = i-b+1;
        ll r = i-a;
        arr[i] = query(1,0,N,l,r);
        update(1,0,N,i);
    }
    
    cout << query(1,0,N,N-d+1,N);
    
    return 0;
} // Segment Tree, DP 
// 아마 정해는 Sweeping + DP 였을 듯?