#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dy[2][6] = {{-1,-1,0,0,1,1},{-1,-1,0,0,1,1}};
ll dx[2][6] = {{-1,0,-1,1,-1,0},{0,1,-1,1,0,1}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M, Q;
    cin >> N >> M >> Q;
    
    vector<vector<vector<ll>>> p(N+1, vector<vector<ll>>(N+1, vector<ll>(N+1, INT_MAX)));
    for(int i =0; i<M; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        for(int j =0; j<=N; ++j)
            p[j][a][b] = c;
    }
    
    for(int l = 1; l<=N; ++l){
        for(int k = 1; k<=N; ++k){
            if(k == l) continue;
            for(int i =1; i<=N; ++i){
                for(int j =1; j<=N; ++j){
                    p[l][i][j] = min(p[l][i][j], p[l][i][k] + p[l][k][j]);
                }
            }
        }
    }
    
    
    while(Q--){
        ll s, k, e;
        cin >> s >> k >> e;
        ll ans = p[k][s][e];
        if(p[k][s][e] == INT_MAX) cout <<"No\n";
        else cout << ans <<"\n";
    }
    
    
    
    
    return 0;
}