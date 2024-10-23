#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    vector<ll> ans;
    for(ll i =0; i<=1000000;++i){
        ll tmp = i;
        ll sz = 0;
        ll backward = 0;
        while(tmp){
            ++sz;
            backward = backward * 10 + tmp%10;
            tmp/=10;
        }
        tmp = i;
        for(int j =0; j<sz; ++j) tmp *= 10;
        if(tmp != 0){
            ans.push_back(tmp + backward);
        }
        for(int j = 0; j<=9; ++j){
            if(tmp == 0 && j == 0) continue;
            ll ack = j;
            for(int k = 0; k<sz; ++k) ack *= 10;
            ans.push_back(tmp*10 + ack + backward);
        }
    }
    
    sort(ans.begin(), ans.end());
    //cout << ans.size()<<"\n";
    ll idx = upper_bound(ans.begin(), ans.end(), n) - ans.begin();
    cout << idx<<"\n";
    
        

    return 0;
}