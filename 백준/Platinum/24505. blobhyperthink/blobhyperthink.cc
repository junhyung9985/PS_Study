#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll MOD = 1'000'000'007;
ll tr[11][400004];

ll query(ll n, ll s, ll e, ll which, ll idx){
    if(idx < s) return 0;
    if(e <= idx) return tr[which][n];
    return (query(n*2, s, (s+e)/2, which, idx) + query(n*2+1, (s+e)/2+1,e, which, idx)) % MOD;
}

ll update(ll n, ll s, ll e, ll which, ll idx, ll val){
    if(idx < s || idx > e) return tr[which][n];
    if(s == e) return tr[which][n] = (tr[which][n] + val)%MOD;
    return tr[which][n] = (update(n*2, s, (s+e)/2, which, idx, val) + update(n*2+1, (s+e)/2+1, e, which, idx, val))%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<deque<ll>> v(N+1);
    for(int i =0;i <N;++i){
        ll tmp;
        cin >> tmp;
        v[tmp].push_front(i+1);
    }
    
    
    ll ans = 0;
    for(int j =1; j<=N; ++j){
        
        for(auto idx : v[j]){
            for(int i =1; i<=9; ++i){
                ll ret = query(1,0,N, i-1, idx-1);
                update(1,0,N, i, idx, ret);
                //cout << idx <<" "<<i << " "<<ret <<"\n";
            }
            ll ret = query(1,0,N, 9, idx-1);
            //cout << idx <<" "<<10 << " "<<ret <<"\n";
            ans += ret;
            ans %= MOD;
        }
        for(auto idx : v[j]){
            update(1,0,N,0, idx, 1);
        }
    }
    cout << ans;    
    return 0;
} // Segment Tree O(11NlogN)