#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll N, K, M;
ll sz[100001];
ll p[100001];
vector<map<ll,ll>> vec;
ll cost = 0;
vector<ll> ans;

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u(ll a, ll b){
    ll pa = f(a);
    ll pb = f(b);
    if(pa == pb) return;

    if(sz[pa] < sz[pb]){
        ll tmp = pa;
        pa = pb;
        pb = tmp;
    } // Smaller-to-Larger
    p[pb] = pa;
    sz[pa] += sz[pb];
    sz[pb] = 0;

    for(auto itr : vec[pb]){
        if(vec[pa].find(itr.first) != vec[pa].end()){
            ans[itr.first] += vec[pa][itr.first] * itr.second * cost; 
        }
        else vec[pa][itr.first] = 0;
        vec[pa][itr.first] += itr.second;
        vec[pb].erase(itr.first);
    }

    return;
}

// Union-Find

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K >> M;
    vec.resize(N+1);
    ans.resize(K+1);
    for(int i =0; i<N; ++i){
        ll tmp;
        cin >> tmp;
        p[i+1] = i+1;
        sz[i+1] = 1;
        vec[i+1][tmp] = 1;
    }
    vector<tuple<ll,ll,ll>> q(M);
    for(int i =0; i<M; ++i){
        ll a,b,c;
        cin >> a >> b >> c;
        q[i] = {c,a,b};
    }

    sort(q.begin(), q.end(), greater<tuple<ll,ll,ll>>());
    
    for(int i =0; i<M; ++i){
        ll c,a,b;
        tie(c,a,b) = q[i];
        cost = c;
        u(a,b);
    }    

    for(int i =1; i<=K; ++i){
        cout << ans[i]<<"\n";
    }

    return 0;
} // Offline-Query, Union-Find, Smaller-to-Larger