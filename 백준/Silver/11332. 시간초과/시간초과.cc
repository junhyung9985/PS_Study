#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool can(string s, ll n, ll t, ll l){
    if(s == "O(N)"){
        return (t*n <= l * 100'000'000);
    }
    if(s == "O(N^2)"){
        if(n >= 40000) return false;
        return (t*n*n <= l * 100'000'000);
    }
    if(s == "O(N^3)"){
        if(n >= 1001)  return false;
        return (t*n*n*n <= l * 100'000'000);
    }
    if(s == "O(2^N)"){
        if(n >= 31) return false;
        ll N =1;
        for(int i =0; i<n; ++i)
            N *= 2;
        return (t * N <= l * 100'000'000);
    }
    if(s == "O(N!)"){
        if(n >= 13) return false;
        ll N = 1;
        for(ll i = 1; i<=n; ++i) N *= i;
        return (t*N <= l * 100'000'000);
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--){
        string o;
        ll n, t, l;
        cin >> o;
        cin >> n >> t >> l;
        if(can(o,n,t,l)) cout <<"May Pass.\n";
        else cout <<"TLE!\n";
    }
    return 0;
} // Case-Working, Parsing