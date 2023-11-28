#include <bits/stdc++.h>
#define ll long long
#define INF 987654321
using namespace std;

ll arr[100001];
vector<ll> tree[400004];

void init(ll n, ll s ,ll e){
    if(s == e){
        tree[n].push_back(arr[s]);
        return;
    }
    init(2*n, s, (s+e)/2);
    init(2*n+1, (s+e)/2+1, e);
    int idx = 0, idx2 =0;
    while(idx < tree[n*2].size() && idx2 < tree[2*n+1].size()){
        if(tree[2*n][idx] < tree[2*n+1][idx2]){
            tree[n].push_back(tree[2*n][idx]);
            ++idx;
        }
        else{
            tree[n].push_back(tree[2*n+1][idx2]);
            ++idx2;
        }
    }
    
    while(idx < tree[n*2].size())
        tree[n].push_back(tree[2*n][idx++]);
        
    while(idx2 < tree[n*2+1].size())
        tree[n].push_back(tree[2*n+1][idx2++]);
    return;
}

ll query(ll n, ll s ,ll e, ll l, ll r, ll k){
    if(r < s || e < l) return 0;
    if(l <= s && e <= r){
        return upper_bound(tree[n].begin(), tree[n].end(), k)-tree[n].begin();
    }
    
    ll mid = (s+e)/2;
    return query(2*n,s,mid, l, r, k) + query(2*n+1, mid+1, e, l, r, k);
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	
	ll N, Q;
	cin >> N >> Q;
	for(int i =0; i<N;++i)
	    cin >> arr[i];
	   
	init(1,0,N-1);

	while(Q--){
	    ll s, e, k;
	    cin >> s >> e >> k;
	    --s; --e;
	    ll l = -1'000'000'001, r = 1'000'000'000;
	    while(l+1 < r){
	        ll mid = (l+r)/2;
	        ll ret = query(1,0,N-1, s, e, mid);
	        if(ret < k) l = mid;
	        else r = mid;
	    }
	    cout << r <<"\n";
	}
	
	return 0;
} // Merge-Sort Tree, Binary Search
// O(NlogN + Mlog10^9logN)