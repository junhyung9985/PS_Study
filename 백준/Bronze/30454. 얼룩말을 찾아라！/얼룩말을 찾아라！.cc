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

    multiset<ll> ms;
    for(int i =0; i<N; ++i){
        string s;
        cin >> s;

        char bef = '0';
        ll cnt = 0;
        for(char ch : s){
            if(ch != bef){
                if(ch == '1') ++cnt;
            }
            bef = ch;
        }
        ms.insert(cnt);
    }

    ll ans = *(ms.rbegin());
    ll cnt = ms.count(ans);

    cout << ans <<" "<<cnt;
    
    return 0;
} // Implemnetation