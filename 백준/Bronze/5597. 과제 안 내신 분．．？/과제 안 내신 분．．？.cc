#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<ll> v(31, 0);
    for(int i =0; i<28; ++i){
        ll a;
        cin >> a; v[a] = 1;
    }
    for(int i = 1; i<=30; ++i)
        if(v[i] == 0) cout << i <<"\n";
    return 0;
}