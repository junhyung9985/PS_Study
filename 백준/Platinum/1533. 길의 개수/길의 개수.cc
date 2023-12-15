#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll m[60][60];
ll new_m[60][60];
ll ans[60][60];
ll MOD = 1'000'003;

void matrix_modification(ll n){
    for(int i =0; i<n; ++i){
        m[40+i][30+i] = m[30+i][20+i] = m[20+i][10+i] = m[10+i][i] = 1;
        for(int j =0; j<n; ++j){
            if(m[i][j] == 2){
                m[i][j] = 0;
                m[i][10+j] = 1;
            }
            else if(m[i][j] == 3){
                m[i][j] = 0;
                m[i][20+j] = 1;
            }
            else if(m[i][j] == 4){
                m[i][j] = 0;
                m[i][30+j] = 1;
            }
            else if(m[i][j] == 5){
                m[i][j] = 0;
                m[i][40+j] = 1;
            }
        }
    }
    return ;
}

ll mul(ll t, ll s, ll e){
    while(t){
        if(t%2){
            for(int i =0; i<60; ++i){
                for(int j =0; j<60; ++j){
                    for(int k =0; k<60; ++k){
                        new_m[i][j] += ans[i][k]*m[k][j];
                        new_m[i][j] %= MOD;
                    }
                }
            }
            for(int i =0; i<60; ++i){
                for(int j =0; j<60; ++j){
                    ans[i][j] = new_m[i][j];
                    new_m[i][j] = 0;
                }
            }
        }
        
        for(int i =0; i<60; ++i){
            for(int j =0; j<60; ++j){
                for(int k=0; k<60; ++k){
                    new_m[i][j] += m[i][k] * m[k][j];
                    new_m[i][j] %= MOD;
                }
            }
        }
        for(int i =0; i<60; ++i)
            for(int j =0; j<60; ++j){
                m[i][j] = new_m[i][j];
                new_m[i][j] = 0;
            }
    
        t/=2;
    }
    
    return ans[s][e];
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, S, E, T;
    cin >> N >> S >> E >> T;
    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            char ch;
            cin >> ch;
            m[i][j] = ch-'0';
        }
    }
    matrix_modification(N);
    
    for(int i = 0; i<60; ++i)
        ans[i][i] = 1;
    
    cout << mul(T,S-1,E-1);
    
    return 0;    
} // Math, Graphs, Divide and Conquer for matrix multiplication