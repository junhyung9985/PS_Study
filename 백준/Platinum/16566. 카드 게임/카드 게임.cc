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
    deque<ll> v(M);
    for(int i =0; i<M; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end());


    vector<pair<ll,ll>> q(K);
    priority_queue<ll, vector<ll>, greater<ll>> q2;
    vector<ll> ans(K);
    for(int i =0; i<K; ++i){
        cin >> q[i].first;
        q[i].second = i;
    }
    sort(q.begin(), q.end());

    int idx = 0;
    while(!v.empty()){
        ll n =  v.front();
        v.pop_front();
        if(idx < K){
            while(q[idx].first < n){
                q2.push(q[idx].second);
                ++idx;
                if(idx == K) break;
            }
        }
        if(!q2.empty()){
            ans[q2.top()] = n;
            q2.pop();
        }
        if(q2.empty() && idx == K) break;
    }

    for(int i =0; i<K; ++i){
        cout << ans[i]<<"\n";
    }
    return 0;
} // Offline Query, Sorting, Priority_Queue