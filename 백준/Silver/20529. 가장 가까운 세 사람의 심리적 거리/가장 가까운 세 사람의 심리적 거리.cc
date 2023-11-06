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

    ll T;
    cin >> T;
    while(T--){
        unordered_map<string, ll> cnt;
        vector<string> v;
        ll N;
        cin >> N;
        for(int i =0; i<N; ++i){
            string tmp;
            cin >> tmp;
            if(cnt[tmp] == 3) continue;
            cnt[tmp]++;
            v.push_back(tmp);
        }

        ll n = v.size();
        ll ans = INT_MAX;
        for(int i =0; i<n; ++i){
            for(int j =i+1; j<n; ++j){
                for(int k =j+1; k<n; ++k){
                    string a = v[i], b = v[j], c =v[k];
                    ll tmp = 0;
                    for(int l =0; l<4; ++l){
                        tmp += (a[l] != b[l]);
                        tmp += (b[l] != c[l]);
                        tmp += (c[l] != a[l]);
                    }
                    ans = min(ans, tmp);
                }
            }
        }
        cout << ans<<"\n";
    }

    return 0;
} // Bruteforcing, Hash_Map