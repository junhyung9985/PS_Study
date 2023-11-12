#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS


ll tr[2000004];
ll arr[500001];

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
    if(s == e) return --tr[n];
    ll mid = (s+e)/2;
    return tr[n] = update(n*2, s, mid, idx)+update(n*2+1, mid+1, e, idx);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;

    vector<ll> v(N);
    vector<ll> v2(N);
    unordered_map<ll, ll> m;
    int idx = 1;
    
    for(int i =0; i<N; ++i){
        cin >> v[i];
        v2[i] = v[i];
    }
    
    sort(v2.begin(), v2.end());
    for(int i =0; i<N; ++i){
        if(m.find(v2[i]) == m.end()) m[v2[i]] = idx++;
        arr[m[v2[i]]]++;
    }
    

    init(1,0,N);
    ll ans = 0;
    for(int i =0; i<N; ++i){
        ans += query(1,0,N,m[v[i]]-1);
        //cout << ans <<"\n";
        update(1,0,N,m[v[i]]);        
    }

    cout << ans;

    return 0;
} // Segment Tree, Value Compression
// 결국에, v[i]는 inversion이 일어난 횟수만큼 움직여야 한다!