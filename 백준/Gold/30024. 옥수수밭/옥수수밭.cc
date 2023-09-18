#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll dy[4] = {1,-1,0,0};
ll dx[4] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    ll N, M;
    cin >> N >> M;
    
    vector<vector<ll>> v(N+1, vector<ll>(M+1));
    vector<vector<bool>> m(N+1, vector<bool>(M+1, false));
    for(int i =1; i<=N; ++i){
        for(int j =1; j<=M; ++j){
            cin >> v[i][j];
        }
    }
    
    priority_queue<tuple<ll,ll,ll>> pq;
    for(int i =1; i<=N; ++i){
        if(!m[i][1]) pq.push({v[i][1], i, 1});
        m[i][1] = true;
    
        if(!m[i][M]) pq.push({v[i][M], i, M});
        m[i][M] = true;
        
    }    
    
    for(int i =1; i<=M; ++i){
        if(!m[1][i]) pq.push({v[1][i], 1, i});
        m[1][i] = true;
    
        if(!m[N][i]) pq.push({v[N][i], N, i});
        m[N][i] = true;
    }
    
    ll K;
    cin >> K;
    while(K--){
        ll val, a, b;
        tie(val, a, b) = pq.top();
        pq.pop();
        cout << a <<" "<<b<<"\n";
        for(int i =0; i<4; ++i){
            ll n_a = a+dy[i];
            ll n_b = b+dx[i];
            if(n_a <= 0 || n_a >N || n_b <= 0 || n_b > M) continue;
            if(m[n_a][n_b]) continue;
            m[n_a][n_b] = true;
            pq.push({v[n_a][n_b], n_a, n_b});
        }
    }

    return 0;
}
/*



*/