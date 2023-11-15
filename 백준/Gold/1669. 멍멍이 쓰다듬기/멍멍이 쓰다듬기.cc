#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll x, y;
    ll curr = 1;
    ll cnt = 0;
    cin >> x >> y;
    if(y == x){
        cout << 0;
        return 0;
    }
    while(y-x > 2*curr){
        y-=curr;
        x+=curr;
        cnt+=2;
        curr++;
    }
    if(y-x>curr) cnt+=2;
    else cnt++;
    cout << cnt<<"\n";

    
    return 0;
}
/*

1 2..3 .... 2 .. 1
y-x => 1 + 2 +... +2+1

이게 맞누...
*/