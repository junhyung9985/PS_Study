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
    ll N;
    cin >> N;
    vector<ll> v(N);
    vector<pair<ll,ll>> v2(N);
    deque<pair<ll,ll>> stck;
    for(int i =0; i<N; ++i){
        cin >> v[i];
        v2[i].first = i;
    }
    for(int i =0; i<N; ++i){
        while(!stck.empty()){
            if(stck.back().first >= v[i]){
                ll val, idx;
                tie(val, idx) = stck.back();
                stck.pop_back();
                v2[idx].second = i;
                v2[i].first = v2[idx].first;
            }
            else break;
        }
        stck.push_back({v[i],i});
    }
    while(!stck.empty()){
        ll val, idx;
        tie(val, idx) = stck.back();
        stck.pop_back();
        v2[idx].second = N;
    }

    ll ans = 0;
    for(int i =0; i<N; ++i){
        ans = max(ans, v[i]*(v2[i].second-v2[i].first));
    }
    cout << ans;

    return 0;
} // Monotone Stack
// 히스토그램에서 제일 큰 직사각형 찾기 문제