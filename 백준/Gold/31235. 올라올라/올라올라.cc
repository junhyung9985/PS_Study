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
    
    string s;
    ll N;
    cin >> N;
    
    vector<ll> v(N);
    for(int i =0; i<N; ++i)
        cin >> v[i];
    
    ll l = 0, r = N;
    while(l+1 < r){
        ll mid = (l+r)/2;
        bool flag = true;
        deque<pair<ll,ll>> q;
        ll bef = 0;
        for(int i =0; i<N; ++i){
            
            while(!q.empty()){
                if(q.front().second <= i - mid) q.pop_front();
                else break;
            }
            while(!q.empty()){
                if(q.back().second <= i-mid || q.back().first < v[i])
                q.pop_back();
                else break;
            } 
            q.push_back({v[i], i});
            if(i >= mid-1){
                if(bef > q.front().first) flag = false;
                bef = q.front().first;
            }
            //cout << bef <<" ";
        }
        //cout<<"\n";
        if(flag) r = mid;
        else l = mid;
    }
    cout << r;
    
    return 0;
} /*




*/