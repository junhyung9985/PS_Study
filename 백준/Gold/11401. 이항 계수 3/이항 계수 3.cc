#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod  = 1'000'000'007;

ll inv(ll n){
    ll p = mod -2;
    ll ret = 1;
    while(p){
        if(p%2){
            ret *= n;
            ret %= mod;
        }
        n *=  n;
        n %= mod;
        p/=2;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, K;
    cin >> N >> K;
    
    ll val = 1; 
    ll inverse = 1, inverse2 = 1;
    for(int i =1; i<=N; ++i){
        val *= i;
        val %= mod;
        if(i == K){
            inverse = inv(val);
        }
        if(i == N-K){
            inverse2 = inv(val);
        }
    }
    val *= inverse;
    val %= mod;
    val *= inverse2;
    val %= mod;
    cout << val;
    
    return 0;
}
// 페르마의 소정리, 분할 정복