#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> p;
vector<ll> sz;

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

bool u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return false;
    if(sz[pa] < sz[pb]){
        ll tmp = pa;
        pa = pb;
        pb = tmp;
    }
    p[pb] = pa;
    sz[pa] += sz[pb];
    sz[pb] = 0;
    return true;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    vector<tuple<ll,ll,ll>> E(M);
    p.resize(N+1);
    sz.resize(N+1);
    
    for(int i =0; i<M; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        E[i] = {c,a,b};
    }
    sort(E.begin(), E.end());
    
    ll Q;
    cin >> Q;
    vector<pair<ll,ll>> ans(Q, {get<0>(E[M-1]),N});
    vector<pair<ll,ll>> q(Q);
    vector<ll> lo(Q), hi(Q, M+1);
    
    for(int i =0; i<Q; ++i){
        ll a, b;
        cin >> a >> b;
        q[i] = {a,b};
    }
    
    while(true){
        bool is_finished = true;
        
        vector<vector<ll>> mids(M+1);
        for(int i =0; i<Q; ++i){
            if(lo[i]+1 < hi[i]){
                mids[(lo[i]+hi[i])/2].push_back(i);
                is_finished = false;
            }
        } // Parallel Binary Search
        
        if(is_finished) break;
        
        for(int i =1; i<=N; ++i){
            p[i] = i;
            sz[i] = 1;
        } // Initialize DSU
        
        for(int i =0; i<M; ++i){
            ll cost, a, b;
            tie(cost, a, b) = E[i];
            u(a,b);
            
            for(ll query : mids[i+1]){
                ll a, b;
                tie(a,b) = q[query];
                if(f(a) == f(b)) {
                    ans[query] = {cost, sz[f(a)]};
                    hi[query] = i+1;
                }
                else lo[query] = i+1;
            }
        } // Kruskal
    }
    
    for(int i =0; i<Q; ++i){
        if(lo[i] == M) cout << -1<<"\n";
        else cout << ans[i].first <<" "<<ans[i].second<<"\n";
    }
    
    return 0;
}
/* PBS, MST */
