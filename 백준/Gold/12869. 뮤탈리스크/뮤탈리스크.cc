#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<vector<vector<ll>>> dp(61, vector<vector<ll>>(61, vector<ll>(61, -1)));
    
    dp[0][0][0] = 0;
    deque<tuple<ll,ll,ll>> q;
    q.push_back({0,0,0});
    while(!q.empty()){
        ll a,b,c;
        tie(a,b,c) = q.front();
        q.pop_front();
        
        ll n = dp[a][b][c];
        
        for(int i =0; i<=9; ++i){
            for(int j =0; j<=3; ++j){
                for(int k = 0; k<=1; ++k){
                    if(a+i > 60 || b+j > 60 || c+k > 60) continue;
                    if(dp[a+i][b+j][c+k] == -1){
                        dp[a+i][b+j][c+k] = n+1;
                        q.push_back({a+i,b+j, c+k});
                    }
                }
            }
        }
        for(int i =0; i<=9; ++i){
            for(int j =0; j<=1; ++j){
                for(int k = 0; k<=3; ++k){
                    if(a+i > 60 || b+j > 60 || c+k > 60) continue;
                    if(dp[a+i][b+j][c+k] == -1){
                        dp[a+i][b+j][c+k] = n+1;
                        q.push_back({a+i,b+j, c+k});
                    }
                }
            }
        }        
        for(int i =0; i<=3; ++i){
            for(int j =0; j<=9; ++j){
                for(int k = 0; k<=1; ++k){
                    if(a+i > 60 || b+j > 60 || c+k > 60) continue;
                    if(dp[a+i][b+j][c+k] == -1){
                        dp[a+i][b+j][c+k] = n+1;
                        q.push_back({a+i,b+j, c+k});
                    }
                }
            }
        }        
        
        for(int i =0; i<=3; ++i){
            for(int j =0; j<=1; ++j){
                for(int k = 0; k<=9; ++k){
                    if(a+i > 60 || b+j > 60 || c+k > 60) continue;
                    if(dp[a+i][b+j][c+k] == -1){
                        dp[a+i][b+j][c+k] = n+1;
                        q.push_back({a+i,b+j, c+k});
                    }
                }
            }
        }        
        for(int i =0; i<=1; ++i){
            for(int j =0; j<=9; ++j){
                for(int k = 0; k<=3; ++k){
                    if(a+i > 60 || b+j > 60 || c+k > 60) continue;
                    if(dp[a+i][b+j][c+k] == -1){
                        dp[a+i][b+j][c+k] = n+1;
                        q.push_back({a+i,b+j, c+k});
                    }
                }
            }
        }        
        for(int i =0; i<=1; ++i){
            for(int j =0; j<=3; ++j){
                for(int k = 0; k<=9; ++k){
                    if(a+i > 60 || b+j > 60 || c+k > 60) continue;
                    if(dp[a+i][b+j][c+k] == -1){
                        dp[a+i][b+j][c+k] = n+1;
                        q.push_back({a+i,b+j, c+k});
                    }
                }
            }
        } 
        
    }
    
    vector<ll> v(3);
    
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }
    cout << dp[v[0]][v[1]][v[2]];
    
    
    return 0;
} // BFS, DP