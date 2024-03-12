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

pair<ll,bool> u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return {sz[pa],false};
    if(sz[pa] < sz[pb]) swap(pa, pb);
    p[pb] = pa;
    sz[pa] += sz[pb];
    sz[pb] = 0;
    return {sz[pa],true};
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


    vector<vector<ll>> occupied(N+1, vector<ll>(N+1,0));
    vector<vector<ll>> dist(N+1, vector<ll>(N+1,-1));
    list<pair<ll,ll>> q;

    p.resize(K+1);
    sz.resize(K+1,1);
    ll maxx = 0;
    for(int i =0; i<K; ++i){
        if(occupied[start[i].first][start[i].second]){
            maxx = max(maxx, u(occupied[start[i].first][start[i].second], i+1).first);
        }
        occupied[start[i].first][start[i].second] = i+1;
        dist[start[i].first][start[i].second] = 0;
        q.push_back({start[i].first, start[i].second});
        p[i+1] = i+1;
    }    
    
    if(maxx == K){
        cout << 0;
        return 0;
    }

    ll ans = 0;
    
    while(!q.empty()){
        ll y,x;
        tie(y,x) = q.front();
        q.pop_front();
        vector<pair<ll,ll>> to_see;
        for(int k =0; k<4; ++k){
            ll ny = y + dy[k], nx = x + dx[k];
            if(ny <= 0 || nx <= 0 || ny > N || nx > N) continue;
            if(occupied[ny][nx]){
                if(dist[ny][nx] > dist[y][x]) continue;
                ll val;
                bool flag;
                tie(val,flag) = u(occupied[y][x], occupied[ny][nx]);
                //cout << y <<" "<<x <<" "<<ny <<" "<<nx<< " : " << val <<"\n";
                maxx = max(maxx, val);
                if(flag) ans = max(ans, max(dist[y][x], dist[ny][nx]));    
                if(maxx == K){
                    cout << ans;
                    return 0;
                }
                
            }
            else{
                occupied[ny][nx] = occupied[y][x];
                dist[ny][nx] = dist[y][x]+1;
                q.push_back({ny,nx});
            }
        }
        
    }

    return 0;
} // DSU, BFS, Smaller-to-Larger(?)