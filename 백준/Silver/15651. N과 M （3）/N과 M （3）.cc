#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll N, M;
vector<ll> v;
void BACK(ll t, ll idx){
    if(t == M){
        for(int i =0; i<M; i++){
            cout << v[i] <<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i = 1; i<=N; i++){
        v.push_back(i);
        BACK(t+1, i);
        v.pop_back();
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    BACK(0,1);
    return 0;
}
/*

Backtracking

*/