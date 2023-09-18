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
    ll A, B;
    cin >> A >> B;
    if(A <= B || A > 2*B){
        cout <<"NO";
        return 0;
    }
    cout << "YES\n";
    vector<string> ans;
    while(B+1 != A){
        ans.push_back("aba");
        A-=2;
        B-=1;
    }
    cout << ans.size()+1<<"\n";
    for(string s : ans){
        cout << s<<"\n";
    }
    for(int i =0; i<B; ++i){
        cout << "ab";
    }
    cout<<"a"<<"\n";


    return 0;
}
/*
2,1 
3,2 
4,3
5,4

8 6
6 5 


8,4 -> 2,1 2,1 

85 -> 4,3 3,2 



*/