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
    
    ll N, Q;
    cin >> N >> Q;
    
    ll r = 0, c = 0;
    ll bef = 0;
    vector<pair<char, ll>> query;
    
    for(int i = 0; i<Q; ++i){
        ll n;
        cin >> n;
        if(bef + N - 2*c == n && r < N){
            query.push_back({'R',++r});
        }
        else if(bef + 2*c-N == n && r> 0){
            query.push_back({'R', r--});
        }
        else if(bef + N - 2*r == n && c < N){
            query.push_back({'C', ++c});
        }
        else if(bef + 2*r-N == n && c > 0){
            query.push_back({'C', c--});
        }
        else {
            cout << -1;
            return 0;
        }
        bef = n;
    }
    for(auto itr : query){
        cout << itr.first <<" "<<itr.second<<"\n";
    }
    
    return 0;
} 
// Greedy, Ad_hoc