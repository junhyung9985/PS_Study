#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    multiset<ll> ms;
    ms.insert(0);
    ll XOR = 0, SUM = 0;
    
    ll Q;
    cin >> Q;
    
    while(Q--){
        ll q;
        cin >> q;
        if(q == 1){
            ll x;
            cin >> x;
            ms.insert(x);
            XOR ^= x;
            SUM += x;
        }
        if(q == 2){
            ll x;
            cin >> x;
            auto itr = ms.find(x);
            ms.erase(itr);
            XOR ^= x;
            SUM -= x;
        }
        if(q == 3){
            cout << SUM<<"\n";
        }
        if(q == 4){
            cout << XOR<<"\n";
        }
    }
    
    return 0;
} // Multiset, Implementation