#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    
    vector<vector<ll>> m(N, vector<ll>(M));
    vector<vector<ll>> dist(N, vector<ll>(M));
    vector<vector<ll>> visited(N, vector<ll>(M, -1));
    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            char ch;
            cin >> ch;
            m[i][j] = ch-'0';
        }
    }

    vector<ll> group;
    ll g = -1;
    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            if(m[i][j] || (visited[i][j] >= 0)) continue;
            ++ g;
            group.push_back(0);
            visited[i][j] = g;
            deque<pair<ll,ll>> q;
            q.push_back({i,j});
            while(!q.empty()){
                ++group[g];
                ll y, x;
                tie(y,x)= q.front();
                q.pop_front();
                for(int k =0; k<4; ++k){
                    ll n_y = y+dy[k], n_x = x+dx[k];
                    if(n_y < 0 || n_y >= N || n_x< 0 || n_x >= M) continue;
                    if(m[n_y][n_x] || (visited[n_y][n_x] == g)) continue;
                    visited[n_y][n_x] = g;
                    q.push_back({n_y,n_x});
                }
            }
        }
    }

    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            if(m[i][j]){
                dist[i][j] = 1;
                set<ll> s;
                for(int k=0;k<4;++k){
                    ll n_y = i+dy[k], n_x = j+dx[k];
                    if(n_y < 0 || n_y >= N || n_x< 0 || n_x >= M) continue;
                    if(m[n_y][n_x]) continue;
                    s.insert(visited[n_y][n_x]);
                }
                for(auto itr : s){
                    dist[i][j] += group[itr];
                    dist[i][j]%=10;
                }
            }
        }
    }

    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            cout<<dist[i][j];
        }
        cout<<"\n";
    }
    return 0;
} // BFS, Flood-Fill(?)