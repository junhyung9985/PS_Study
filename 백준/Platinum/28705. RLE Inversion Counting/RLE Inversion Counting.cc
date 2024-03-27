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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension
// Rope

ll tr[2000001];
ll arr[500000];
ll MOD = 1'000'000'007;

unordered_map<ll, ll> idx;

ll query(ll n, ll s, ll e, ll val){
    //cout << n <<" "<< val <<"\n";
    if(s > val) return tr[n];
    if(e <= val) return 0;
    ll mid = (s+e)/2;
    return (query(2*n, s, mid, val) + query(2*n+1, mid+1, e, val)) % MOD; 
}

ll update(ll n, ll s, ll e, ll index){
    if(index < s || e < index) return tr[n];
    if(s == e) return tr[n] = arr[s];
    ll mid = (s+e)/2;
    return tr[n] = (update(2*n, s, mid, index) + update(2*n+1, mid+1, e, index)) % MOD;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll M;
    ll ans = 0;
    cin >> M;
    
    set<ll> s;
    vector<pair<ll, vector<ll>>> queries(M);
        
    for(int i = 0; i < M ; ++i){
        ll N;
        cin >> queries[i].first >> N;
        for(int j = 0; j<N; ++j){
            ll tmp;
            cin >> tmp;
            queries[i].second.push_back(tmp);
            s.insert(tmp);
        }
        
    }
    
    ll cnt = 0 ;
    for(auto itr : s){
        idx[itr] = cnt++;
    }
    
    for(int i =0 ;i<M; ++i){
        ll K = queries[i].first;
        ordered_set os, os2;
        
        for(auto itr : queries[i].second){
            //cout << itr <<" ";
            ll ret = query(1,0,cnt-1, idx[itr]);
            ans += (ret * K) % MOD;
            ans %= MOD;
            ll n = os.order_of_key(-itr);
            ll n2 = os2.order_of_key(itr);
            //cout << n <<" "<<n2<<"\n";
            
            ans += (n%MOD) * ((((K * (K+1)))/2) % MOD);
            ans %= MOD;
            ans += (n2%MOD) * ((((K-1) * K) /2) % MOD);
            ans %= MOD;
            os.insert(-itr);
            os2.insert(itr);
            
        }
        
        for(auto itr : queries[i].second){
            arr[idx[itr]] += K;
            arr[idx[itr]] %= MOD;
            update(1,0,cnt-1, idx[itr]);
            
            
        }
        
    }
    cout << ans;

    return 0;
}
// Segment Tree + Value Compression