#include <bits/stdc++.h>
#define ll long long
#define INF 987654321
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>

ll dy[4] = {1,-1,0,0};
ll dx[4] = {0,0,1,-1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    vector<vector<char>> m(N, vector<char>(M));
    map<ll, vector<ll>> E;
    map<ll, map<ll,ll>> f;
    map<ll, map<ll,ll>> c;
    
    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            cin >> m[i][j];
        }
    }
    ll s = -1, e = -1;
    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            if(m[i][j] == '#') continue;
            if(m[i][j] == 'K'){
                s = i*M+j+N*M;
            }
            if(m[i][j] == 'H'){
                e = i*M+j;
            }
            E[i*M+j].push_back(N*M+i*M+j);
            E[N*M+i*M+j].push_back(i*M+j);
            c[i*M+j][N*M+i*M+j] = 1;
            
            for(int k = 0; k<4; ++k){
                ll ny = i+dy[k], nx = j+dx[k];
                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(m[ny][nx] == '#') continue;
                else if(m[ny][nx] == 'H'){
                    if(m[i][j] == 'K'){
                        cout << -1;
                        return 0;
                    }
                }
                E[N*M+i*M+j].push_back(ny*M+nx);
                E[ny*M+nx].push_back(N*M+i*M+j);
                c[N*M+i*M+j][ny*M+nx] = INT_MAX;
            }
        }
    }
    
    ll ans = 0;
    while(true){
        vector<ll> visited(2*N*M, -1);
        deque<ll> q;
        q.push_back(s);
        while(!q.empty()){
            ll n = q.front();
            q.pop_front();
            for(auto itr : E[n]){
                if(c[n][itr] - f[n][itr] >0 && visited[itr] == -1){
                    visited[itr] = n;
                    q.push_back(itr);
                }
                if(itr == e) break;
            }
        }
        if(visited[e] == -1) break;
        
        ll curr = e;
        ll minn = INT_MAX;
        while(curr != s){
            minn = min(minn, c[visited[curr]][curr] - f[visited[curr]][curr]);
            curr = visited[curr];
        }
        curr = e;
        while(curr != s){
            f[visited[curr]][curr] += minn;
            f[curr][visited[curr]] -= minn;
            curr = visited[curr];
        }
        ans += minn;
    }
    cout << ans;
    
	return 0;
} // Edmond-Karp, Max-flow Min-cut theorem