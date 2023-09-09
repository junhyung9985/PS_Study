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
    ll N, M, K, Q;
    cin >> N >> M >> K >> Q;
    vector<map<ll,deque<pair<ll,ll>>>> v(N+1);
    vector<ll> ans(N+1, INT_MAX);
    vector<bool> visited(N+1, false);
    priority_queue<pair<ll,ll>> q;

    for(int i =0; i<M; i++){
        ll a, b;
        cin >> a >> b;
        v[a][b].push_back({1,-1});
        v[b][a].push_back({1,-1});
    }

    for(int i = 0; i<K; i++){
        ll a;
        cin>> a;
        ans[a] = 0;
        q.push({0,a});
    }

    vector<tuple<ll,ll,ll>> hist(Q);

    for(int i =0; i<Q; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        hist[i] = {a,b,c};
    }
    sort(hist.begin(), hist.end());
    for(int i =0; i<Q; i++){
        ll t, a, b;
        tie(t,a,b) = hist[i];
        
        if(v[a][b].empty()) v[a][b].push_back({t+1, -1});
        else if(v[a][b].back().second == -1) v[a][b].back().second = t;
        else v[a][b].push_back({t+1, -1});
        
        if(v[b][a].empty()) v[b][a].push_back({t+1, -1});
        else if(v[b][a].back().second == -1) v[b][a].back().second = t;
        else v[b][a].push_back({t+1, -1});

    }

    while(!q.empty()){
        ll val, a;
        tie(val, a)= q.top();
        q.pop();
        val *= -1;
        if(ans[a] < val) continue;
        ans[a] = val;
        //cout << a <<" "<< val<<"\n";
        for(auto itr : v[a]){
            ll next = itr.first;
            auto itr2 = itr.second;
            //if(ans[next] <= val+1) continue;
            while(!itr2.empty()){
                if((itr2.front().second < val+1) && (itr2.front().second != -1)) itr2.pop_front();
                else {
                    ll new_val = max(val+1, itr2.front().first);
                    if(new_val < ans[next]){
                        ans[next] = new_val;
                        q.push({-ans[next], next});
                    }
                    break;
                }
            }
            //cout << next<<"\n";
        }
    }
    
    for(int i =1; i<=N; i++){
        if(ans[i] == INT_MAX) ans[i] = -1;
        cout << ans [i]<<" ";
    }
    return 0;
}