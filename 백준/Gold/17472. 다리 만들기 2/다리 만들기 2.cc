#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

ll p[100];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

bool u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return false;
    p[pa] = pb;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    cin >> N >> M;

    vector<vector<ll>> m(N, vector<ll>(M));
    vector<vector<ll>> vis(N, vector<ll>(M, -1));
    
    for(int i =0; i<N; ++i)
        for(int j =0; j<M;++j)
            cin >> m[i][j];

    ll g = 0;
    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            if(vis[i][j] != -1 || !m[i][j]) continue;
            vis[i][j] = g;
            deque<pair<ll,ll>> q;
            q.push_back({i,j});
            while(!q.empty()){
                ll y, x;
                tie(y,x) = q.front();
                q.pop_front();
                vis[i][j] = g;
                for(int k =0;k<4; ++k){
                    ll n_y = y+dy[k], n_x = x+dx[k];
                    if(n_y < 0 || n_y >= N || n_x < 0 || n_x >= M) continue;
                    if(!m[n_y][n_x] || vis[n_y][n_x] != -1) continue;
                    vis[n_y][n_x] = g;
                    q.push_back({n_y,n_x});
                }
            }
            ++g;
        }
    } // BFS로 각 섬들의 그룹을 파악

    priority_queue<tuple<ll,ll,ll>> pq;
    ll ans = 0;

    for(int i =0; i<N; ++i){
        for(int j =0; j<M; ++j){
            if(m[i][j]){
                for(int k =0; k<4; ++k){
                    ll y = i, x = j;
                    ll n_y = i, n_x = j;
                    while(true){    
                        n_y = y+dy[k], n_x = x+dx[k];
                        if(n_y < 0 || n_y >= N || n_x < 0 || n_x >= M) break;
                        if(vis[n_y][n_x] != -1){
                            pq.push({-(abs(n_y-i + n_x-j)-1), vis[i][j], vis[n_y][n_x]});
                            break;
                        } // 갔는데 다른 섬이 있다면 거기서 스톱
                        y = n_y, x = n_x;
                    }
                }
            }
        }
    } // O(NMNM) -> 100 * 100 이므로 가능


    for(int i =0; i<g; ++i)
        p[i] = i;
    // DSU  초기화

    while(!pq.empty()){
        ll c, a, b;
        tie(c,a,b) = pq.top();
        pq.pop();
        c *= -1;
        if(c < 2) continue;
        //cout << c <<" "<<a <<" "<<b<<"\n";
        if(u(a,b)) ans += c;
    } // MST -> Kruskal Algorithm

    for(int i =0; i<g ; ++i){
        for(int j =0; j<g; ++j){
            if(f(i) != f(j)) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << ans;

    return 0;
} // MST, BFS, DSU