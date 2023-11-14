#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> // SGI extension
using namespace __gnu_cxx;
// Rope
 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    crope s;
    char tmp[100005];
    ll Q;

    cin >> tmp;
    cin >> Q;

    s = crope(tmp);

    while(Q--){
        ll q;
        cin >> q;
        if(q== 1){
            ll l, r;
            cin >> l >> r;
            s.insert(0, s.substr(l, r-l+1));
            s.erase(r+1, r-l+1);
        }
        if(q == 2){
            ll l, r;
            cin >> l >> r;
            s.insert(s.size(), s.substr(l, r-l+1));
            s.erase(l, r-l+1);
        }
        if(q == 3){
            ll x;
            cin >> x;
            cout << s[x]<<"\n";
        }
        //cout << s<<"\n";
    }
    
    return 0;
} // Rope