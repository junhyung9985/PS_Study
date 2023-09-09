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
    ll N, K;
    ordered_set s;
    cin >> N >> K;
    for(int i = 1; i<=N; i++)
        s.insert(i);
    
    ll cnt = K-1;
    cout <<"<";
    while(s.size()>1){
        auto n = s.find_by_order(cnt);
        cout << *n <<", ";
        s.erase(n);
        cnt += K-1;
        cnt %= s.size();
    }
    cout << *(s.find_by_order(0))<<">";

    return 0;
}
/*

*/