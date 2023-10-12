#include <bits/stdc++.h>
#define ll long long

using namespace std;

string s;
bool can(int idx, ll len){
    //cout << idx <<" "<<len<<"\n";
    if(len == 1) return true;

    bool ret = true;
    for(int i =idx; i<len/2; ++i){
        ret = ret && (s[i] != s[idx+len-1-i]);
    }
    if(!ret) return ret;
    else return can(idx, len/2) && can(idx+len/2+1, len/2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll T;
    cin >> T;
    while(T--){
        cin >> s;
        bool flag = can(0, s.size());
        if(flag) cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}

/*

중앙 : 0 or 1 
이후 : 0 or 1 

*/