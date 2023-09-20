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
    
    v[1] = "12";
    v[2] = "34";
    v[3] = "56";
    
    
    for(int i = 4; i<=1000; ++i){
        v[i] = v[1] + v[i-1];
        for(int j = 1; j<i; ++j){
            if(cmp(v[j]+v[i-j], v[i])){
                v[i] = v[j]+v[i-j];
            }
        }
        if(i%2 == 0){
            if(cmp("1"+v[i/2]+"2", v[i])){
                v[i] = "1"+v[i/2]+"2";
            }
        }        
        if(i%3 == 0){
            if(cmp("3"+v[i/3]+"4", v[i])){
                v[i] = "3"+v[i/3]+"4";
            }
        }        
        if(i%5 == 0){
            if(cmp("5"+v[i/5]+"6", v[i])){
                v[i] = "5"+v[i/5]+"6";
            }
        }
    } // O(N^2) DP


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
} // DP