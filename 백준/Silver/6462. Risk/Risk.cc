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
    
    ll t;
    ll cnt = 1;
    while(cin >> t){
        vector<vector<ll>> E(21, vector<ll>());
        for(int i =0; i<t; ++i){
            ll tmp;
            cin >> tmp;
            E[tmp].push_back(1);
            E[1].push_back(tmp);
        }
        for(int i = 2; i<20; ++i){
            cin >> t;
            for(int j = 0; j<t; ++j){
                ll tmp;
                cin >> tmp;
                E[tmp].push_back(i);
                E[i].push_back(tmp);
            }
        }
        vector<vector<ll>> dist(21, vector<ll>(21, INT_MAX));
        
        for(int i = 1; i<=20; ++i){
            dist[i][i] = 0;
            deque<ll> q;
            vector<bool> visited(21, false);
            visited[i] = true;
            q.push_back(i);
            while(!q.empty()){
                ll n = q.front();
                q.pop_front();
                for(auto itr : E[n]){
                    if(!visited[itr]){
                        visited[itr] = true;
                        dist[i][itr] = dist[i][n] + 1;
                        q.push_back(itr);
                    }
                }
            }
        }
        
        ll T;
        cin >> T;
        cout <<"Test Set #"<<cnt<<"\n";
        while(T--){
            ll a, b;
            cin >> a >> b;
            if(a < 10) cout<<" ";
            cout << a <<" to ";
            if(b < 10) cout <<" ";
            cout<<b<<": "<<dist[a][b]<<"\n";
        }
        ++cnt;
        cout <<"\n";
    }
 
    
    return 0;
} // BFS