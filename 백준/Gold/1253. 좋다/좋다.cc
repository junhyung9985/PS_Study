#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<ll> v(N);
    unordered_map<ll,ll> m;
    for(int i =0; i<N; ++i){
        cin >> v[i];
        if(m.find(v[i]) == m.end())m[v[i]] =0;
        ++m[v[i]];
    }
    
    ll ans =0;
    for(int i= 0; i<N; ++i){
        for(int j =0; j<N; ++j){
            if(i == j) continue;
            ll val = v[i]-v[j];
            ll least = 0;
            if(v[i] == val ) ++least;
            if(v[j] == val ) ++least;
            if(m[val] > least){
                ++ans;
                break;
            }
        }
    }
    
    cout << ans;
    
    return 0;
} // Bruteforcing, Tree_set