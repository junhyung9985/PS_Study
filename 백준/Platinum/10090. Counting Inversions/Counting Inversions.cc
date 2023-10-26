#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS


ll tr[4000004];
ll arr[1000001];

ll init(ll n, ll s, ll e){
    if(s == e) return tr[n] = arr[s];
    ll mid = (s+e)/2;
    return tr[n] = init(n*2, s, mid)+init(n*2+1, mid+1,e);
}

ll query(ll n, ll s, ll e, ll idx){
    if(idx < s) return 0;
    if(idx >= e) return tr[n];
    ll mid = (s+e)/2;
    return query(n*2, s, mid, idx)+query(n*2+1, mid+1, e, idx);
}

ll update(ll n, ll s, ll e, ll idx){
    if(idx < s || idx > e) return tr[n];
    if(s == e) return tr[n] = 0;
    ll mid = (s+e)/2;
    return tr[n] = update(n*2, s, mid, idx)+update(n*2+1, mid+1, e, idx);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;

    vector<ll> v(N);

    for(int i =0; i<N; ++i){
        cin >> v[i];
        arr[i+1] = 1;
    }

    init(1,0,N);
    ll ans = 0;
    for(int i =0; i<N; ++i){
        ans += query(1,0,N,v[i]-1);
        //cout << ans <<"\n";
        update(1,0,N,v[i]);        
    }

    cout << ans;

    return 0;
} // Segment Tree
// 아니면 Merge sort tree를 활용해서 쿼리 구간에 대해서 작은 값들을 구한다?