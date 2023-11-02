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
    string s;
    cin >> s;

    for(int i =0;i<N; ++i){
        cout << s;
    }

    return 0;
} // Ad_hoc -> 일단 동일한게 N번씩은 들어가는걸 포함해야하니 len(s)*N이 최선인 것은 알긴함.