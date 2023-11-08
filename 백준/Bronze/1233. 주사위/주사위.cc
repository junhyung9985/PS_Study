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

    ll a, b, c;
    map<ll, ll> m;
    cin >> a >> b >> c;
    
    for(int i =1; i<=a; ++i){
        for(int j =1; j<=b; ++j){
            for(int k=1; k<=c; ++k){
                m[i+j+k]++;
            }
        }
    }
    ll maxx = 0, idx = 0;
    for(auto itr : m){
        if(maxx < itr.second){
            idx = itr.first;
            maxx = itr.second;
        }
    }

    cout << idx;

    return 0;
} // Bruteforcing, Tree Map