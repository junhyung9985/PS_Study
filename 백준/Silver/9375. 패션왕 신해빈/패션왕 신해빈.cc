#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T;
    cin >> T;
    while(T--){
        ll N;
        unordered_map<string, ll> m;
        cin >> N;
        for(int i =0; i<N; ++i){
            string a, b;
            cin >> a >> b;
            ++m[b];
        }
        ll ans = 1;
        for(auto itr : m){
            ans = ans *(itr.second+1);
        }
        cout << ans-1<<"\n";
    }
    
    return 0;
} // Combinatorics, Hash Map 