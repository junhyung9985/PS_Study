#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

pair<ll,ll> tr[400001];
ll arr[100001];

pair<ll,ll> init(ll n, ll s, ll e){
    if(s == e) return tr[n] = {arr[s], 0};
    ll mid = (s+e)/2;
    pair<ll,ll> r1 = init(2*n, s, mid);
    pair<ll,ll> r2 = init(2*n+1, mid+1, e);
    if(r1.first > r2.first){
        tr[n].first = r1.first;
        if(r1.second > r2.first) tr[n].second = r1.second;
        else tr[n].second = r2.first;
    }
    else {
        tr[n].first = r2.first;
        if(r2.second > r1.first) tr[n].second = r2.second;
        else tr[n].second = r1.first;    
    }
    return tr[n];
}

pair<ll, ll> update(ll n, ll s ,ll e, ll idx){
    if(idx <s || e < idx) return tr[n];
    if(s == e) return tr[n] = {arr[idx], 0};
    ll mid = (s+e)/2;
    pair<ll,ll> r1 = update(2*n, s, mid, idx);
    pair<ll,ll> r2 = update(2*n+1, mid+1, e, idx);
    if(r1.first > r2.first){
        tr[n].first = r1.first;
        if(r1.second > r2.first) tr[n].second = r1.second;
        else tr[n].second = r2.first;
    }
    else {
        tr[n].first = r2.first;
        if(r2.second > r1.first) tr[n].second = r2.second;
        else tr[n].second = r1.first;    
    }
    return tr[n];
}

pair<ll, ll> query(ll n ,ll s, ll e, ll l, ll r){
    if(e < l || r < s) return {0,0};
    if(l<= s && e <= r) return tr[n];

    pair<ll,ll> ret;
    ll mid = (s+e)/2;
    pair<ll,ll> r1 = query(2*n, s, mid, l, r);
    pair<ll,ll> r2 = query(2*n+1, mid+1, e, l, r);
    if(r1.first > r2.first){
        ret.first = r1.first;
        if(r1.second > r2.first) ret.second = r1.second;
        else ret.second = r2.first;
    }
    else {
        ret.first = r2.first;
        if(r2.second > r1.first) ret.second = r2.second;
        else ret.second = r1.first;    
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    for(int i =0; i<N; ++i)
        cin>> arr[i];
    
    init(1,0,N-1);
    ll Q;
    cin >> Q;
    while(Q--){
        ll q, a, b;
        cin >> q >> a >> b;
        if(q == 1){
            arr[a-1] =b;
            update(1,0,N-1,a-1);
        }
        else {
            pair<ll,ll> ret = query(1,0,N-1, a-1, b-1);
            cout << ret.first + ret.second<<"\n";
        }
    }
    
    return 0;
} // Segment Tree, find two maximum elements within a range