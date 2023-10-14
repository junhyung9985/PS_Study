#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    
    ll dy[4] = {1,-1,0,0};
    ll dx[4] = {0,0,1,-1};

    vector<vector<vector<ll>>> dp(N, vector<vector<ll>>(M, vector<ll>(4, INT_MAX)));
    vector<vector<char>> m(N, vector<char>(M));
    ll s_y, s_x, ty1=-1, tx1=-1, ty2=-1, tx2=-1;

    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            cin >> m[i][j];
            if(m[i][j] =='S'){
                s_y = i;
                s_x = j;
            }
            if(m[i][j] == 'C'){
                if(ty1 == -1){
                    ty1 = i;
                    tx1 = j;
                }
                else{
                    ty2 =i;
                    tx2 =j;
                }
            }
        }
    }

    deque<tuple<ll,ll,ll, ll>> q;
    q.push_back({s_y,s_x, 0, -1});
    ll ans = INT_MAX;
    while(!q.empty()){
        ll y,x,c,d;
        tie(y,x,c,d) = q.front();
        q.pop_front();

        for(int k = 0; k<4; ++k){
            ll n_y = y+dy[k], n_x = x+dx[k];
            if(n_y < 0 || n_y >= N || n_x < 0 || n_x >=M || k == d){
                continue;
            }
            if(m[n_y][n_x] =='#') continue;
            if(dp[n_y][n_x][k] > c+1){
                dp[n_y][n_x][k] = c+1;
                q.push_back({n_y,n_x,c+1, k});
            }
        }

    } // BFS S -> C1 and C2 

    

    for(int i =0; i<4; ++i){
        if(dp[ty1][tx1][i] == INT_MAX) continue;
        
        ll tmp_ans = dp[ty1][tx1][i];
        
        deque<tuple<ll,ll,ll, ll>> q;        
        vector<vector<vector<ll>>> dp2(N, vector<vector<ll>>(M, vector<ll>(4, INT_MAX)));
        dp2[ty1][tx1][i] = 0;
        q.push_back({ty1, tx1, 0, i});

        while(!q.empty()){
            ll y,x,c,d;
            tie(y,x,c,d) = q.front();
            q.pop_front();

            for(int k = 0; k<4; ++k){
                ll n_y = y+dy[k], n_x = x+dx[k];
                if(n_y < 0 || n_y >= N || n_x < 0 || n_x >=M || k == d){
                    continue;
                }
                if(m[n_y][n_x] =='#') continue;

                if(dp2[n_y][n_x][k] > c+1){
                    dp2[n_y][n_x][k] = c+1;
                    q.push_back({n_y,n_x,c+1, k});
                }
            }    
        }

        // for(int k =0; k<4; ++k){
        //     for(int i =0;i <N; ++i){
        //         for(int j =0; j<M ;++j){
        //             cout<<dp2[i][j][k]<<" ";
        //         }
        //         cout<<"\n";
        //     }
        //     cout<<"\n";
        // }

        ll tmp_ans2= INT_MAX;
        for(int j=0; j<4; ++j){
            tmp_ans2 = min(tmp_ans2, dp2[ty2][tx2][j]);
        }
        if(tmp_ans2 == INT_MAX) continue;
        ans = min(ans, tmp_ans+tmp_ans2);
        // BFS C1 -> C2
    }    

    for(int i =0; i<4; ++i){
        if(dp[ty2][tx2][i] == INT_MAX) continue;
        
        ll tmp_ans = dp[ty2][tx2][i];
        
        deque<tuple<ll,ll,ll, ll>> q;        
        vector<vector<vector<ll>>> dp2(N, vector<vector<ll>>(M, vector<ll>(4, INT_MAX)));
        dp2[ty2][tx2][i] = 0;
        q.push_back({ty2, tx2, 0, i});

        while(!q.empty()){
            ll y,x,c,d;
            tie(y,x,c,d) = q.front();
            q.pop_front();

            for(int k = 0; k<4; ++k){
                ll n_y = y+dy[k], n_x = x+dx[k];
                if(n_y < 0 || n_y >= N || n_x < 0 || n_x >=M || k == d){
                    continue;
                }
                if(m[n_y][n_x] =='#') continue;
                if(dp2[n_y][n_x][k] > c+1){
                    dp2[n_y][n_x][k] = c+1;
                    q.push_back({n_y,n_x,c+1, k});
                }
            }    
        }

        ll tmp_ans2= INT_MAX;
        for(int j=0; j<4; ++j){
            tmp_ans2 = min(tmp_ans2, dp2[ty1][tx1][j]);
        }
        if(tmp_ans2 == INT_MAX) continue;
        ans = min(ans, tmp_ans+tmp_ans2);
        // BFS C1 -> C2
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans;

    return 0;
} // BFS, Implementation