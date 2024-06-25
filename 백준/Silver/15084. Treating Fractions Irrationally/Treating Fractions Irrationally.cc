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
    
    ll curr = 0;
    ll n, d;
    cin >> n >> d;
    unordered_set<ll> dup;
    string s = "0.";
    while(true){
        n *= 10;
        if(dup.find(n) != dup.end()){
            cout << "throw out";
            return 0;
        }
        dup.insert(n);
        curr = n/d;
        if(curr == 0){
            if(s[s.size()-1] == '.'){
                cout << 0;
                return 0;
            }
            else{
                break;
            }
        }
        if(curr == 9){
            if(s[s.size()-1] == '.'){
                cout << 1;
                return 0;
            }
            else{
                s[s.size()-1] = s[s.size()-1]+1;
                break;
            }
        }
        s += (curr + '0');
        n = n%d;
    }
    cout << s;
    
    return 0;
} // Implementation