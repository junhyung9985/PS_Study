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
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension
// Rope

ll dy[4] = {1,-1,0,0};
ll dx[4] = {0,0,1,-1};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T;
    cin >> T;
    for(int tc = 1; tc<=T; ++tc){
        
        ll R,C;
        cin >> R >> C;
        
        ll sy, sx;
        cin >>sy >> sx;
        
        vector<vector<ll>> v(R, vector<ll>(C));
        vector<vector<bool>> vis(R, vector<bool>(C, false));
        --sy;
        --sx;
        
        for(int i =0; i< R; ++i)
            for(int j =0;j <C; ++j)
                cin >> v[i][j];
        
        ll ans = 0;
        vis[sy][sx] = true;
        deque<pair<ll,ll>> q;
        q.push_back({sy,sx});
        while(!q.empty()){
            ll y,x;
            tie(y,x) = q.front();
            q.pop_front();
            if(y == 0 || x ==0 || y == R-1 || x == C-1) ++ans;
            for(int k =0; k<4; ++k){
                ll ny = y +dy[k], nx = x+dx[k];
                if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
                if(v[ny][nx] < v[y][x]) continue;
                if(vis[ny][nx]) continue;
                vis[ny][nx] = true;
                q.push_back({ny,nx});
            }
        }
        
        cout << "Case #"<<tc <<": "<<ans<<"\n";
        
    }
    
    
    return 0;
} // BFS
// 지문 이해 실수 주의!!!
