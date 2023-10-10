#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N;
    vector<ll> a(N);
    for(int i =0; i<N; ++i){
        cin >> a[i];
    }
    
    ll ans = 0;
    
    for(ll i =0; i<30; ++i){
        ll val = ((ll)1 << i);
        ll tmp = 0;
        for(int i =0; i<N; ++i){
            if(val&a[i]){
                ++tmp;
            }
        }
        ans = max(ans, tmp);
    }
    
    cout << ans;
    
    return 0;
} // O(NlogN)