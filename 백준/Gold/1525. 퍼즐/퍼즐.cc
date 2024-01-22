#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// // PBDS

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll curr = 0;
    ll t;
    for(int i =0; i<9; ++i){
        cin >> t;
        curr = curr*10+t;
    }
    
    set<ll> s;
    deque<pair<ll,ll>> q;
    s.insert(curr);
    q.push_back({curr, 0});
    
    int board[3][3];
    ll ans = -1;
    while(!q.empty()){
        ll c,d;
        tie(c,d) = q.front();
        q.pop_front();
        //cout << c <<" "<<d<<"\n";
        if(c == 123456780){
            ans = d;
            break;
        }
        int y,x;
        for(int i = 2; i>-1; --i){
            for(int j =2; j>-1; --j){
                if(c%10 == 0){
                    y = i, x= j;
                }
                board[i][j] = c%10;
                c/=10;
            }
        }
        for(int k = 0; k<4; ++k){
            int ny = y+dy[k], nx = x+dx[k];
            if(nx < 0 || ny < 0 || ny>=3 || nx >= 3) continue;
            ll n_c = 0;
            for(int i =0; i<3; ++i){
                for(int j =0; j<3; ++j){
                    if(i == y & j == x){
                        n_c = n_c * 10 + board[ny][nx];
                    }
                    else if(i == ny && j == nx){
                        n_c = n_c * 10 + board[y][x];
                    }
                    else n_c = n_c * 10 + board[i][j];
                }
            }
            if(s.find(n_c) == s.end()){
                s.insert(n_c);
                q.push_back({n_c, d+1});
            }
        }
    }
    
    cout << ans;
    return 0;
} // BFS, Simulation