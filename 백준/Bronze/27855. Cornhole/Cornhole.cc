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
    
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    a = 3*a+b;
    a -= 3*c+d;
    if(a > 0){
        cout << 1 <<" "<<a;
    }
    else if(a < 0){
        cout << 2 <<" "<<-a;
    }
    else cout <<"NO SCORE";
    
    
    return 0;
} // Implementation + Math(?)
