#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> v;
vector<ll> q;
    

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll W, N;
    cin >> W >> N;
    
    vector<ll> v(N);
    vector<bool> vis(799995);
    
    for(int i =0; i<N; ++i)
        cin >> v[i];
    
    for(int i =0; i<N; ++i){
        for(int j =i+1; j<N; ++j){
            ll f = W - v[i] - v[j];
            if(f < 0) continue;
            if(vis[f]){
                cout <<"YES";
                return 0;
            }
        }
        for(int j =0; j<i; ++j){
            vis[v[i]+v[j]]=true;
        }
    } // O(N^2)
    
    cout <<"NO";
    return 0;
}
/* MITM...? */
