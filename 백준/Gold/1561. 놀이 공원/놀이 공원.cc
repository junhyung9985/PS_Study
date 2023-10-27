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

    ll lcm = 1;

    ll N, M;
    cin >> N >> M;

    vector<ll> t(M);
    
    for(int i =0; i<M; ++i){
        cin >> t[i];
    }
    

    ll l = 0, r =  60000000001;
    while(l+1 < r){
        ll mid = (l+r)/2;
        ll total = 0;
        for(int i =0; i<M; ++i){
            total += mid/t[i];
            if(mid%t[i]) total ++;
        }
        if(total >= N){
            r = mid;
        }
        else l = mid;
        //cout << mid <<" "<<total<<"\n";
    }
    
    for(int i =0; i<M; ++i){
        N -= l/t[i];
        if(l%t[i]) --N;
    }
    //cout << l<<"\n";
    
    ll ans = 0;
    for(int i =0; i<M; ++i){
        if((l)%t[i] == 0){
            --N;
            ans = i+1;
            if(N == 0) break;
        }
    }
    cout << ans;
    

    return 0;
} 
// Binary Search