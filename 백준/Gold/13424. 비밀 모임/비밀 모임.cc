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
    
    ll T;
    cin >> T;
    while(T--){
        ll N, M;
        cin >> N >> M;
        vector<vector<ll>> v(N+1, vector<ll>(N+1, INT_MAX));
        for(int i = 1; i<=N; ++i) v[i][i] = 0;
        for(int i =0 ; i<M; ++i){
            ll a, b, c;
            cin >> a >> b >> c;
            v[a][b] = v[b][a] = c;
        }
        
        for(int i = 1; i<=N; ++i){
            for(int j = 1; j<=N; ++j){
                for(int k = 1; k<=N; ++k){
                    v[j][k] = min(v[j][i]+v[i][k], v[j][k]);
                }
            }
        }
        
        ll K;
        cin >> K;
        vector<ll> friends(K);
        for(int i = 0; i<K; ++i){
            cin >> friends[i];
        }
        ll ans = 0;
        ll ans2 = INT_MAX;
        
        for(int i = 1; i<=N; ++i){
            ll total = 0;
            for(int j = 0; j<K; ++j)
                total += v[i][friends[j]];
            if(ans2 > total){
                ans2 = total;
                ans = i;
            }
            
        }
        cout << ans <<"\n";
        
    }
    
    return 0;
} // Floyd-Warshall