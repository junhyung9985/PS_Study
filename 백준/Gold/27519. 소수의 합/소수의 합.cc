#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll d[100001];
bool primes[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<ll> p;
    for(int i=2; i<=100000; ++i){
        if(primes[i]) continue;
        primes[i] = true;
        p.push_back(i);
        for(int j =i*2; j<=100000; j+=i){
            primes[j] = true;
        }
    }

    d[0] = 1;
    for(ll prime : p){
        for(int i = 0; i<=100000-prime; ++i){
            d[i+prime] += d[i];
            d[i+prime] %= 1000000007;
        }
    }

    ll T;
    cin >> T;
    while(T--){
        ll c;
        cin >> c;
        cout<<d[c]<<"\n";
    }
    
    return 0;
}/*

2, 3, 5 ... 순서대로 계속 더한 결과를 찾으면 될듯?

*/