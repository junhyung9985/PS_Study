#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dy[4] = {-1,0,1,0};
ll dx[4] = {0,1,0,-1};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll H, W;
    cin >> H >> W;
    
    vector<vector<vector<char>>> m(2, vector<vector<char>>(H, vector<char>(W)));
    
    ll y, x, dir;
    cin >> y >> x >> dir;
    
    for(int i =0; i<2; ++i){
        for(int j =0; j<H; ++j){
            for(int k =0; k<W; ++k){
                cin >> m[i][j][k];
            }
        }
    }
    
    vector<vector<bool>> visited2(H, vector<bool>(W, false));
    ll cnt = 0;
    ll ans = 0;
    ll unvisited = 0;
    for(int i = 0; i< 40'000'000; ++i){
        if(visited2[y][x]){
            ++unvisited;
            dir += m[1][y][x] - '0';
        }
        else{
            unvisited = 0;
            dir += m[0][y][x] - '0';
            ++cnt;
        }
        dir %=4;
        visited2[y][x] = true;
        y += dy[dir];
        x += dx[dir];
        ++ans;
        //if(cnt == W*H) break;
        if(y < 0 || y >= H || x < 0 || x >= W) break;
    }
    //cout << ans <<" "<<unvisited<<"\n";
    cout << ans - unvisited;
    
    return 0;
} // Implementation, Simulation