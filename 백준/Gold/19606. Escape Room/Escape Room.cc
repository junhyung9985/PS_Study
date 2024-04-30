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
    
    ll N, M;
    
    cin >> N >> M;
    
    vector<vector<ll>> v(N+1, vector<ll>(M+1));
    vector<vector<pair<ll,ll>>> E(1'000'001);
    
    for(int i =1; i<=N; ++i)
        for(int j =1 ; j<=M; ++j){
            cin >> v[i][j];
            E[i*j].push_back({i,j});
        }
    
    vector<bool> covered(1'000'001, false);
    
    deque<pair<ll,ll>> q;
    q.push_back({1,1});
    
    while(!q.empty()){
        ll y, x;
        tie(y, x) = q.front();
        q.pop_front();
        ll val  = v[y][x];
        if(covered[val]) continue;
        covered[val] = true;
        if(val == N * M) break;
        for(auto itr : E[val]){
            q.push_back({itr.first, itr.second});
        }
    }    
    if(covered[N*M]) cout <<"yes";
    else cout <<"no";
    
    return 0;
} // BFS
