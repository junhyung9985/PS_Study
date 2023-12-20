#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, I, M;
    cin >> N >> I >> M;
    
    I/=2;
    
    vector<pair<ll,ll>> v(M);
    for(int i =0; i<M; ++i)
        cin >> v[i].first >> v[i].second;
    
    
    ll ans = 0;
    
    for(int i =0; i<M; ++i){
        for(int j =0; j<M; ++j){
            ll y = v[i].first, x = v[j].second;
            for(int i = 1; i<I; ++i){
                ll n_y = y+i, n_x = x+I-i;
                ll tmp = 0;
                for(int k = 0; k<M; ++k){
                    if(y <= v[k].first && v[k].first <= n_y && x <= v[k].second && v[k].second <= n_x){
                        ++tmp;
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }
    
    cout << ans;
    
    return 0;
} // O(M^3I/2)
// Bruteforcing