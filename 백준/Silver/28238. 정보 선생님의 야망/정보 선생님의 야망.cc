#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<vector<ll>> v(N, vector<ll>(5));
    for(int i =0; i<N; ++i)
        for(int j =0; j <5; ++j)
            cin >> v[i][j];
    
    ll maxx = 0;
    ll a = 0 , b = 1 ;
    for(int i =0; i<5; ++i){
        for(int j =0; j<5; ++j){
            if(i == j) continue;
            ll cnt = 0;
            for(int k =0; k<N; ++k){
                if(v[k][i] && v[k][j]) ++ cnt;
            }
            if(maxx < cnt){
                a = i;
                b = j;
            }
            maxx = max(maxx, cnt);
        }
    }
    
    cout << maxx<<"\n";
    for(int i =0; i<5; ++i)
        cout << (int)((i==a) || (i==b)) <<" ";

    return 0;
} // Bruteforcing