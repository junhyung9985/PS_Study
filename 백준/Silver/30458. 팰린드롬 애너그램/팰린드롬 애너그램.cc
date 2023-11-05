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
    string s;

    cin >> N;
    cin >> s;

    vector<ll> s1(26);
    vector<ll> s2(26);

    for(int i =0; i<N/2; ++i){
        s1[s[i]-'a']++;
        s2[s[N-1-i]-'a']++;
    }

    bool can = true;
    for(int i =0; i<26; ++i){
        can = can && ((s1[i] + s2[i])%2 == 0);
    }
    if(can) cout << "Yes";
    else cout << "No";

    return 0;
} // Ad_hoc?