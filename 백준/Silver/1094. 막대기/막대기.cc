#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    ll ans = 0;
    while(N > 0){
        if(N%2) ++ans;
        N /= 2;
    }
    cout << ans;    
    return 0;
} // Bitmasking, Math