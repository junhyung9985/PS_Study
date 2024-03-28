#include <iostream>
#define ll long long
using namespace std;
ll dp[101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for(int i =6; i<=100; ++i){
        dp[i] = dp[i-1] + dp[i-5];
        //cout << dp[i]<<"\n";        
    }
    ll T;
    cin >> T;
    while(T--){
        int tmp;
        cin >> tmp;
        cout << dp[tmp]<<"\n";
    }
    
    return 0;
} // DP - 파도반 수열