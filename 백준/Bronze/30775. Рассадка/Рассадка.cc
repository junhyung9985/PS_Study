#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> v;
vector<ll> q;
    

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll M, K;
    cin >> M >> K;
    
    ll total = 0;
    for(int i =0; i<K; ++i){
        ll tmp;
        cin >> tmp;
        total += tmp;
    }
    ll ans = total / M;
    if(total%M) ++ans;
    cout << ans;
    
    return 0;
}
/*

Ad_hoc, Math

*/
