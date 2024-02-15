#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p[200000];
ll sz[200000];
ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return;
    if(sz[pa] < sz[pb]) swap(pa, pb);
    p[pb] = pa;
    sz[pa] += sz[pb];
    sz[pb] = 0;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q;
    cin >> N >> Q;
    vector<tuple<ll,ll,ll>> coords_x(N);
    vector<tuple<ll,ll,ll>> coords_y(N);
    
    for(int i = 0; i<N; ++i){
        p[i] = i, sz[i] = 1;
        
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        coords_x[i] = {x1, x2, i};
        coords_y[i] = {y1, y2, i};
    }
    sort(coords_x.begin(), coords_x.end());
    sort(coords_y.begin(), coords_y.end());
    
    ll g = -1, cover = -2'000'000'000;
    for(int i =0; i<N; ++i){
        ll s, e, idx;
        tie(s,e,idx) = coords_x[i];
        if(cover < s){
            g = idx;
            cover = e;
        }
        else {
            cover = max(cover, e);
        }
        u(idx, g);
    }
    
    g = -1, cover = -2'000'000'000;
    for(int i =0; i<N; ++i){
        ll s, e, idx;
        tie(s,e,idx) = coords_y[i];
        if(cover < s){
            g = idx;
            cover = e;
        }
        else {
            cover = max(cover, e);
        }
        u(idx, g);
    }
    
    while(Q--){
        ll a, b;
        cin >> a >> b;
        if(f(a-1) == f(b-1))cout << 1 <<"\n";
        else cout << 0 <<"\n";
    }
    
    return 0;
} // Greedy, Sorting, Sweeping