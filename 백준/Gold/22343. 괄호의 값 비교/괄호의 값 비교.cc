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

    
    ll T;
    cin >> T;
    while(T--){
        string a, b;
        cin >> a >> b;
        
        set<ll> sa;
        set<ll> sb;
        sa.insert(0);
        sb.insert(0);

        ll depth = 0;
        bool up = true;
        for(char ch : a){
            if(ch == '('){
                depth++;
                up = true;
            }
            else {
                if(up){
                    ll tmp = depth;
                    while(sa.find(tmp) != sa.end()){
                        sa.erase(tmp);
                        ++tmp;
                    }
                    sa.insert(tmp);
                }
                up = false;
                --depth;
            }
        }

        depth = 0;
        up = true;
        for(char ch : b){
            if(ch == '('){
                depth++;
                up = true;
            }
            else {
                if(up){
                    ll tmp = depth;
                    while(sb.find(tmp) != sb.end()){
                        sb.erase(tmp);
                        ++tmp;
                    }
                    sb.insert(tmp);
                }
                up = false;
                --depth;
            }
        }
        
        
        ll max_a = *(sa.rbegin()), max_b = *(sb.rbegin());        
        while(max_a == max_b){
            if(max_a == 0 && max_b == 0) break;
            sa.erase(max_a);
            sb.erase(max_b);
            max_a = *(sa.rbegin());
            max_b = *(sb.rbegin());             
        }
        if(max_a == max_b) cout << "=\n";
        else if(max_a > max_b) cout << ">\n";
        else cout << "<\n";
        
    }

    return 0;
} // Tree_Set, Stack, Bitmasking(?)
// O(TNlogN)