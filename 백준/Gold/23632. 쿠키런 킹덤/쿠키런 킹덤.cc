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
    
    ll N, M, T;
    cin >> N >> M >> T;
    
    vector<bool> able_to_reach(N+1, false);
    vector<vector<ll>> make(N+1, vector<ll>());
    vector<vector<ll>> need(N+1, vector<ll>());

    vector<ll> dist(N+1, INT_MAX);
    vector<ll> ind(N+1, 0);

    deque<ll> q;
    
    for(int i =0; i<M; ++i){
        ll n;
        cin >> n;
        dist[n] = 0;
        ind[n] = 0;
        q.push_back(n);
    }
    for(int i =1; i<=N; ++i){
        ll cnt;
        cin >> cnt;
        make[i].resize(cnt);
        for(int j =0; j<cnt; ++j)
            cin >> make[i][j];
    }
    for(int j =0; j<N-M; ++j){
        ll n, cnt;
        cin >> n >> cnt;
        ind[n] = cnt;
        for(int j =0; j<cnt; ++j){
            ll tmp;
            cin >> tmp;
            need[tmp].push_back(n);
        }
    }
    
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        for(auto itr : make[n]){
            if(able_to_reach[itr]) continue;
            for(auto itr2 : need[itr]){
                --ind[itr2];
                if(ind[itr2] == 0){
                    dist[itr2] = dist[n]+1;
                    q.push_back(itr2);
                }
            }
            able_to_reach[itr] = true;
        }
    }
    
    vector<ll> ans;
    for(int i =1; i<=N; ++i)
        if(dist[i] <= T) ans.push_back(i);
    cout << ans.size()<<"\n";
    for(auto itr : ans)
        cout << itr <<" ";
    
    
    return 0;
} // Topological Sorting