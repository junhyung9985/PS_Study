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
    map<string, string>m;
    m["Algorithm"] = "204";
    m["DataAnalysis"] = "207";
    m["ArtificialIntelligence"] = "302";
    m["CyberSecurity"] = "B101";
    m["Network"] = "303";
    m["Startup"] = "501";
    m["TestStrategy"] = "105";
    ll N;
    cin>> N;
    for(int i =0; i<N; ++i){
        string s;
        cin >> s;
        cout << m[s]<<"\n";
    }

    return 0;
} // Implementation, Hash_Map(?), String