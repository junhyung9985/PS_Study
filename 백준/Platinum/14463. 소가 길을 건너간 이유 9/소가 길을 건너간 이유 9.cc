#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll arr[100001];
ll tr[400005];

ll update(ll n, ll s, ll e, ll idx){
    if(e < idx || idx < s) return tr[n];
    if(s == e) return tr[n] = arr[s];
    ll mid = (s+e)/2;
    return tr[n] = update(2*n, s, mid, idx) + update(2*n+1, mid+1, e, idx);
}

ll query(ll n, ll s, ll e, ll idx){
    if(e < idx) return 0;
    if(idx <= s) return tr[n];
    ll mid = (s+e)/2;
    return query(2*n, s, mid, idx) + query(2*n+1, mid+1, e, idx);   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    ll ans = 0;
    int idx = 0;

    cin >> N;

    vector<ll> found(N+1, -1);

    for(int i =0; i<2*N; ++i){
        ll n;
        cin >> n;
        if(found[n] == -1){
            found[n] = idx;
            arr[idx] = 1;
            update(1,0,N-1, idx);
            ++idx;
        }
        else {
            arr[found[n]] = 0;
            update(1,0,N-1, found[n]);
            ans += query(1, 0, N-1, found[n]);
            //cout << ans <<"\n";
        }
    }
    
    cout << ans;

    return 0;
} // Segment Tree, Range Sum Query
