#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll Q;
    ll curr = 1;
    ll offset = 0;
    ll times = 1;

    cin >> Q;
    
    while(Q--){
        ll cmd, val;
        cin >> cmd;
        if(cmd < 3){
            cin >> val;
        }
        if(cmd == 0){
            offset+=val;
        }
        if(cmd == 1){
            offset *= val;
            times *= val;
        }
        if(cmd == 2){
            curr += val;
        }
        if(cmd == 3){
            cout << curr * times + offset <<"\n";
        }
    }    
        
    return 0;
}

/*

- 생각해보면 곱하기가 전부 양수만 있으므로 수들의 순서는 항상 유지됨.
- 그래서 그냥 맨 앞의 수가 얼마인지, 얼마나 더해졌는지, 얼마나 곱해졌는지를 따로 관리해주면 될듯.

Time Complexity : O(Q)

*/