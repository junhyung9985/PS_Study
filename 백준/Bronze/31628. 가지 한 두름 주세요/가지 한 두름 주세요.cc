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
    vector<vector<string>> m(10, vector<string>(10));
    for(int i =0 ;i<10; ++i){
        for(int j =0; j<10; ++j){
            cin >> m[i][j];
        }
    }
    
    bool ans = false;
    for(int i =0; i<10; ++i){
        bool flag = true;
        string ch = m[i][0];
        for(int j =0; j<10; ++j){
            flag = flag && (m[i][j] == ch);
        }
        ans = ans || flag;
    }
    for(int i =0; i<10; ++i){
        bool flag = true;
        string ch = m[0][i];
        for(int j =0; j<10; ++j){
            flag = flag && (m[j][i] == ch);
        }
        ans = ans || flag;
    }
    if(ans) cout <<"1";
    else cout <<"0";
    
    
    return 0;
} // 찌삐찌삐짜빠짜빠