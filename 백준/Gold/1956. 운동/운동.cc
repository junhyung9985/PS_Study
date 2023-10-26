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
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> v(N, vector<ll>(N, INT_MAX));
    for(int i =0;i <M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        v[a-1][b-1] = c;
    }
    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++)
            for(int k =0; k<N; k++)
                v[j][k] = min(v[j][k], v[j][i]+v[i][k]);
    
    ll minn = INT_MAX;
    for(int i =0; i<N; i++)
        minn = min(minn, v[i][i]);
    
    if(minn == INT_MAX) minn = -1;
    cout << minn;

    return 0;
}