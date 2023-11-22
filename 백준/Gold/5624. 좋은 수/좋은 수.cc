#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<ll> v(N);
    vector<ll> pos(200001), neg(200001);
    vector<bool> check(N, false);
    
    for(int i =0; i<N; ++i)
        cin >> v[i];
    
    
    ll ans = 0;
    
    for(int i =0; i<N; ++i){
        for(int j=0; j<=i; ++j){
            ll val = v[i]+v[j];
            if(val >=0) pos[val] = 1;
            else neg[-val] = 1;
        }
        for(int j =i+1; j<N; ++j){
            ll f = v[j]-v[i];
            if(f < 0){
                if(neg[-f]) check[j] = true;
            }
            else if(pos[f]) check[j] = true;
        }
    }
    
    for(int i =0; i<N; ++i)
        if(check[i]) ++ans;
    
    cout <<ans;
    return 0;
}
/* MITM...? */
