#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dy[4] = {1,-1,0,0};
ll dx[4] = {0,0,1,-1};

map<pair<ll,ll>, pair<ll,ll>> p;
map<pair<ll,ll>, vector<pair<ll,ll>>> sz;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll r, c;
    cin >>  r >> c;
    vector<vector<char>> v(r, vector<char>(c));
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    vector<vector<char>> vision(r, vector<char>(c, '#'));
    
    for(int i =0; i<r; ++i){
        for(int j =0; j<c; ++j){
            cin >> v[i][j];
        }
    }
    
    for(ll i =0; i<r; ++i){
        for(ll j =0; j<c; ++j){
            if(visited[i][j]) continue;
            
            deque<pair<ll,ll>> q;
            q.push_back({i,j});
            
            char ch = v[i][j];
            visited[i][j] = true;
            
            while(!q.empty()){
                ll y, x;
                tie(y,x) = q.front();
                q.pop_front();
                p[{y,x}] = {i,j};
                sz[{i,j}].push_back({y,x});
                
                for(int k=0; k<4; ++k){
                    ll ny = y+dy[k], nx = x+dx[k];
                    if(ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                    if(ch == v[ny][nx] and !visited[ny][nx]){
                        visited[ny][nx] = true;
                        q.push_back({ny,nx});
                    }
                }
            }
            //cout << i<<" "<< j<<" "<<sz[{i,j}].size()<<"\n";
            
        }
    }
    
    ll cur_y, cur_x;
    cin >> cur_y >> cur_x;
    --cur_y; --cur_x;
    
    string cmd;
    cin >> cmd;
    for(char ch : cmd){
        if(ch == 'L') -- cur_x;
        if(ch == 'R') ++ cur_x;
        if(ch == 'U') -- cur_y;
        if(ch == 'D') ++ cur_y;
        if(ch == 'W'){
            if(vision[cur_y][cur_x] == '.') continue;
            pair<ll, ll> pcur = p[{cur_y,cur_x}];
            //cout << pcur.first <<" "<<pcur.second<<" "<<sz[pcur].size()<<"\n";
            for(auto itr : sz[pcur]){
                ll y, x;
                tie(y,x) = itr;
                vision[y][x] = '.';
            }
        }
    }
    vision[cur_y][cur_x] = '.';
    for(int i = 0; i<4; ++i){
        ll y = cur_y + dy[i], x = cur_x + dx[i];
        if(y < 0 || x < 0 || y>=r || x >= c) continue;
        vision[y][x] = '.';
    }
    for(int i =0; i<r; ++i){
        for(int j =0; j<c; ++j){
            cout << vision[i][j];
        }
        cout<<"\n";
    }
    
    
    return 0;    
} // Flood-Fill, Simulation