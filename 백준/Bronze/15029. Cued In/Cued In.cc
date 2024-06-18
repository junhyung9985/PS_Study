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
    ll reds = 0, maxx = 0;
    vector<ll> scores(8);
    
    for(int i =0; i<N; ++i){
        string s;
        cin >> s;
        if(s == "red") ++reds;
        if(s == "yellow") ++scores[2];
        if(s == "green") ++scores[3];
        if(s == "brown") ++scores[4];
        if(s == "blue") ++scores[5];
        if(s == "pink") ++scores[6];
        if(s == "black") ++scores[7];
    }
    ll sum = 0;
    for(int i = 2; i <8; ++i){
        if(scores[i]){
            maxx = i;
        }
        sum += scores[i] * i;
    }
    if(maxx == 0) reds = 1;
    sum += (maxx+1) * reds;
    cout << sum;
    
    return 0;
} // Math + Greedy + Case-working