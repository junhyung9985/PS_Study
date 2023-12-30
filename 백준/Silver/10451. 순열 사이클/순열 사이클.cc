#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll p[1001];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    p[pb] = pa;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        for(int i = 1; i<=N; ++i){
            p[i] = i;
        }
        for(int i = 1; i<=N; ++i){
            ll tmp;
            cin >> tmp;
            u(i, tmp);
        }
        ll cnt = 0;
        for(int i = 1; i<=N; ++i)
            if(f(i) == i) ++cnt;
        cout << cnt<<"\n";
    }
    
    return 0;
} // DSU