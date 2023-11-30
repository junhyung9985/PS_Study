#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M, K;
    cin >> N >> M >> K;

    vector<vector<ll>> E(N+M+3);
    vector<vector<ll>> f(N+M+3, vector<ll>(N+M+3));
    vector<vector<ll>> c(N+M+3, vector<ll>(N+M+3));
    
    for(int i =1; i<=N; ++i){
        ll t;
        cin >> t;
        for(int k = 0; k<t; ++k){
            ll m;
            cin >> m;
            E[i].push_back(N+m);
            E[N+m].push_back(i);
            c[i][N+m] = 1;
        }
        E[0].push_back(i);
        E[i].push_back(0);
        c[0][i] = 1; // 기본 개수
        E[N+M+2].push_back(i);
        E[i].push_back(N+M+2);
        c[N+M+2][i] = K; // 벌점을 추가적으로 받아 더 일할 수 있는 최대 개수
    }
    E[N+M+2].push_back(0); E[0].push_back(N+M+2);
    c[0][N+M+2] = K;

    for(int i = 1; i<=M; ++i){
        E[N+i].push_back(N+M+1);
        E[N+M+1].push_back(N+i);
        c[N+i][N+M+1] = 1;
    }    

    ll s = 0, e = N+M+1;
    ll ans = 0;
    while(true){
        vector<ll> visited(N+M+3, -1);
        deque<ll>q;
        q.push_back(s);
        while(!q.empty()){
            ll n = q.front();
            q.pop_front();
            for(auto itr : E[n]){
                if(visited[itr] == -1 && c[n][itr] - f[n][itr] > 0){
                    visited[itr] = n;
                    q.push_back(itr);
                    if(itr == e) break;
                }
            }
        }

        if(visited[e] == -1) break;
        ll curr = e;
        ll minn = INT_MAX;
        while(curr != s){
            ll bef = visited[curr];
            minn = min(minn, c[bef][curr] - f[bef][curr]);
            curr = bef;
        }
        curr = e;
        while(curr != s){
            ll bef = visited[curr];
            f[bef][curr] += minn;
            f[curr][bef] -= minn;
            curr = bef;
        }
        ans += minn;    
    }
    cout << ans;

    return 0;
} // Max-Flow