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

string num[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111","1010010","1111111","1111011"};

ll diff_calc(ll a, ll b){
    ll cnt = 0;
    for(int i =0; i<7; ++i)
        if(num[a][i] != num[b][i]) ++cnt;
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<ll>> diffs(10, vector<ll>(10));
    for(int i =0; i<10; ++i)
        for(int j =i+1; j<10; ++j)
            diffs[i][j] = diffs[j][i] = diff_calc(i,j);
    
    ll N, K, P, X;
    ll ans = 0;
    cin >> N >> K >> P >> X;
    for(int i =1; i<=N; ++i){
        if(i == X) continue;
        ll tmp_1 = i, tmp_2 = X;
        ll diff_count = 0;
        for(int k =0; k<K; ++k){
            diff_count += diffs[tmp_1%10][tmp_2%10];
            tmp_1/=10;
            tmp_2/=10;
        }
        if(diff_count <= P) ++ans;
    }
    cout << ans;

    return 0;
} // Bitmasking(?), Bruteforcing