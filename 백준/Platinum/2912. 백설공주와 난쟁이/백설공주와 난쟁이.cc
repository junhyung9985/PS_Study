#include <bits/stdc++.h>
#define ll long long

using namespace std;


vector<ll> arr;
vector<vector<ll>> tr;

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
    if(l<= s && e <= r) return upper_bound(tr[n].begin(), tr[n].end(), val) - tr[n].begin();
    ll mid = (s+e)/2;
    return query(n*2, s, mid, l, r, val) + query(n*2+1, mid+1, e, l, r, val);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, C;
    cin >> N >> C;
    
    arr.resize(N+1);
    tr.resize(4*N+4);
    for(int i =0; i<N; ++i)
        cin >> arr[i];
    
    init(1,0,N-1);
        
    ll Q;
    cin >> Q;
    while(Q--){
        ll l , r;
        cin >> l >> r;
        --l; -- r;
        ll tot = (r-l+1)/2+1;
        ll bef = 0;
        ll ans = 0;
        ll l1 = 0, r1 = C;
        while(l1+1 < r1){
            ll mid = (l1+r1)/2;
            ll ret = query(1,0,N-1,l, r, mid);
            if(ret >= tot) r1 = mid;
            else l1 = mid;
        }
        
        ll ret = query(1,0,N-1,l,r, r1) - query(1,0,N-1,l,r,r1-1);
        if(ret >= tot) cout <<"yes "<<r1 <<"\n";
        else cout <<"no\n";
        
    } // O(NlogN + QlogClogN)
    
    return 0;
}
/*

Merge Sort Tree, Binary Search

*/
