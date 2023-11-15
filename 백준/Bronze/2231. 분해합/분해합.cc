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

    for(ll i = 1; i<=N; ++i){
        ll tmp = i;
        ll ret = tmp;
        while(tmp > 0){
            ret += tmp%10;
            tmp /= 10;
        }
        if(ret == N){
            cout << i;
            return 0;
        }
    }
    cout << 0;

    return 0;
} // Bruteforcing