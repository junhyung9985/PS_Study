#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<vector<ll>> tr;
vector<ll> arr;

void init(ll n, ll s, ll e){
    if(s == e) {
        tr[n].push_back(arr[s]);
        return;
    }
    ll mid = (s+e)/2;
    init(n*2, s, mid);
    init(n*2+1, mid+1, e);
    int i_left = 0, i_right = 0;
    while(i_left <  tr[2*n].size() && i_right< tr[2*n+1].size()){
        if(tr[2*n][i_left] <= tr[2*n+1][i_right]){
            tr[n].push_back(tr[2*n][i_left++]);
        }
        else tr[n].push_back(tr[2*n+1][i_right++]);
    }
    if(i_left == tr[2*n].size()){
        while(i_right < tr[2*n+1].size()){
            tr[n].push_back(tr[2*n+1][i_right++]);
        }
    }
    else {
        while(i_left < tr[2*n].size()){
            tr[n].push_back(tr[2*n][i_left++]);
        }
    }
    return;
}

ll query(ll n, ll s, ll e, ll l, ll r, ll val){
    if(e < l || r < s) return 0;
    if(l <= s && e <= r) {
        ll idx = (upper_bound(tr[n].begin(), tr[n].end(), val)-tr[n].begin());
        return tr[n].size() - idx;   
    }
    ll mid = (s+e)/2;
    return query(2*n, s,mid, l,r,val) + query(2*n+1, mid+1, e, l, r, val);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, Q;
    cin >> N;
    arr.resize(N);
    tr.resize(4*N);
    
    for(int i =0; i<N; i++)
        cin >> arr[i];
    
    init(1,0,N-1);

    cin >> Q;
    ll last_ans = 0;
    for(int i =0; i<Q; i++){
        ll a , b, c;
        cin >> a >> b >> c;
        a ^= last_ans;
        b ^= last_ans;
        c ^= last_ans;
        last_ans = query(1,0,N-1,a-1,b-1,c);
        cout << last_ans <<"\n";
    }

    return 0;
}
/*

Merge Sort Tree, Segment Tree

*/