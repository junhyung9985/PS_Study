#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

struct node{
    ll n, c, d;
};

struct cmp{
    bool operator() (node a, node b){
       return a.d < b.d; 
    }
};

bool cmp2(node a, node b){
    return a.d < b.d;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll T, N, M, K;;
    cin >> T;
    cin >> N >> M >> K;
    vector<vector<node>> E(N+1);
    vector<vector<ll>> dist(N+1, vector<ll>(M+1, INT_MAX));
    priority_queue<node, vector<node>, cmp> pq;
    
    node n;
    for(int i =0; i<K; i++){
        ll a, b, c, d;
        cin >> a >>b >> c >> d;
        n.n =b;
        n.c = c;
        n.d = d;
        E[a].push_back(n);
        //E[b].push_back({d,a,c});
    }
    
    for(int i =0; i<=N; ++i){
        sort(E[i].begin(), E[i].end(), cmp2);
    }
    
    for(int i =0; i<=M; i++)
        dist[1][i] = 0;
    node s;
    s.n = 1;
    s.d = 0;
    s.c = 0;
    pq.push(s);
    while(!pq.empty()){

        node n =  pq.top();
        pq.pop();
        n.d *= -1;
        if(dist[n.n][n.c] < n.d) continue;
        if(n.n == N) break;
                    
        for(node next : E[n.n]){
            ll n_c = next.c, n_d = next.d, n_n = next.n;
            if(next.c+n.c > M) continue;
            if(dist[next.n][next.c+n.c] <= next.d + n.d) continue;
            dist[next.n][next.c+n.c] = next.d+n.d;

            for(int i = n_c+n.c+1; i<=M; i++){
                if(dist[n_n][i] > n.d+n_d) dist[n_n][i] = n.d+n_d;
                else break;
            }
            node n_s;
            n_s.d = -n.d-n_d;
            n_s.n = n_n;
            n_s.c = n.c+n_c;
            pq.push(n_s);
        }
    }
    if(dist[N][M] == INT_MAX) cout << "Poor KCM";
    else cout << dist[N][M];


    return 0;
}
/*

DP + Dijkstra, Dijkstra with constraint of total cost

*/