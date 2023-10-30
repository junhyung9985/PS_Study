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
ll tr[400001];

ll init(ll n, ll s, ll e){
    if(s == e) return tr[n] = arr[s];
    ll mid = (s+e)/2;
    return tr[n] = init(n*2, s, mid) + init(n*2+1, mid+1, e);
}

ll update(ll n, ll s, ll e, ll idx){
    if(idx < s || e < idx) return tr[n];
    if(s == e) return tr[n] = arr[s];
    ll mid = (s+e)/2;
    return tr[n] = update(n*2, s, mid, idx)+update(n*2+1, mid+1, e, idx);
}

ll query(ll n, ll s ,ll e, ll l, ll r){
    if(r < s || e < l) return 0;
    if( l<= s && e <= r) return tr[n];
    ll mid = (s+e)/2;
    return query(n*2, s, mid, l, r) + query(n*2+1, mid+1, e, l, r);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<pair<ll,ll>> query1; // 1st queries
    deque<tuple<ll,ll,ll,ll>> query2; // 2nd queries : {k, idx, l, r}
    
    ll N;
    cin >> N;
    for(int i =0; i<N; ++i){
        cin >> arr[i];
    }

    init(1,0,N-1);
    ll Q;
    cin >> Q;
    vector<ll> ans(Q);
    for(int i =0; i<Q; ++i){
        ll q;
        cin >> q;
        if(q == 1) {
            ans[i] = -1;
            ll idx ,v;
            cin >> idx >> v;
            query1.push_back({idx-1, v});
        }
        else {
            ll k, l, r;
            cin >> k >> l >> r;
            query2.push_back({k,i,l-1,r-1});
        }
    }
    
    sort(query2.begin(), query2.end());

    int q_idx = 0;
    while(!query2.empty()){
        ll k, idx, l, r;
        tie(k,idx,l,r) = query2.front();
        if(k == q_idx){
            query2.pop_front();
            ans[idx] = query(1,0,N-1, l, r);
        }
        else{
            ll i, v;
            tie(i,v) = query1[q_idx++];
            arr[i] = v;
            update(1,0,N-1, i);
        }
    }

    for(int i =0; i<Q; ++i){
        if(ans[i] == -1) continue;
        cout << ans[i]<<"\n";
    }

    return 0;
} // Segment Tree, Offline Queries