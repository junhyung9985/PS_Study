#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    ll g = max(N, M);
    
    vector<vector<ll>> v(2*g, vector<ll>(2*g)); // downwards
    vector<vector<ll>> v2(2*g, vector<ll>(2*g)); // rightward
    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            char tmp;
            cin >> tmp;
            v2[i+j][N-1-i+j] = v[i+j][N-1-i+j] = tmp-'0';
        }
    }
    
    ll ans = 0;
    for(int i =0; i<2*g-1; ++i){
        for(int j=0; j<2*g-1; ++j){
            if(v[i][j]){
                if(i - 2 >= 0 ) v[i][j] = v[i-2][j] + 1;
                if(j - 2 >= 0 ) v2[i][j] = v2[i][j-2] + 1;
            }
        }
    }
    for(int i =0; i<2*g-1; ++i){
        for(int j=0; j<2*g-1; ++j){
            if(v[i][j] and v2[i][j]){
                
                ll sz2 = min(v2[i][j], v[i][j]);
                for(ll sz=sz2;sz>0;--sz)
                 if(i-2*sz+2 >=0 and j-2*sz+2 >=0)
                if(v[i][j-2*(sz-1)] >= sz and v2[i-2*(sz-1)][j] >= sz){ // 위에서 -> 나 <- 에서 아래로써나 길이가 같은가?
                    ans = max(ans, sz);
                    
                }
                //if(i-2*(sz2-1) <0 || j-2*(sz2-1) <0) continue;
                //if(v[i][j-2*(sz2-1)] >=sz2 and v2[i-2*(sz2-1)][j]>=sz2){ // 
            }
        }
    }
    cout << ans;

    return 0;
} // rotate 45 degree + 2D prefix sum