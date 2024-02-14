#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<ll> p(N);
    for(int i =0; i<N; ++i){
        cin >> p[i];
    }
    
    ll K;
    cin >> K;
    
    ll ans = 0;
    for(int i =0; i<N; ++i){
        ll prime = p[i];
        ll d = prime;
        while(K/d){
            ans += K/d;
            d *= prime;
        }
    }
    cout << ans;
    
    
    return 0;
} // Case-working, Implementation