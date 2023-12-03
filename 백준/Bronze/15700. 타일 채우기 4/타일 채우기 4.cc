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
    ll N,M;
    cin >> N >> M;
    ll ans =  (N/2);
    ans *= M;
    if(N%2)
        ans += M/2;

    ll ans2 = (M/2);
    ans2 *= N;
    if(M%2) ans2 += N/2;
    cout << max(ans,ans2);
    return 0;
} // Math