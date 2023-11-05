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

    vector<ll> v(N);
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    ll bef = 0;
    ll ans = 0;
    ll cnt = 0;
    for(int i : v){
        if(bef != i) {
            ++ans;
            cnt = 0;
        }
        else {
            if(cnt < 1){
                ++ans;
            }
            cnt = 1;
        }
        bef = i;
    }
    cout << ans;

    return 0;
} // Sorting, Greedy(?)