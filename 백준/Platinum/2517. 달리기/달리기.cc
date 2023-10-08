#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    ordered_set s;
    for(int i =0; i<N; ++i){
        ll a, lower;
        cin >> a;

        s.insert(a);
        lower = s.order_of_key(a+1);
        cout << s.size()-lower+1<<"\n";
    }

    return 0;
} // PBDS solution -> 아마 Segment tree + 좌표압축 + 이분탐색 이게 정해일거임.