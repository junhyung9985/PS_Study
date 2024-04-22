//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
// Compiler Optimization Options

#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension
// Rope


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    
    map<ll,ll> m;
    for(int i =0; i<N; ++i){
        ll tmp;
        cin >> tmp;
        while(tmp%2 == 0) tmp/=2;
        if(m.find(tmp) == m.end()) m[tmp] = 0;
        ++m[tmp];
    }
    
    ll ans = 0;
    for(auto itr : m)
        ans = max(ans, itr.second);
    cout << ans;
    
    return 0;
} // Greedy + Sorting