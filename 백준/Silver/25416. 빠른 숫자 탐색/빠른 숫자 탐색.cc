#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dy[4] = {1,-1,0,0};
ll dx[4] = {0,0,1,-1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<ll>> m(5, vector<ll>(5));
    vector<vector<ll>> dist(5, vector<ll>(5, 30));
    
    for(int i =0; i<5; ++i)
        for(int j =0; j<5; ++j)
            cin >>m[i][j];
    
    
    ll y,x;
    cin >> y >> x;
    dist[y][x] = 0;
    
    deque<pair<ll,ll>> q;
    q.push_back({y,x});

    while(!q.empty()){
        ll y,x;
        tie(y,x) = q.front();
        q.pop_front();
        for(int k =0; k<4; ++k){
            ll ny = y+dy[k], nx = x+dx[k];
            if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
            if(m[ny][nx] == -1) continue;
            if(dist[ny][nx] <= dist[y][x] + 1) continue;
            dist[ny][nx] = dist[y][x]+1;
            q.push_back({ny,nx});
        }
    }    
    
    ll minn = 30;
    for(int i = 0; i<5; ++i){
        for(int j =0; j<5; ++j){
            if(m[i][j] == 1) minn = min(minn, dist[i][j]);
        }
    }
    if(minn == 30) minn = -1;
    cout << minn;
    
    return 0;
} // BFS