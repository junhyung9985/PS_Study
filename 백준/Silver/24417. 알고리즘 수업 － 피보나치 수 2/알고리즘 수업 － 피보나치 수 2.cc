#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll ret[2][2];
ll v[2][2];

ll MOD = 1'000'000'007;

void power(bool flag){
    vector<vector<ll>> tmp(2, vector<ll>(2));
    if(flag){
        for(int i = 0; i<2; ++i){
            for(int j =0; j<2; ++j){
                for(int k=0; k<2; ++k){
                    tmp[i][j] += v[k][j] * ret[i][k];
                    tmp[i][j]%= MOD;
                }
            }
        }
        for(int i =0; i<2; ++i) for(int j =0; j<2; ++j) ret[i][j] = tmp[i][j];

    }
    else{
        for(int i = 0; i<2; ++i){
            for(int j =0; j<2; ++j){
                for(int k=0; k<2; ++k){
                    tmp[i][j] +=  v[k][j] * v[i][k];
                    tmp[i][j]%= MOD;
                }
            }
        }
        
        for(int i =0; i<2; ++i) for(int j =0; j<2; ++j) v[i][j] = tmp[i][j];
    }
}

void print_ret(){
    for(int i =0 ;i<2; ++i){
        for(int j =0; j<2 ;++j)
            cout << ret[i][j] <<" ";
        cout<<"\n";
    }
}


ll fib(ll n){
    ret[0][0] = ret[1][1] = 1;
    v[0][0] = v[0][1] = v[1][0] = 1;
    while(n){
        if(n%2) power(true);
        power(false);
        n/=2;
    }
    //print_ret();
    return ret[0][1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    cout << fib(N) <<" "<<N-2;
    
    return 0;
} // Exponential using DnC