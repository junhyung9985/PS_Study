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
    
    set<ll> s;
    vector<ll> a(100001);
    a[0] = 0;
    s.insert(0);
    for(int i =1; i<100001; ++i){
        a[i] = (a[i-1]-i);
        if(a[i] < 0 || s.find(a[i]) != s.end()) a[i] = (a[i-1] + i);
        s.insert(a[i]);
    }
    cout << a[N];
    
    return 0;
    
    
} // arithmetic, implementation