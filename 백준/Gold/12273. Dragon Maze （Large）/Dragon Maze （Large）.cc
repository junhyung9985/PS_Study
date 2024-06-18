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

ll dy[4] = {-1,1,0,0};
ll dx[4] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T;
    cin >> T;
    for(int tc = 1; tc <= T; ++ tc){
        ll N, M;
        cin >> N >> M;
        ll sx, sy, ex, ey;
        cin >> sy >> sx >> ey >> ex;
        vector<vector<ll>> dist(N, vector<ll>(M, INT_MAX));
        vector<vector<ll>> power(N, vector<ll>(M, 0));
        vector<vector<ll>> m(N, vector<ll>(M));
        for(int i =0; i<N; ++i)
            for(int j =0; j<M; ++j)
                cin >> m[i][j];
        
        ll l = 0, r = N*M+1;
        dist[sy][sx] = 0;
        power[sy][sx] = m[sy][sx];
        deque<pair<ll,ll>> q;
        q.push_back({sy,sx});
        while(!q.empty()){
            ll y, x;
            tie(y, x) = q.front();
            q.pop_front();
            //cout << y <<" "<< x <<" "<<power[y][x]<<"\n";
            for(int k =0 ;k<4; ++k){
                ll ny = dy[k] + y, nx = dx[k] + x;
                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(m[ny][nx] == -1) continue;
                if(dist[ny][nx] < dist[y][x] + 1) continue;
                power[ny][nx] = max(power[ny][nx], power[y][x] + m[ny][nx]);
                if(dist[ny][nx] != INT_MAX) continue;
                dist[ny][nx] = dist[y][x]+1;
                q.push_back({ny,nx});
            }
            
        }
        cout <<"Case #"<<tc<<": ";
        if(dist[ey][ex] == INT_MAX) cout << "Mission Impossible.\n";
        else cout << power[ey][ex]<<"\n";
        
    }
    return 0;
} // BFS, DP(?)