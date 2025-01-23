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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension
// Rope



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T;
    cin >> T;
    for(int tc = 1; tc<=T; ++tc){
        string s;
        cin >> s;
        
        ll ans = 0;
        char curr_all = s[0];
        char bef = s[0];
        for(int i = 1; i<s.size(); ++i){
            if(s[i] == bef) continue;
            ++ans;
            bef = s[i];
            curr_all = s[i];
        }
        if(curr_all == '-')++ans;
        cout << "Case #"<<tc<<": "<<ans <<"\n";
        
    }
    
    return 0;
} // Greedy
