#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b;
    while(cin >> a >> b){
        cout << b / (a+1)<<"\n";
    }
    return 0;
}