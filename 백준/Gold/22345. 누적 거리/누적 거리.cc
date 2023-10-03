#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, Q;
    cin >> N >> Q;
    vector<ll> p(N+1);
    vector<ll> a(N+1);
    vector<pair<ll,ll>> v(N+1);
    v[0] = {INT_MIN, INT_MIN};
    for(int i =1; i<=N; ++i){
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    for(int i =1 ;i<=N; ++i){
        ll pi, ai;
        tie(pi, ai) = v[i];
        p[i] = pi*ai;
        a[i] = ai;
        if(i > 0) p[i] += p[i-1], a[i] += a[i-1];
    }

    for(int i =0; i<Q; ++i){
        ll q;
        cin>> q;
    
        ll l = 0, r = N+1;
        while(l+1 < r){
            ll mid = (l+r)/2;
            if(v[mid].first<=q){
                l = mid;
            }
            else r = mid;
        } // Binary Search

        ll ans = p[N]-p[l];
        ans += -p[l];
        ans += (-a[N]+a[l]) * q;
        ans += (a[l]) * q;
        cout << ans <<"\n";
    }


    return 0;
} // Prefix-Sum, Binary Search