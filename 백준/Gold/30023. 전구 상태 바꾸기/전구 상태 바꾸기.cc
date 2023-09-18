#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

map<char, ll> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    string s;
    cin >> s;
    
    ll ans = -1;
    m['R'] = 0;
    m['G'] = 1;
    m['B'] = 2;

    vector<ll> curr(N);
    for(int i =0; i<N; ++i){
        curr[i] = m[s[i]];
    }
    
    for(int i =0; i<3; ++i){
        vector<ll> bef(N, i);
        ll tmp = 0;
        for(int j =0; j<N-2; ++j){
            if(curr[j] != bef[j]){
                ll k = (curr[j]-bef[j] + 3 )% 3;
                tmp += (bef[j]-curr[j] + 3 )% 3;
                bef[j] = (bef[j]+k)%3;
                bef[j+1] += k;
                bef[j+2] += k;
                bef[j+1] %= 3;
                bef[j+2] %=3;
            }    
        }
        bool flag = true;
        for(int j=0; j<N; ++j){
            //cout << bef[j]<<" ";
            flag = flag && (curr[j] == bef[j]);
        }
        if(flag){
            if(ans == -1) ans = tmp;
            ans = min(tmp, ans);
        }
    }
    
    cout << ans;    
    
    return 0;
}
/*

RRRR -> X

BBBB -> RRRB -> RGGR 

GGGG -> RRRG -> RGGB
RRRG -> 

RRRRR
BBBRR + 2
BGGBR + 2
BGRGB + 2





*/