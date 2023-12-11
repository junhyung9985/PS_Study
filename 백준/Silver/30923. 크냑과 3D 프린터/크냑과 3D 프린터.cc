#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    ll ans = 2*N;
    
    vector<ll> v(N+2);
    for(int i =1; i<=N; ++i){
        cin >> v[i];
        ans += 2 * v[i];
    }
    for(int i =1; i<=N; ++i){
        ans += max(v[i]-v[i-1], (ll)0);
        ans += max(v[i]-v[i+1], (ll)0);
    }
    cout << ans;
    
    
    return 0;
} // Math