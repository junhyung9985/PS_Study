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
    vector<vector<vector<ll>>> dist(2, vector<vector<ll>>(N, vector<ll>(M, INT_MAX)));

    for(int i =0; i<N; ++i){
        for(int j =0; j< M; ++j){
            char ch;
            cin >> ch;
            m[i][j] = ch-'0';
        }
    }

    dist[0][0][0] = dist[1][0][0] = 1;
    priority_queue<tuple<ll,ll,ll,ll>> pq;
    pq.push({-1,0,0,0});
    while(!pq.empty()){
        ll d, c, y, x;
        tie(d,c,y,x) = pq.top();
        pq.pop();
        d *= -1;
        c *= -1;
        if(dist[c][y][x] < d) continue;
        for(int k =0; k<4; ++k){
            ll n_y = y + dy[k], n_x = x + dx[k];
            if(n_y >= N || n_y < 0 || n_x >= M || n_x < 0) continue;
            if(m[n_y][n_x] == 1 && c == 0){
                if(dist[c+1][n_y][n_x] > d + 1){
                    dist[c+1][n_y][n_x] = d + 1;
                    pq.push({-d-1, -c-1, n_y,n_x});
                }
            }
            if(m[n_y][n_x] == 0){
                if(dist[c][n_y][n_x] > d+1){
                    dist[c][n_y][n_x] = d+1;
                    pq.push({-d-1, -c, n_y, n_x});
                    if(c == 0){
                        if(dist[c+1][n_y][n_x] > d+1){
                            dist[c+1][n_y][n_x] = d+1;
                            pq.push({-d-1, -c-1, n_y, n_x});
                        }
                    }
                }
            }
        }
    }


    ll ans = min(dist[0][N-1][M-1], dist[1][N-1][M-1]);
    if(ans == INT_MAX) ans = -1;
    cout << ans;

    return 0;
} // Dijkstra
// 원래 의도한 풀이는 BFS일 것 같긴한데...