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

ll N;
vector<ll> val;

bool solve(ll n){
    vector<bool> able(N);
    able[0] = true;
    for(int i = 0; i<N; ++i){
        if(!able[i]) continue;
        for(int j =i+1; j<N; ++j){
            ll cost = (j-i) * (1+abs(val[j]-val[i]));
            if(cost <= n) able[j] = true;
        }
    }
    return able[N-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    val.resize(N);

    for(int i = 0; i<N; ++i)
        cin >> val[i];
        
    ll l = 0, r = 1'000'000'000'000'000;
    while(l+1 < r){
        ll mid = (l+r)/2;
        if(solve(mid)) r = mid;
        else l = mid;
    }
    cout << r;
    
    return 0;
} // Parametric Search