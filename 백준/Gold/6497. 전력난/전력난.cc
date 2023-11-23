#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p[200001];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

bool u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return false;
    p[pb] = pa;
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        
        ll N,M, ans = 0;
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        
        for(int i = 0; i<N; ++i)
            p[i] = i;
        
        vector<tuple<ll,ll,ll>> roads(M);
        
        ll total = 0;
        
        for(int i =0; i<M; ++i){
            ll a, b, c;
            cin >> a >> b >> c;
            roads[i] = {c,a,b};
            total += c;
        }
        sort(roads.begin(), roads.end());
        
        for(int i =0; i<M; ++i){
            ll w,a,b;
            tie(w,a,b) = roads[i];
            if(u(a,b)) ans += w;
        }
        
        cout << total - ans<<"\n";
    }
    return 0;
} // MST