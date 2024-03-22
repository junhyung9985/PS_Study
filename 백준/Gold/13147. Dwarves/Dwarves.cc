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

vector<ll> E[10000];
ll ind[10000];
map<string,ll> idx;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    ll index = 0;
    
    
    for(int i = 0; i<N; ++i){
        string a, b;
        char which;
        cin >> a >> which >> b;
        if(idx.find(a) == idx.end()){
            idx[a] = index++;
        }
        if(idx.find(b) == idx.end()){
            idx[b] = index++;
        }
        if(which == '>') swap(a,b);
        E[idx[a]].push_back(idx[b]);
        ++ind[idx[b]];
    }
    
    deque<ll> q;
    for(int i =0; i<index; ++i){
        if(ind[i] == 0){
            q.push_back(i);
        }
    }
    
    while(!q.empty()){
        ll node = q.front();
        q.pop_front();
        
        for(auto itr : E[node]){
            --ind[itr];
            if(ind[itr] == 0){
                q.push_back(itr);
            }
        }
    }
    
    bool ans = true;
    for(int i =0; i<index; ++i) ans = ans && (ind[i] == 0);
    if(ans) cout <<"possible";
    else cout <<"impossible";
    
    return 0;
} // Topological Sort