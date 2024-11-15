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

const ll MAX = 1'000'000'000'000'000'000;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    deque<ll> q;
    for(int i = 0; i<N; ++i){
        ll tmp;
        cin >> tmp;
        if(q.empty()) q.push_back(tmp);
        else{
            ll idx = lower_bound(q.begin(), q.end(), tmp) - q.begin();
            if(idx == q.size()) q.push_back(tmp);
            q[idx] = tmp;
        }
    }
    cout << q.size();
    
    
    return 0;
} // O(NlogN) LIS
