#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll x,y;
    cin >> x >> y;
    if(x > 0){
        if(y > 0) cout << 1;
        else cout << 4;
    }
    else{
        if(y > 0) cout << 2;
        else cout << 3;
    }
    return 0;
}