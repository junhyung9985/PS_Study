#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<ll> p;
    for(int i = 2; i<=1000; ++i){
        bool flag = true;
        for(int j = 2; j<i; ++j){
            flag = flag && (i%j);
        }
        if(flag) p.push_back(i);
    }
    
    ll T;
    cin >> T;
    
    while(T--){
        ll K;
        cin >> K;
        bool flag = false;
        for(auto itr : p){
            for(auto itr2 : p){
                for(auto itr3 : p){
                    if(itr + itr2 + itr3 == K){
                        cout << itr <<" "<<itr2 <<" "<<itr3<<"\n";
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) cout << 0 <<"\n";
    }
    
    return 0;
} // Number Theory, Implementation(?)