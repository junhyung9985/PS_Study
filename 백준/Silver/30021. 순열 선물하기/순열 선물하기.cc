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

    if(N == 2){
        cout <<"NO";
        return 0;
    }
    cout << "YES\n";
    cout << "1";
    if(N > 2 ){
        cout << " 3 2 ";
    }
    for(int i =4; i<=N; ++i){
        cout <<i<<" ";
    }



    return 0;
}
/*



*/