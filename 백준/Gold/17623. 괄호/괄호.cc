#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

bool cmp (string a, string b){
    if(a.size() == b.size()){
        return a < b;
    }
    return a.size() < b.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v(1001, "");
    
    for(int i = 0; i<=1000; ++i){
        string curr = v[i];
        ll n = i;
        
        if(n > 0){
            if(2*n <= 1000){
                if(cmp("1"+curr+"2", v[2*n]) || v[2*n] == ""){
                    v[2*n] = "1"+curr+"2";
                }
            }
            if(3*n <= 1000){
                if(cmp("3"+curr+"4" , v[3*n]) || v[3*n] == ""){
                    v[3*n] = "3"+curr+"4";
                }
            }
            if(5*n <= 1000){
                if(cmp("5"+curr+"6" , v[5*n]) || v[5*n] == ""){
                    v[5*n] = "5"+curr+"6";
                }
            }
        }
        if(n+1 <= 1000){
            string add_what = "12"+curr;
            if(cmp(curr+"12" , add_what)) add_what = curr+"12";
            if(cmp(add_what , v[n+1]) || v[n+1] ==""){
                v[n+1] = add_what;
            }
        }
        if(n+2 <= 1000){
            string add_what = "34"+curr;
            if(cmp(curr+"34" , add_what)) add_what = curr+"34";
            if(cmp(add_what , v[n+2]) || v[n+2] ==""){
                v[n+2] = add_what;
            }
        }        
        if(n+3 <= 1000){
            string add_what = "56"+curr;
            if(cmp(curr+"56" , add_what)) add_what = curr+"56";
            if(cmp(add_what , v[n+3]) || v[n+3] ==""){
                v[n+3] = add_what;
            }
        }
    }


    ll T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;
        for(int i =0 ;i<v[N].size(); ++i){
            char ch = v[N][i];
            if(ch == '1') cout <<"(";
            if(ch == '2') cout <<")";
            if(ch == '5') cout<<"[";
            if(ch == '6') cout <<"]";
            if(ch == '3') cout <<"{";
            if(ch == '4') cout <<"}";
        }
        cout<<"\n";
    }

    
    return 0;
} // BFS