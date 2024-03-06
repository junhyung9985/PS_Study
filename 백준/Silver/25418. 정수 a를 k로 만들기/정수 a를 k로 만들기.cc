#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll A, K;
    cin >> A >> K;
    
    vector<ll> dp(K+1, K+1);
    dp[A] = 0;
    deque<ll> q;
    q.push_back(A);
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        if(2*n <= K){
            if(dp[2*n] > dp[n]+1){
                dp[2*n] = dp[n]+1;
                q.push_back(2*n);
            }
        }
        if(n+1 <= K){
            if(dp[n+1] > dp[n]+1){
                dp[n+1] = dp[n]+1;
                q.push_back(n+1);
            }
        }
    }
    cout << dp[K];

    return 0;
} // BFS