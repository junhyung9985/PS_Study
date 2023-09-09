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
    string s;
    string p;
    getline(cin , s);
    getline(cin, p);
    vector<ll> kmp(p.length());
    int j = 0;
    for(int i =1; i< p.length(); i++){
        while(j > 0 && p[i] != p[j]){
            j = kmp[j-1]; // kmp[j]도 p[j] 랑 동일하므로!
        }
        if(p[i] == p[j]){
            kmp[i] = ++j; // i+1번째에 틀렸으면 i번째까지는 j랑 맞으므로 j+1번째 부터 보면 됨.
        }
    }

    // for(int i =0; i<p.length(); i++){
    //     cout << kmp[i] <<" ";
    // }
    // cout<<"\n";

    vector<ll> ans;
    j = 0;

    for(int i =0; i<s.length(); i++){
        while( j > 0 && s[i] != p[j]){
            j = kmp[j-1];
            //cout<< j<<"\n";
        }
        if(s[i] == p[j]){
            if(j == p.length()-1){
                ans.push_back(i-p.length()+2);
                j = kmp[j];
            }
            else j++;
        }
       // cout << j <<" ";

    }

    //  cout<<"\n";
    cout << ans.size()<<"\n";
    for(int idx : ans){
        cout << idx<<"\n";
    }


    return 0;
}
/*
https://blog.naver.com/PostView.naver?blogId=ndb796&logNo=221240660061&parentCategoryNo=&categoryNo=128&viewDate=&isShowPopularPosts=false&from=postView
*/