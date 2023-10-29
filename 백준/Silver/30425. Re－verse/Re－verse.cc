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
    string s;
    cin >> N >> s;
    ll ans = 0;
    int idx = 0;

    for(int i =0; i<N; ++i){
        bool flag = true;
        for(int j =0; j<N; ++j){
            if(i+j == s.size()) break;
            flag = flag && (s[i+j] == s[j]);
        }
        if(flag) {
            ++ ans;
            s = s.substr(0,i) + s;
        }
    }

    cout << ans <<"\n";

    return 0;
}