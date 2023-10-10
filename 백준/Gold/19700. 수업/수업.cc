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

    ll N;
    cin >> N;
    
    vector<pair<ll,ll>> v(N);
    multiset<ll> ms;
    for(int i =0; i<N; ++i){
        cin >> v[i].first >> v[i].second;
        ms.insert(0);
    }
    sort(v.begin(), v.end(), greater<pair<ll,ll>>());

    for(int i =0; i<N; ++i){
        ll a, b;
        tie(a,b) = v[i];
        auto itr = ms.upper_bound(-b);
        ll val = *itr;
        ms.erase(itr);
        ms.insert(val-1);
    }

    ll ans = 0;
    for(auto itr : ms){
        if(itr != 0) ++ans;
    }
    cout << ans;

    return 0;
} // Greedy, Set, Binary Search
// 이거 근데 증명을 어케 해야하나...