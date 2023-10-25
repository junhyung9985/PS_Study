#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> p(1000001, false);
    vector<bool> primes(1000001, false);
    vector<ll> primes2;
    for(ll i = 2; i<=1000000; ++i){
        if(p[i]) continue;
        p[i] = true;
        primes[i] = true;
        primes2.push_back(i);
        for(int j = i*2; j<=1000000; j+=i)
            p[j] = true;
    } // Sieve

    ll T;
    cin >> T;
    while(T--){
        ll q;
        cin >> q;

        ll ans = 0;
        ll ans2 = 0;
        for(int i : primes2){
            if(i > q) break;
            if(q-i == i) ++ans2;
            else if(primes[q-i]) ++ans;
            
        }
        cout << ans/2+ans2 <<"\n";
    }

    return 0;
} // Math, Prime Number, Sieve