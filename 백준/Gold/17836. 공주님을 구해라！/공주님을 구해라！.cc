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

ll dy[4] = {0,0,1,-1};
ll dx[4] = {1,-1,0,0};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M, T;
    cin >> N >> M >> T;
    
    vector<vector<ll>> m(N, vector<ll>(M));
    vector<vector<ll>> dist(N, vector<ll>(M,INT_MAX));
    
    ll gramy = 0, gramx = 0;
    for(int i =0; i<N; ++i)
        for(int j =0; j<M; ++j){
            cin >> m[i][j];
            if(m[i][j] == 2) gramy = i, gramx = j;
        }
    
    deque<pair<ll,ll>> q;
    q.push_back({0,0});
    dist[0][0] = 0;
    while(!q.empty()){
        ll y, x;
        tie(y, x) = q.front();
        q.pop_front();
        for(int k = 0; k<4; ++k){
            ll ny = y + dy[k], nx = x + dx[k];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            if(m[ny][nx] == 1) continue;
            if(dist[ny][nx] <= dist[y][x]+1) continue;
            dist[ny][nx] = dist[y][x]+1;
            q.push_back({ny,nx});
        }
    }
    ll least_time = min(dist[N-1][M-1], dist[gramy][gramx] + abs(N-1-gramy) + abs(M-1 - gramx));
    if(least_time <= T) cout << least_time;
    else cout << "Fail";
    return 0;
}