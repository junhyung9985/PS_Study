#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> p;
vector<ll> sz;
vector<bool> open;

ll f(ll n){
    if(p[n] == n){
        return n;
    }
    return p[n] = f(p[n]);
}

ll u(ll a, ll b){
    ll pa = f(a);
    ll pb = f(b);
    if(pa == pb) return sz[pa];
    if(sz[pa] < sz[pb]){
        ll tmp = pa;
        pa = pb;
        pb = tmp;
    }
    p[pb] = pa;
    sz[pa] += sz[pb];
    sz[pb] = 0;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    p.resize(N+1);
    open.resize(N+1);
    sz.resize(N+1);
    for(int i =1; i<=N; ++i){
        p[i] = i;
        sz[i] = 1;
    }
    vector<vector<ll>> E(N+1, vector<ll>());
    vector<bool> ans(N);
    vector<ll> q(N);
    for(int i =0; i<M; ++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    
    for(int i = 0; i<N; ++i){
        cin >> q[i];
    }
    
    ll cnt = 1;
    for(int i =N-1; i>-1; --i){
        open[q[i]] = true;
        for(ll next : E[q[i]]){
            if(open[next]){
                u(next, q[i]);
            }
        }
        ll pa = f(q[i]);
        if(sz[pa]== cnt) ans[i] = true;
        ++cnt;
    }
    for(int i =0; i<N; ++i){
        if(ans[i]) cout <<"CONNECT\n";
        else cout <<"DISCONNECT\n";
    }
    cout <<"DISCONNECT\n";
    
    return 0;
} // Offline-Query, DSU
