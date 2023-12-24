#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<bool> p(1000001, false);
    vector<ll> prime;
    vector<ll> c4plus1;
    for(ll i = 2; i<=1'000'000; ++i){
        if(p[i]) continue;
        p[i] = true;
        prime.push_back(i);
        if(i%4 == 1 || i == 2) c4plus1.push_back(i);
        for(ll j = 2*i; j<= 1'000'000; j+=i){
            p[j] = true;
        }
    }
    
    ll L, U;
    while(cin >> L >> U){
        if(L == -1 && U == -1) break;
        ll count = upper_bound(prime.begin(), prime.end(), U) - lower_bound(prime.begin(), prime.end(), L);
        ll ans = upper_bound(c4plus1.begin(), c4plus1.end(), U) - lower_bound(c4plus1.begin(), c4plus1.end(), L);
        cout << L <<" "<< U <<" "<<count <<" "<<ans<<"\n";
    }
    
    return 0;
} // Sieve