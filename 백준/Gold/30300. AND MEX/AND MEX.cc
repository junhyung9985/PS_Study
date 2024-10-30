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

const ll MAX = 1'000'000'000'000'000'000;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        vector<ll> v(N);
        set<ll> ans;
        for(int i =0; i<=N; ++i)
            ans.insert(i);
            
        for(int i =0; i<N; ++i){
            cin >> v[i];
        }
        ll p = (1<<30) - 1;
        ll mex = 0, answer = 0;
        while(p){
            for(int i =0;i <N; ++i){
                ll n_v = v[i] & p;
                ans.erase(n_v);
            }
            if(mex < *(ans.begin())){
                mex = *(ans.begin());
                answer = p;
            }
            for(int i =0; i<N; ++i){
                ans.insert(p & v[i]);
            }
            p/=2;
        }
        cout << answer<<"\n";
        
    }    
    return 0;
} // Ad_Hoc, Consturctive
/*

AND 최대값 -> 해당 값 그대로...
떨어질 일 밖에 없다!

001101
001011
001010
101000
100001
010011

000111

32 * 100000



*/
