//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
// Compiler Optimization Options

#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension
// Rope

const ll MAX = 1'000'000'000'000'000'000;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T;
    cin >> T;
    while(T--){
        ll N, s, t;
        cin >> N >> s >> t;
        ll ans = 0;
        ll curr = 0;
        
        vector<ll> v;
        while(N){
            v.push_back(N%2);
            N/=2;
        }
        reverse(v.begin(), v.end());
        
        for(int i = 0; i<v.size(); ++i){
            ans += min(curr * s, t);
            curr *= 2;
            if(v[i] == 1) ans += s;
            curr += v[i];
        }
        
        cout << ans <<"\n";
    }    
    return 0;
} // Greedy, Bitmasking