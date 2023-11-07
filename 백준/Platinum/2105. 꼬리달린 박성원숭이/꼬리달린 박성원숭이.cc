#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<ll> ans;
ll p[200001];
unordered_set<ll> sz[200001];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u(ll a, ll b, int t){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return;


    if((pa != 1 && sz[pa].size() < sz[pb].size()) || (pb == 1)){
        ll tmp = pa; pa = pb; pb = tmp;
    }
    
    p[pb] = pa;
    for(auto itr : sz[pb]){
        sz[pa].insert(itr);
        if(pa == 1) ans[itr] = t;
    }
    sz[pb].clear();
    
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> E(N+1);
    vector<pair<ll, ll>> E2(N+1);
    vector<bool> visited(N+1, false);
    for(int i =1; i<=N; ++i){
        ll a, b;
        cin >> a >> b;
        E[i] = {a,b};
        E2[i] = {a,b};
        p[i] = i;
        sz[i].insert(i);
    }

    vector<pair<ll, ll>> query(M);
    ans.resize(N+1, -1);
    for(int i =0; i<M; ++i){
        ll a, b;
        cin >> a >> b;
        query[i] = {a,b};
        if(b == 1) E2[a].first = -1;
        else E2[a].second = -1;
    }

    for(int i =1; i<=N; ++i){
        if(visited[i]) continue;
        visited[i] = true;
        deque<ll> q;
        q.push_back(i);
        while(!q.empty()){
            ll n = q.front();
            q.pop_front();
            ll n1 = E2[n].first, n2 = E2[n].second;
            if(n1 != -1){
                u(i, n1, -1);
                if(!visited[n1]){
                    visited[n1] = true;
                    q.push_back(n1);
                }
            }
            if(n2 != -1){
                u(i, n2, -1);
                if(!visited[n2]){
                    visited[n2] = true;
                    q.push_back(n2);
                }
            }
        }
    }

    for(ll i = M-1; i > -1; --i){
        ll a, b;
        tie(a, b) = query[i];
        if(b == 1) {
            u(a, E[a].first, i);
        }
        else {
            u(a, E[a].second, i);
        }
    }

    for(int i =1; i<=N; ++i){
        cout << ans[i]<<"\n";
    }

    return 0;
} // Offline Query, DSU