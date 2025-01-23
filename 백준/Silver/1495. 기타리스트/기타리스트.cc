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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension
// Rope



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, S, M;
    cin >> N >> S >> M;
    
    vector<vector<ll>> able(N+1, vector<ll>(M+1));
    
    able[0][S] = 1;
    for(int i =1; i<=N; ++i){
        ll v;
        cin >> v;
        for(int j = 0; j<=M; ++j){
            if(able[i-1][j] == 1){
                if(j+v <= M) able[i][j+v] = 1;
                if(j-v >=0) able[i][j-v] = 1;
            }
        }
    }
    
    for(int i = M; i>=0 ; --i){
        if(able[N][i]){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    
    return 0;
} // DP
