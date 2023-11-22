#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ordered_set ms;
    ll N, M;
    cin >> N >> M;

    vector<ll> curr(N+1);
    for(int i =1; i<=N; ++i){
        cin >> curr[i];
        ms.insert(curr[i]);
    }

    while(M--){

        ll q;
        cin >> q;
        if(q == 1){
            ll i, x;
            cin >> i >> x;
            auto itr = ms.find_by_order(ms.order_of_key(curr[i]));
            ms.erase(itr);
            ms.insert(curr[i]+x);
            curr[i] += x;
        }
        else if(q == 2){
            ll i, y;
            cin >> i >> y;
            auto itr = ms.find_by_order(ms.order_of_key(curr[i]));
            ms.erase(itr);
            ms.insert(curr[i]-y);
            curr[i] -= y;
        }
        else if (q == 3){
            ll l, r;
            cin >> l >> r;
            ll cnt = ms.order_of_key(r+1) - ms.order_of_key(l);
            cout << cnt <<"\n";
        }
        else {
            ll t;
            cin >> t;
            auto itr = ms.find_by_order(N-t); 
            cout << *itr <<"\n";
        }
    }

    return 0;
} // PBDS
// Segment Tree + Coordination Compression + Binary Search, Offline Query가 정해 였을 듯...