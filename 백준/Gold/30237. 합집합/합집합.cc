#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll arr[101];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        vector<ll> v(N,0);
        ll cannot = 0;
        for(int i =0; i<N; ++i){
            ll c;
            cin >> c;
            for(int j =0; j<c; ++j){
                ll a;
                cin >> a;
                v[i]= v[i] | ((ll)1<<a);
            }
            cannot = cannot | v[i];
        }    

        ll ans = 0;
        int idx = 0;
        while(cannot){
            if(cannot%2){
                ll tmp = 0;
                ll cmp = ((ll)1 << idx);
                for(int i =0; i<N; ++i){
                    if(cmp & v[i]) continue;
                    tmp |= v[i];
                }
                ll tmp_ans = 0;
                while(tmp){
                    tmp_ans += tmp%2;
                    tmp/=2;
                }
                ans = max(ans, tmp_ans);
            }
            ++idx;
            cannot /= 2;
        }

        cout << ans<<"\n";
    }

    return 0;
} // Bitmasking, Ad_hoc