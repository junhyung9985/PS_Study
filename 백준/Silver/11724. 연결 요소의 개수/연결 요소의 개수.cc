#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p[1001];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u(ll a, ll b){
    p[f(a)] = f(b);
    return;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    for(int i = 1 ; i<=n; ++i) p[i] = i;
    while(m--){
        ll a, b;
        cin >> a >> b;
        u(a,b);
    }
    ll ans = 0;
    for(int i = 1; i<=n; ++i) ans += (p[i] == i);
    cout << ans;

    return 0;
} // DSU