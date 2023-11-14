#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll tr[800008];
ll arr[200002];

ll update(ll n, ll s ,ll e, ll idx){
    if(idx < s || idx > e) return tr[n];
    if(s == e) return tr[n] = arr[idx];
    ll mid = (s+e)/2;
    return tr[n] = update(2*n, s, mid, idx) + update(2*n+1, mid+1, e, idx);
}

ll query(ll n ,ll s, ll e, ll l, ll r){
    if(e < l|| r < s) return 0;
    if(l<=s && e <= r) return tr[n];
    ll mid = (s+e)/2;
    return query(2*n, s, mid, l, r) + query(2*n+1, mid+1, e, l, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    set<string> s;
    vector<tuple<ll,string,ll,string>> queries(N);
    for(int i =0; i<N; ++i){
        ll q;
        cin >> q;
        if(q == 1){
            string key;
            ll val;
            cin >> key >> val;
            while(key.size() <=105){
                key = '0'+key;
            }
            queries[i] = {q,key, val, key};
            s.insert(key);
        }
        if(q == 2){
            string key1, key2;
            cin >> key1 >> key2;
            while(key1.size() <=105){
                key1 = '0'+key1;
            }
            while(key2.size() <=105){
                key2 = '0'+key2;
            }
            queries[i] = {q, key1, 0, key2};
            s.insert(key1);
            s.insert(key2);
        }
        if(q == 3){
            string key;
            string tmp = "";
            cin >> key;
            while(key.size() <=105){
                key = '0'+key;
            }
            queries[i] = {q,key, 0, key};
            s.insert(key);
        }
    } // Offline Query

    ll t_idx = 0;
    map<string,ll> m;
    for(auto itr : s){
        //cout << itr<<"\n";
        m[itr] = t_idx++;
    } // Coordinate Compression

    for(int i =0; i<N; ++i){
        ll q, val, idx, idx2;
        string k1, k2;
        tie(q,k1,val,k2) = queries[i];
        if(q == 1){
            idx = m[k1];
            arr[idx] += val;
            update(1,0,t_idx-1, idx);
            cout << tr[1]<<" ";
        }
        if(q == 2){
            idx = m[k1];
            idx2 = m[k2];
            cout << query(1,0,t_idx-1, idx, idx2)<<" ";
        }
        if(q == 3){
            idx = m[k1];
            arr[idx] = 0;
            update(1,0,t_idx-1, idx);
            cout << tr[1]<<" ";
        }

    } // Segment Tree

    return 0;
} // Offline Query, Coordinate Compression, Segment Tree, Tree_Set/Map