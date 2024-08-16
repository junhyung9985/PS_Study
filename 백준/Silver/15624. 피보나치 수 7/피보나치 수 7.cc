#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fib[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    cout.precision(16);
    cout<<fixed;
    
    ll N;
    cin >> N;
    ll mod = 1'000'000'007;
    
    fib[0] = 0;
    fib[1] = 1;
    for(int i =2; i<=N; ++i){
        fib[i] = fib[i-1]+fib[i-2];
        fib[i] %= mod;
    }
    cout << fib[N]<<"\n";

    return 0;
} // Math, DP
