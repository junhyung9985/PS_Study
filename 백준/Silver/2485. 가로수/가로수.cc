#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<ll> v(N);
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }
    
    ll gcd = v[1]-v[0];
    for(int i =2; i<N; ++i){
        gcd = __gcd(gcd, v[i] - v[i-1]);
    }
    
    ll ans = 0;
    for(int i =1; i<N; ++i){
        ll cnt = (v[i]-v[i-1])/gcd - 1;
        ans += cnt;
    }
    cout << ans;
    return 0;
} // Math, Euclidean Algorithm