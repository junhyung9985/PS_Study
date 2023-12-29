#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> sz;
vector<ll> p;

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

ll u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return 0;
    ll ret = sz[pa] * sz[pb];
    sz[pa] += sz[pb];
    sz[pb] = 0;
    p[pb] = pa;
    return ret;
}


int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M, Q;
    cin >> N >> M >> Q;
    
    p.resize(N+1);
    sz.resize(N+1, 1);
    vector<pair<ll,ll>> E(M);
    vector<bool> has_deleted(M, false);
    
    for(int i = 1; i<=N; ++i)
        p[i] = i;

    for(int i =0; i<M; ++i){
        ll a,b;
        cin >> a >> b;
        E[i] = {a,b};
    }
  
    vector<ll> query(Q);
    ll ans = 0;
    for(int i =0; i<Q; ++i){
        ll n;
        cin >> n;
        query[i] = n-1;
        has_deleted[n-1] = true;
    }
    
    for(int i =0; i<M; ++i){
        if(has_deleted[i]) continue;
        ll a, b;
        tie(a,b) = E[i];
        u(a,b);
    }
    
    for(int i = Q-1; i > -1; --i){
        ll now = query[i];
        has_deleted[now] = false;
        ll a, b;
        tie(a,b) = E[now];
        ans += u(a,b);
    }
    
    cout << ans;
    
    return 0;
} // Offline Query + DSU