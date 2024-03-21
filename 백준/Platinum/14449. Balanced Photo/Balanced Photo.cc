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

vector<ll> arr(100001);
vector<vector<ll>> tr(400005);

void init(ll n, ll s ,ll e){
    if(s == e){
        tr[n].push_back(arr[s]);
        return;    
    }
    ll mid = (s+e)/2;
    init(2*n, s, mid);
    init(2*n+1, mid+1, e);
    
    int idx1 = 0, idx2 = 0;
    while(idx1 < tr[2*n].size() && idx2 < tr[2*n+1].size()){
        if(tr[2*n][idx1] < tr[2*n+1][idx2]){
            tr[n].push_back(tr[2*n][idx1++]);
        }
        else tr[n].push_back(tr[2*n+1][idx2++]);
    }
    
    while(idx1 < tr[2*n].size()){
        tr[n].push_back(tr[2*n][idx1++]);
    }
    
    while(idx2 < tr[2*n+1].size()){
        tr[n].push_back(tr[2*n+1][idx2++]);
    }    
    
    return;
}

ll query(ll n, ll s , ll e, ll l, ll r, ll val){
    if(r < s || e < l) return 0;
    if(l<= s && e <= r) return tr[n].size() - (upper_bound(tr[n].begin(), tr[n].end(), val) - tr[n].begin());
    ll mid = (s+e)/2;
    return query(n*2, s, mid, l, r, val) + query(n*2+1, mid+1, e, l, r, val);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    for(int i =0 ;i<N; ++i){
        cin >> arr[i];
    }
    init(1,0,N-1);
    ll ans = 0;
    for(int i =0; i<N; ++i){
        ll left = 0, right = 0;
        if(i > 0) left = query(1,0,N-1, 0, i-1, arr[i]);
        if(i < N-1) right = query(1,0,N-1, i+1,N-1, arr[i]);
        if(left > 2 * right || right > 2*left) ++ans;
        //cout << left <<" "<<right<<"\n";
    }
    cout << ans;
    
    return 0;
} // Merge Sort Tree
