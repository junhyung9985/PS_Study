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
    ll N, M;
    cin >> N >> M;
    vector<set<ll>> rec(M, set<ll>());
    vector<ll> rec_to_mul(M);
    vector<vector<ll>> related(N+1);
    vector<bool> visited(N+1, false);
    for(int i =0; i<M; ++i){
        ll n;
        cin >> n;
        for(int j=0;j<n; ++j){
            ll tmp;
            cin >> tmp;
            rec[i].insert(tmp);
            related[tmp].push_back(i);
        }
        cin >> rec_to_mul[i];
    }
    
    ll n;
    cin >> n;
    deque<ll> q(n);
    for(int i =0; i<n;++i){
        cin >> q[i];
        visited[q[i]] = true;
    }
    
    while(!q.empty()){
        ll mul = q.front();
        q.pop_front();
        for(int j : related[mul]){
            rec[j].erase(mul);
            if(rec[j].empty()){
                ll ret = rec_to_mul[j];
                if(!visited[ret]){
                    visited[ret] = true;
                    q.push_back(ret);
                }
            }
        }
    }

    vector<ll> ans;
    for(int i =1; i<=N; ++i){
        if(visited[i]) ans.push_back(i);
    }
    cout << ans.size()<<"\n";
    for(int i : ans)
        cout << i <<" ";

    return 0;
} // Topological Sort