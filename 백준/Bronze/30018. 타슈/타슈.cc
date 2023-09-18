#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);
    
    for(int i =0; i<N; ++i){
        cin >> a[i];
    }
    for(int i =0; i<N; ++i){
        cin >> b[i];
        a[i] -= b[i];
    }
    
    ll ans = 0;
    for(int i =0; i<N; ++i){
        ans += abs(a[i]);
    }
    
    cout << ans / 2;
    
    
    return 0;
}