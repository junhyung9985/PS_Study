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

    unordered_set<string> ss;

    for(int i =0; i<N; ++i){
        string s;
        cin >> s;
        string tmp = "";
        for(int j = s.size()-1; j>-1; --j){
            tmp = s[j]+tmp;
            if(ss.find(tmp) == ss.end()) ss.insert(tmp);
            else ss.erase(tmp);
        }
    }

    cout << ss.size()<<"\n";


    return 0;
}
/*

Implementait

*/