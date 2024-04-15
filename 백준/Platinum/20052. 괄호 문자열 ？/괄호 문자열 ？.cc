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
ll tr[400001];
ll arr[100000];

ll query(ll n, ll s, ll e, ll l, ll r){
    if(r < s || e < l) return INT_MAX;
    if(l <= s && e <= r) return tr[n];
    return min(query(2*n, s, (s+e)/2, l, r),query(2*n+1, (s+e)/2+1, e, l, r));
}

ll init(ll n, ll s, ll e){
    if(s == e) return tr[n] = arr[s];
    return tr[n] = min(init(2*n, s, (s+e)/2), init(2*n+1, (s+e)/2+1, e));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    ll N = s.size();
    for(int i =0; i<N; ++i){
        if(s[i] == '(') arr[i] = 1;
        else arr[i] = -1;
        if(i > 0) arr[i] += arr[i-1];
    }
    init(1,0,N-1);
    
    ll Q;
    ll ans = 0;
    cin >> Q;
    while(Q--){
        ll l, r;
        cin >> l >> r;
        ll ret = query(1,0,N-1,l-1,r-1);
        ll range = arr[r-1];
        if(l > 1) ret -= arr[l-2], range-=arr[l-2];
        if(ret >= 0 && range == 0) ++ans;
        //cout << ans <<"\n";
    }
    cout << ans;
    return 0;
} // Prefix Sum + Segment Tree