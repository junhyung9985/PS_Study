#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll p[100001];
unordered_set<ll> sz[100001];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u(ll a,  ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return;
    if(sz[pa].size() < sz[pb].size()){
        ll tmp = pa; pa = pb; pb = tmp;
    }
    p[pb] = pa;
    for(auto itr : sz[pb]){
        sz[pa].insert(itr);
    }
    sz[pb].clear();
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, Q;
    cin >> N >> Q;
    
    vector<ll> parent(N+1);
    vector<ll> ind(N+1);
    vector<tuple<ll, ll, ll>> query(N-1+Q);

    for(int i =2; i<=N; ++i){
        ll n;
        cin >> n;
        parent[i] = n;    
        ind[n]++;
    }

    for(int i =1; i<=N; ++i){
        p[i] = i;
        ll c;
        cin >> c;
        sz[i].insert(c);
    }

    for(int i =0; i<N-1+Q; ++i){
        ll q, x;
        cin >> q >> x;
        if(q == 1){
            query[i] = {q,x, parent[x]};
            ind[parent[x]]--;
            parent[x] = 0;
        }
        else{
            query[i] = {q, x, 0};
        }
    }

    deque<ll> q;
    for(int i =1; i<=N; ++i){
        if(ind[i] == 0) q.push_back(i);
    }
    
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        
        ll par = parent[n];
        if(par == 0) continue;
        u(n, parent[n]);
        ind[parent[n]]--;
        if(ind[parent[n]] == 0) q.push_back(parent[n]);
    } // 초기 DSU 설정 -> Topological Sort

    for(int i = N-2+Q; i>-1; --i){
        ll q, a, b;
        tie(q,a,b) = query[i];
        if(q == 1){
            u(a, b);
        }
        else{
            ll pa = f(a);
            query[i] = {q,a,sz[pa].size()};
        }
    } // Offline Query

    for(int i =0; i<N-1+Q; ++i){
        ll q, a, b;
        tie(q,a,b) = query[i];
        if(q == 2) cout << b<<"\n";
    } // Print Answers

    return 0;
} // Offline Query, DSU, Smaller To Larger, Topological_Sort