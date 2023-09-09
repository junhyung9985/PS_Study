#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<vector<pair<ll,ll>>> p(1001, vector<pair<ll,ll>>(1001));
vector<vector<ll>> vals (1001, vector<ll>(1001));
vector<vector<bool>> activated(1001, vector<bool>(1001,false));
ll s = 0;

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

pair<ll,ll> f(pair<ll,ll> n){
    if(p[n.first][n.second] == n) return p[n.first][n.second];
    return p[n.first][n.second] = f(p[n.first][n.second]);
}

void u(pair<ll,ll> a, pair<ll,ll>b){
    pair<ll,ll> pa = f(a);
    pair<ll,ll> pb = f(b);
    if(pa == pb) return;
    p[pb.first][pb.second] = pa;
    s-= vals[pa.first][pa.second];
    s-=vals[pb.first][pb.second];
    
    vals[pa.first][pa.second] ^= vals[pb.first][pb.second];
    s += vals[pa.first][pa.second];

    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    ll ans = 0;
    cin >> N >> M;
    vector<tuple<ll,ll,ll>> v(N*M);

    for(ll i =0; i<N; i++)
        for(ll j =0; j<M; j++){
            ll val;
            cin >> val;
            v[i*M+j] = {val, i, j};
            p[i][j] = {i,j};
            activated[i][j] = false;
            vals[i][j] = val;
        }

    sort(v.begin(), v.end(), greater<tuple<ll,ll,ll>>());

    ll bef = get<0>(v[0]);

    for(int i =0; i<N*M; i++){
        ll a, y, x;
        tie(a, y, x) = v[i];
        if(bef != a){
            ans = max(ans, s);
        }
        activated[y][x] = true;
        s+= a;
        for(int k = 0; k<4; k++){
            int n_y = y+dy[k];
            int n_x = x+dx[k];
            if(n_y < 0 || n_y >= N) continue;
            if(n_x < 0 || n_x >= M) continue;
            if(!activated[n_y][n_x]) continue;
            u({n_y,n_x}, {y,x});
        } 
        bef = a;
    }
   
    ans = max(ans, s);

    cout << ans <<"\n";

    return 0;
}
/*

DSU + Offline Query 

(작은 것부터 빼는게 아니라 역순으로 큰 순서대로 더한다고 생각하면 됨!)

*/