#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll N;
vector<vector<pair<ll,ll>>> E;
vector<ll> e;
vector<ll> ans;

vector<bool> visited;
vector<ll> tr;
vector<ll> e_need;
vector<ll> traversed;

ll update(ll n, ll s, ll e, ll idx){
    if(idx < s  || e < idx) return tr[n];
    if(s == e) return tr[n] = e_need[idx];
    ll mid = (s+e)/2;
    return tr[n] = update(2*n, s, mid, idx) + update(2*n+1, mid+1, e, idx);
}

ll query(ll n, ll s, ll e, ll idx){
    if (e < idx) return 0;
    if(  idx<=s) return tr[n];
    ll mid = (s+e)/2;
    return query(2*n, s, mid, idx) + query(2*n+1, mid+1, e, idx);
}


void DFS(ll n){
    traversed.push_back(n);
    visited[n] = true;
    ll l = -1, r = traversed.size()-1;
    while(l+1 < r){
        ll mid = (l+r)/2;
        if(query(1,0,N, mid) <= e[n]) r = mid;
        else l = mid;
    }

    ans[n] = traversed[r];

    for(int i =0; i<E[n].size(); i++){
        if(visited[E[n][i].first]) continue;
        ll nx, ne;
        tie(nx, ne) = E[n][i];
        e_need[traversed.size()-1] = ne;
        update(1,0,N,traversed.size()-1);
        DFS(nx);
        e_need[traversed.size()-1] = 0;
        update(1,0,N,traversed.size()-1);
    }
    traversed.pop_back();
    visited[n] = false;

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    e.resize(N);
    E.resize(N, vector<pair<ll,ll>>());
    ans.resize(N);
    e_need.resize(N+1);
    tr.resize(4*N+4);
    visited.resize(N, false);

    for(int i =0; i<N; i++)
        cin >> e[i];

    
    for(int i =0; i<N-1; i++){
        ll a, b, e;
        cin >> a >> b >> e;
        a--;
        b--;
        E[a].push_back({b,e});
        E[b].push_back({a,e});
    }

    DFS(0);

    for(int i =0; i<N; i++){
        cout << ans[i]+1<<"\n";
    }

    return 0;
}
/*

Segment Tree + Binary Search + DFS (Tree Traversal)

*/