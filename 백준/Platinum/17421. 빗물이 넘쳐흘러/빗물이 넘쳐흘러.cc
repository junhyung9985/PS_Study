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

    ll N, K ;
    cin >> N >> K;

    vector<ll> v(N);
    vector<bool> check(N, false);
    vector<ll> cost(N);
    vector<ll> covers(N);
    deque<tuple<ll,ll,ll>> depth;
    for(int i=0; i<N; i++){
        cin >> v[i];
        if(i > 0 ) check[i] = v[i] > v[i-1];
    }
    ll ans = -1;
    ll bef = -1;
    multiset<ll> s;
    for(int i =0; i<N; i++){
        ll val = v[i];
        ll diff = 0;
        ans = -1;
        while(!depth.empty()){
            ll val2, idx2, dif2;
            tie(val2, idx2, dif2) = depth.back();

            if(val2 > val || (val2 == val && (!diff))){
                cost[i] += (dif2+1)*(val2-val) + cost[idx2];
                cost[idx2] = 0;
                s.erase(idx2);
                depth.pop_back();
                diff+= dif2+1;
            }
            else break;
        }
        if(cost[i]) {
            s.insert(i);
            bef = v[i];
        }
        covers[i] = diff;
        depth.push_back({val, i, diff});
        if(check[i]){
            if(s.size()>= K-1){
                int cnt = 0;
                for(auto itr : s){
                    cnt ++;
                    if(cnt == K) break;
                    ans += cost[itr];
                }
                cout << ans +1 ;
                return 0;
            }
        }
    }

    // if(bef < v[N-1]){
    //     s.insert(N-1);
    // }

    // if(s.size() >= K){
    //         int cnt = 0;
    //         for(auto itr : s){
    //             ans += cost[itr];
    //             cnt++;
    //             if(cnt > K-2) break;
    //         }
    //         cout << ans+1;
    //         return 0;
    // }
    cout << ans;

    return 0;
}
/*

Stack으로 풀기

*/