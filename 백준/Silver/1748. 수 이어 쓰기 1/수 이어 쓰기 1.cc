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

    ll q = 9;
    ll cnt = 1;
    ll ans = 0;
    while(N > q){
        ans += cnt *(q-q/10);
        q = q*10+9;
        ++cnt;
    }
    ans += cnt *(N-q/10);
    cout << ans;

    return 0;
} // Math