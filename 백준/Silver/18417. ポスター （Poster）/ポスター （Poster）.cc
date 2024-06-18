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
    vector<vector<vector<char>>> m(2, vector<vector<char>>(N, vector<char>(N)));
    vector<vector<char>> m2(N, vector<char>(N));
    for(int i = 0; i<N; ++i){
        for(int j =0 ; j<N; ++j){
            cin >> m[0][i][j];
        } 
    }
    for(int i = 0; i<N; ++i){
        for(int j =0 ; j<N; ++j){
            cin >> m2[i][j];
        } 
    }
    ll ans = INT_MAX;
    ll offset = 0;
    
    for(int k = 0; k<4; ++k){
        ll diff = 0;
        for(int i = 0; i<N; ++i){
           for(int j = 0 ; j<N; ++j){
               if(m[k%2][i][j] != m2[i][j]) ++ diff;
           } 
        }
        ans = min(ans, diff + offset);
        
        if(k%2 == 0){
            offset = 1;
        }
        if(k == 1) offset = 2;
        for(int i = 0; i<N; ++i){
            for(int j =0 ;j<N; ++j){
                m[1-k%2][j][N-i-1] = m[k%2][i][j]; 
            }
        }
    }
    
    cout << ans;
    return 0;
} // Implementation?
// O(N^2)