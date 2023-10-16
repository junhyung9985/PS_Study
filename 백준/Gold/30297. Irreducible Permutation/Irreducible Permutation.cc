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
    while(T--){
        ll N;
        cin >> N;
        ll maxx = 0;
        vector<ll> ans;
        vector<ll> v(N);
        for(int i =0; i<N; ++i){
            cin >> v[i];
        }
        for(int i =0; i<N-1; ++i){
            maxx =max(v[i], maxx);
            if(maxx == i+1){
                ans.push_back(i+1);
            }
        }
        cout<<ans.size()<<"\n";
        for(int i : ans){
            cout<< i <<" ";
        }
        cout<<"\n";
    }

    return 0;
} // Ad_hoc