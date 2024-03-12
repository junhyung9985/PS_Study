#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll dy[4] = {1,-1,0,0};
ll dx[4] = {0,0,1,-1};

vector<ll> p;
vector<ll> sz;

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

ll u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return sz[pa];
    if(sz[pa] < sz[pb]) swap(pa, pb);
    p[pb] = pa;
    sz[pa] += sz[pb];
    sz[pb] = 0;
    return sz[pa];
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, K;
    cin >> N >> K;
    vector<pair<ll,ll>> start(K);
    for(int i =0; i<K; ++i){
        cin >> start[i].first >> start[i].second;
    }

    ll l = -1, r = N*N+1;
    while(l+1 < r){
        ll mid = (l+r)/2;

        vector<vector<ll>> occupied(N+1, vector<ll>(N+1,0));
        list<tuple<ll,ll,ll>> q;

        p.resize(K+1);
        sz.resize(K+1,1);

        for(int i =0; i<K; ++i){
            occupied[start[i].first][start[i].second] = i+1;
            q.push_back({start[i].first, start[i].second, 0});
            p[i+1] = i+1;
        }    

        ll maxx = 0;
        
        
        while(!q.empty()){
            ll y,x,d;
            tie(y,x,d) = q.front();
            q.pop_front();
            for(int k =0; k<4; ++k){
                ll ny = y + dy[k], nx = x + dx[k];
                if(ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
                if(occupied[ny][nx]){
                    maxx = max(maxx, u(occupied[y][x], occupied[ny][nx]));
                }
                else if(d < mid){
                    occupied[ny][nx] = occupied[y][x];
                    q.push_back({ny,nx,d+1});
                }
            }
        }
        if(maxx == K) r = mid;
        else l = mid;

        p.clear();
        sz.clear();

    } // O((N^2+KlogK) * logN) = (4000000 * 11 * 11)

    cout << r;

    return 0;
} // Parametric Search, DSU, BFS, Smaller-to-Larger(?)