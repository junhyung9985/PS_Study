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
    vector<ll> ans(N);
    deque<pair<ll,ll>> fixed;
    multiset<ll> ms;

    for(int i =0; i<N; ++i){
        cin >> v[i];
        ms.insert(i+1);
    }    
    
    if(v[N-1] != N+1){
        cout << "No";
        return 0;
    }

    ll curr = 1;
    for(int i =0; i<N; ++i){
        if(v[i] != curr){
            fixed.push_back({i, curr});
            ms.erase(curr);
            curr = v[i];
        }
    }

    bool flag = true;
    ll curr_idx = 0;
    while(!fixed.empty()){
        ll idx, val;
        tie(idx, val) = fixed.front();
        fixed.pop_front();

        for(; curr_idx < idx ;curr_idx++){
            auto itr = ms.begin();
            ans[curr_idx] = *itr;
            ms.erase(itr);
        }
        if(!ms.empty()){
            auto itr = ms.begin();
            if(*itr < v[idx]){
                flag = false;
                break;
            }
        }
        ans[curr_idx++] = val; 
    }
    if(!flag){
        cout <<"No";
    }
    else {
        cout <<"Yes\n";
        for(auto itr : ans){
            cout << itr<<" ";
        }
    }

    return 0;
} // Constructive, Ad_hoc