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
    
    vector<vector<ll>> position(N, vector<ll>(3));
    for(int i = 0; i < N; ++i){
        char tmp;
        cin >> position[i][0];
        cin >> tmp;
        cin >> position[i][1];
        cin >> tmp;
        cin >> position[i][2];
    }
    // for(int i = 0; i < N; ++i){
    //     for(int j = 0; j < 3; ++j)
    //         cout << position[i][j]<<" ";
    //     cout <<"\n";
    // }
    
    ll t;
    cin >> t;
    vector<ll> player(t);
    
    ll offset = 0;
    for(int i =0; i<t; ++i){
        string s;
        cin >> s;
        for(char ch : s){
            if(ch == 'O') player[i] |= 4;
            if(ch == 'V') player[i] |= 2;
            if(ch == 'N') player[i] |= 1;
        }
        if(player[i] == 7) ++offset;
    }
    
    for(int i = 0; i<N; ++i){
        for(int j =0; j<t; ++j){
            if(player[j] == 4) -- position[i][0];
            if(player[j] == 2) -- position[i][1];
            if(player[j] == 1) -- position[i][2];
        }
        for(int j =0 ;j<3; ++j){
            position[i][j] = max((ll)0, position[i][j]);
        }
        bool able = false;
        for(int a = 0; a < 2; ++a){
            for(int b = 0; b < 3; ++b){
                if(b == 1) continue;
                for(int c = 1; c < 3; ++c){
                    ll o = position[i][0], v = position[i][1], n = position[i][2];
                    for(int j =0; j<t; ++j){
                        if(player[j] == 6){
                            if(a == 1){
                                if(v > 0) -- v;
                                else if(o > 0) -- o;
                            }
                            else{
                                if(o > 0) --o;
                                else if (v > 0) -- v;
                            }
                        }
                        if(player[j] == 5){
                            if(b == 2){
                                if(n > 0) --n;
                                else if(o >0) --o;
                            }
                            else{
                                if(o > 0) -- o;
                                else if( n > 0) -- n;
                            }
                        }
                        if(player[j] == 3){
                            if(c == 2){
                                if(n > 0) -- n;
                                else if( v > 0) -- v;
                            }
                            else{
                                if(v > 0) -- v;
                                else if(n > 0) -- n;
                            }
                        }
                        
                    }
                    //cout << o <<" "<< v <<" "<<n << " " << offset<<"\n";
                    if(o + v + n <= offset) able = true;
                    
                }
            }
        }
        if(able) cout <<"DA\n";
        else cout <<"NE\n";
    }
    
    
    return 0;
} // Bruteforcing