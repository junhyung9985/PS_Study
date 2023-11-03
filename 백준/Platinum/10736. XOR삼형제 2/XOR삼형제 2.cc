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
    ll T;
    cin >> T;
    
    vector<vector<ll>> ans(101, vector<ll>());
    for(int i =1; i<=100; ++i){
        
        ll tmp = i;
        ll cnt = 0;
        ll ans1 = 1;
        while(tmp){
            ++cnt;
            tmp/=2;
            ans1 *=2;
        }
        ans1 /= 2;
        ll ans2=  ans1/2;
        for(int j= 0; j<pow(2, cnt-2); ++j){
            ans1 ^= j;
            if(ans1>= 1 && ans1 <= i) ans[i].push_back(ans1);
            ans1 ^= j;
            ans2 ^= j;
            if(ans2>= 1 && ans2 <= i) ans[i].push_back(ans2);
            ans2 ^= j;
        }

    }
    
    
    while(T--){
        ll N;
        cin >> N;
        cout << ans[N].size()<<"\n";
        for(auto itr: ans[N]){
            cout << itr <<" ";
        }
        cout<<"\n";
    }

    return 0;
} // Greedy