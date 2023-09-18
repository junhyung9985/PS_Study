#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    return a.first - a.second > b.first - b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N,A,B;
    cin >> N >> A >> B;
    vector<pair<ll,ll>> v(N);
    ll ans = 0;
    for(int i =0; i<N; ++i){
        cin >> v[i].first >> v[i].second;
        ans += v[i].first;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i =0; i<B; ++i){
        ans -= v[i].first;
        ans += v[i].second;
    }
    
    cout << ans ;
    
    
    return 0;
}
/*

4+7+5+3+10 = 


2,1 
3,2 
4,3
5,4

8 6
6 5 


8,4 -> 2,1 2,1 

85 -> 4,3 3,2 



*/