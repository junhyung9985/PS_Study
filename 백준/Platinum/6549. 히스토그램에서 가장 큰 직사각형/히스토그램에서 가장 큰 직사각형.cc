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
    while(cin >> N){
        if(N == 0) break;
        vector<ll> v(N);
        vector<tuple<ll,ll>> v2(N);
        for(int i =0; i<N; i++){
            cin >> v[i];
            v2[i] = {-1,N-1};
        }

        deque<tuple<ll, ll>> stck;

        for(int i =0; i<N; i++){
            
            while(!stck.empty()){
                ll val, idx;
                tie(val, idx) = stck.back();
                if(val > v[i]){
                    get<1>(v2[idx]) = i-1;
                    get<0>(v2[i]) = get<0>(v2[idx]);
                    stck.pop_back();
                }
                else {
                    if(val < v[i]){
                        get<0>(v2[i]) = idx;
                    }
                    else get<0>(v2[i]) = get<0>(v2[idx]);
                    break;
                }
            }
            stck.push_back({v[i], i});
        }
        ll maxx =0;
        for(int i =0; i<N; i++){
            maxx = max(maxx, (get<1>(v2[i])-get<0>(v2[i]))*v[i]);
        }
        cout << maxx<<"\n";


    }


    return 0;
}