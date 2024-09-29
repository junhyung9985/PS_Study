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

ll dist(pair<ll,ll> a, pair<ll,ll>b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) *(a.second - b.second);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, K, T;
    cin >> N >> K >> T;
    
    vector<pair<ll,ll>> coords(N+1);
    vector<ll> ver(N+1);
    vector<ll> has_pic(N+1);
    vector<vector<ll>> E(N+1);
    
    cin >> coords[0].first >> coords[0].second >> ver[0];
    for(int i =1; i<=N; ++i){
        cin >> coords[i].first >> coords[i].second >> ver[i] >> has_pic[i];
    }
    
    for(int i = 0; i<=N; ++i){
        for(int j =i+1; j<=N; ++j){
            ll diff =  dist(coords[i], coords[j]);
            ll ver_diff = abs(ver[i] - ver[j]);
            if(diff <= K * K && ver_diff <= T){
                E[i].push_back(j);
                E[j].push_back(i);
            }
        }
    }
    
    vector<bool> visited(N+1, false);
    deque<ll> q;
    q.push_back(0);
    visited[0] = true;
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        for(auto itr : E[n]){
            if(visited[itr]) continue;
            visited[itr] = true;
            q.push_back(itr);
        }
    }
    bool flag = true;
    for(int i =1 ;i<=N; ++i){
        if(visited[i] && has_pic[i]) {
            cout << i <<" ";
            flag = false;
        }
    }
    if(flag) cout << 0;
    return 0;
    
    
} // BFS, Geometry, Math