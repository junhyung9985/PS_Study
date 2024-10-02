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
    
    ll T;
    cin >> T;
    while(T--){
        ll N;
        string s;
        cin >> N;
        cin >> s;
        
        ll ans = 0;
        bool flag = true;
        deque<ll> q;
        for(int i = 0; i<N; ++i){
            if(s[i] == 'T'){
                if(!q.empty()){
                    ll l = q.back();
                    if((i-l-1)%2 == 0) {
                        ans += i-l;
                        q.pop_back();
                    }
                    else q.push_back(i);
                }
                else q.push_back(i);
            }
        }
        if(!q.empty()) flag = false;
        if(flag) cout << ans<<"\n";
        else cout << -1<<"\n";
        
    }
    
    return 0;
} 
// Greedy, Ad_hoc, Stack