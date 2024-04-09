#include <bits/stdc++.h>
#define ll long long 
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    ll MOD = 1'000'000'007;

    cin >> N >> M;
    vector<vector<ll>> E(N, vector<ll>());
    vector<ll> depth(N, 0);
    vector<ll> depths(N+1, 0);

    for(int i =0; i<M; ++i){
        ll a, b;
        cin >> a >> b;
        --a; --b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    deque<pair<ll,ll>> q;
    q.push_back({0,1});
    depth[0] = 1;
    depths[1]++;
    while(!q.empty()){
        ll n, d;
        tie(n, d) = q.front();
        q.pop_front();
        for(int next : E[n]){
            if(!depth[next]){
                depth[next] = d+1;
                ++depths[d+1];
                q.push_back({next, d+1});
            }
        } 
    }
    ll ans = 1;
    for(int i =1 ; i<=N; ++i){
        ans *= (depths[i]+1);
        ans %= MOD;
    }
    ans +=(MOD-1);
    ans %= MOD;
    cout << ans<<"\n";
}