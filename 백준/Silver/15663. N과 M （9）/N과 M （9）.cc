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

ll N, M;
int is_found[8];
set<vector<ll>> s;
vector<ll> v;
vector<ll> curr;
void backtrack(ll n, ll cnt){
    if(cnt == M){
        s.insert(curr);
        return;
    }
    for(int i = 0; i<N; ++i){
        if(is_found[i]) continue;
        is_found[i] = 1;
        curr.push_back(v[i]);
        backtrack(i, cnt+1);
        curr.pop_back();
        is_found[i] = 0;
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    v.resize(N);
    for(int i = 0; i<N; ++i) cin >> v[i];
    backtrack(-1, 0);
    for(auto itr : s){
        for(auto itr2 : itr) cout << itr2<<" ";
        cout<<"\n";
    }
    
    return 0;
}