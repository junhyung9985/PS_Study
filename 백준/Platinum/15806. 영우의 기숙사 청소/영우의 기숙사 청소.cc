#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
ll dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M, K, t;
    cin >> N >> M >> K >> t;

    vector<vector<vector<ll>>> v(2, vector<vector<ll>>(N, vector<ll>(N, -1)));
    deque<tuple<ll,ll,ll>> q;
    for(int i =0; i<M; ++i){
        ll x, y;
        cin >> x >> y;
        q.push_back({0, y-1,x-1});
        v[0][y-1][x-1] = 0;
    }

    while(!q.empty()){
        ll d, y, x;
        tie(d,y,x) = q.front();
        q.pop_front();
        if(v[d][y][x] == t) break;
        if(v[d][y][x] == 2) break;
        for(int k =0; k<8; ++k){
            ll n_y = y+dy[k], n_x = x+dx[k];
            if(n_y < 0 || n_y >= N || n_x <0 || n_x>= N) continue;
            v[1-d][n_y][n_x] = v[d][y][x]+1;
            q.push_back({1-d, n_y, n_x});
        }   
    }

    bool ans = true;
    while(K--){
        ll y, x;
        cin >> x >> y;
        ans = ans && (v[t%2][y-1][x-1] < 1);
    }

    if(ans) cout <<"NO";
    else cout <<"YES";
    
    return 0;
} // BFS
// 숨바꼭질5에서 좀 더 어려워진 버젼?