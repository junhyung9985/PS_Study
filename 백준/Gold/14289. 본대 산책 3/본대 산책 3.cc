#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MOD = 1'000'000'007;
ll m[51][51];
ll ans[51][51];

void mul(){
    
    vector<vector<ll>> tmp(51, vector<ll>(51));
    
    for(int i = 0; i<51; ++i)
        for(int j =0; j<51; ++j)
            for(int k =0; k<51; ++k)
                tmp[i][j] += m[i][k] * ans[k][j], tmp[i][j] %= MOD ;
    
    for(int i =0; i<51; ++i)
        for(int j =0; j<51; ++j)
            ans[i][j] = tmp[i][j] % MOD;
    
    return;
}

void mul2(){
    
    vector<vector<ll>> tmp(51, vector<ll>(51));
    
    for(int i = 0; i<51; ++i)
        for(int j =0; j<51; ++j)
            for(int k =0; k<51; ++k)
                tmp[i][j] += m[i][k] * m[k][j], tmp[i][j] %= MOD;
    
    for(int i =0; i<51; ++i)
        for(int j =0; j<51; ++j)
            m[i][j] = tmp[i][j] % MOD;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    for(int i = 0; i<=50; ++i)
        ans[i][i] = 1;
    
    while(M--){
        ll a, b;
        cin >> a >> b;
        m[a][b] = m[b][a] = 1;
    }
    
    ll D;
    cin >> D;
    while(D){
        if(D%2){
            mul();
        }
        mul2();
        D/=2;
    }
    cout << ans[1][1];
    
    return 0;
} // DP, Divide and Conquer