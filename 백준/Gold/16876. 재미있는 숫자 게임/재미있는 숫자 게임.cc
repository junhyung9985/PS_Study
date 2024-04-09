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

ll able[101][10001];

void turn(ll curr, ll t){
    for(int i = 0; i<10000; ++i){
        if(able[t-1][i] == curr){
            ll tmp = i;
            ll val = 1;
            for(int k =0; k<4; ++k){
                ll tmp2 = i - val;
                if(tmp%10 == 0){
                    tmp2 = i + 9 * val;
                }
                able[t][tmp2] = curr;
                tmp /= 10;
                val *= 10;
            }
        }
    }
    for(int i =0; i<10000; ++i){
        if(able[t][i] == 0) able[t][i] = -curr; 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    for(int i =0; i<10000; ++i){
        if(i <= N) able[0][i] = -1;
        else able[0][i] = 1;
    }
    
    ll curr_player = 2 * (M%2) - 1;
    for(int j = 1; j<=M; ++j){
        turn(curr_player, j);
        curr_player = -curr_player;
    }
    if(able[M][N] == 1) cout <<"koosaga";
    else cout <<"cubelover";

    return 0;
} // Game Theory, DP