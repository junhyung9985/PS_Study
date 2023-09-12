#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    
    vector<vector<char>> m(N,vector<char>(M));
    for(int i =0; i<N; ++i){
        for(int j =0 ;j< M; ++j){
            cin >> m[i][j];
        }
    }

    bool check = false;
    for(int i = 1; i<N-1; ++i){
        if(M%2){
            if(m[i][M/2-1] == 'X' && m[i][M/2] == 'X' && m[i][M/2+1] == 'X'){
                m[i][M/2-1] = 'W';
                m[i][M/2] = 'Y';
                m[i][M/2+1] = 'W';
                check  = true;
            }

        }
        else {
            if(m[i][M/2-1] == 'X' && m[i][M/2] == 'X' && m[i][M/2-2] == 'X' && m[i][M/2+1] == 'X'){
                m[i][M/2-2] = 'W';
                m[i][M/2-1] = 'Y';
                m[i][M/2] = 'Y';
                m[i][M/2+1] = 'W';
                check  = true;
            }
        }
        if(check) break;
    }
    if(!check){
        cout <<"NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            if(m[i][j] =='X') m[i][j] = 'B';
            cout <<m[i][j];
        }
        cout<<"\n";
    }

    return 0;
}