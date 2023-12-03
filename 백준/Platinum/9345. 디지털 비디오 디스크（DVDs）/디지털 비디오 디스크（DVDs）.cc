#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<pair<ll,ll>> tr; // max-min segtree
vector<ll> arr;
pair<ll, ll> init(ll n ,ll s ,ll e){
    if(s == e) return tr[n] = {arr[s],arr[s]};
    auto itr1 = init(2*n, s, (s+e)/2), itr2 = init(2*n+1, (s+e)/2+1, e);
    return tr[n] = {max(itr1.first, itr2.first), min(itr1.second, itr2.second)};
}

pair<ll, ll> update(ll n, ll s, ll e, ll idx){
    if(e < idx || idx < s) return tr[n];
    if(s == e) return tr[n] = {arr[idx], arr[idx]};
    auto itr1 = update(2*n, s, (s+e)/2, idx), itr2 = update(2*n+1, (s+e)/2+1, e, idx);
    return tr[n] = {max(itr1.first, itr2.first), min(itr1.second, itr2.second)};
}

pair<ll, ll> query(ll n, ll s, ll e ,ll l, ll r){
    if(e < l || r < s) return {INT_MIN, INT_MAX};
    if(l <= s && e <= r) return tr[n];
    auto itr1 = query(2*n,s,(s+e)/2,l,r), itr2 = query(2*n+1,(s+e)/2+1,e,l,r);
    return {max(itr1.first, itr2.first), min(itr1.second, itr2.second)};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T;
    cin >> T;
    while(T--){
        ll N, Q;
        cin >> N >> Q;
        tr.resize(4*N);
        arr.resize(N);
        for(int i =0; i<N; ++i)
            arr[i] = i;

        init(1,0,N-1);
        while(Q--){
            ll q, a, b;
            cin >> q >> a >> b;
            if(q == 0){
                ll tmp = arr[b];
                arr[b] = arr[a];
                arr[a] = tmp;
                update(1,0,N-1, a);
                update(1,0,N-1, b);
            }
            else{
                ll maxx, minn;
                tie(maxx, minn) = query(1,0,N-1,a,b);
                if(maxx == b && minn == a) cout <<"YES\n";
                else cout <<"NO\n";
            }
        }

    }

    return 0;
} // Min-Max Segment Tree
// 아이디어 -> 어차피 구간내의 최댓값이 b, 최솟값이 a라면 다 있는거다 ㅇㅇ