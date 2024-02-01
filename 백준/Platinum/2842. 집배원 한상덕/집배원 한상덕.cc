#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dy[8] = {1,1,1,0,0,-1,-1,-1};
ll dx[8] = {-1,0,1,-1,1,-1,0,1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<pair<ll,ll>> houses;
    vector<vector<char>> m(N, vector<char>(N));
    vector<vector<ll>> v(N, vector<ll>(N));
    vector<ll> vals(N*N);
    ll sy, sx;
    
    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            cin >> m[i][j];
            if(m[i][j] == 'P'){
                sy = i;
                sx = j;
            }
            else if(m[i][j] == 'K'){
                houses.push_back({i,j});
            }
        }
    }
    
    
    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            cin >> v[i][j];
            vals[i*N+j] = v[i][j];
        }
    }
    sort(vals.begin(), vals.end());

    ll l = -1, r = 1'000'000;
    while(l+1 < r){
        ll mid = (l+r)/2;
        bool flag = false;
        for(int k = 0; k<N*N; ++k){
            ll from = vals[k], to = vals[k]+mid;
            if(v[sy][sx] < from || to < v[sy][sx]) continue;
            
            vector<vector<bool>> visited(N, vector<bool>(N, false));
            deque<pair<ll,ll>> q;
            
            visited[sy][sx] = true;
            q.push_back({sy,sx});
            
            while(!q.empty()){
                ll y, x;
                tie(y,x) = q.front();
                q.pop_front();
                for(int d = 0; d<8; ++d){
                    ll ny = y + dy[d], nx = x + dx[d];
                    if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                    if(v[ny][nx] < from || v[ny][nx] > to) continue;
                    if(visited[ny][nx]) continue;
                    visited[ny][nx] = true;
                    q.push_back({ny,nx});
                }
            }
            
            bool flag2 = true;
            for(auto itr: houses){
                ll y,x;
                tie(y,x) = itr;
                flag2 = flag2 && visited[y][x];
            }
            
            if(flag2){
                flag = true;
                break;
            }
        }
        // cout << mid <<" ";
        // cout << flag<<"\n";
        if(flag) r = mid;
        else l = mid;
    }
    
    cout << r;
    
    return 0;
} // Sweeping, Binary Search, BFS
// O(N^4 log (1'000'000)) 2500*2500