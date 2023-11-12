#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll check[9] = {1,2,3,5,6,7,9,10,11};
pair<ll,ll> grid[3] = {{0,3}, {3,6}, {6,9}};

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<ll>> v(9, vector<ll>(9));
    
    string s;
    cin >> s;
    for(int i =0; i<3; ++i){
        cin >> s;
        for(int j =0; j<9; ++j){
            char ch = s[check[j]];
            if(ch == '.') v[i][j] = 0;
            else v[i][j] = ch-'0';
        }
    }
    cin >> s;
    for(int i =3; i<6; ++i){
        cin >> s;
        for(int j =0; j<9; ++j){
            char ch = s[check[j]];
            if(ch == '.') v[i][j] = 0;
            else v[i][j] = ch-'0';
        }
    }
    cin >> s;
    for(int i =6; i<9; ++i){
        cin >> s;
        for(int j =0; j<9; ++j){
            char ch = s[check[j]];
            if(ch == '.') v[i][j] = 0;
            else v[i][j] = ch-'0';
        }
    }
    
    bool flag = true;
    for(int i =0; i<9; ++i){
        vector<bool> check(10, true);
        for(int j =0; j<9; ++j){
            if(v[i][j] == 0) continue;
            flag = flag && check[v[i][j]];
            check[v[i][j]] = false;
        }
    }
    
    for(int i =0; i<9; ++i){
        vector<bool> check(10, true);
        for(int j =0; j<9; ++j){
            if(v[j][i] == 0) continue;
            flag = flag && check[v[j][i]];
            check[v[j][i]] = false;
        }
    }
    for(int row = 0; row<3; ++row){
        for(int col =0; col<3; ++col){
            vector<bool> check(10, true);
            for(int i = grid[row].first; i<grid[row].second ; ++i){
                for(int j = grid[col].first; j<grid[col].second; ++j){
                    if(v[i][j] == 0) continue;
                    flag = flag && check[v[i][j]];
                    check[v[i][j]] = false;
                }
            }
        }
    }
    if(flag) cout <<"OK";
    else cout <<"GRESKA";

    return 0;
}