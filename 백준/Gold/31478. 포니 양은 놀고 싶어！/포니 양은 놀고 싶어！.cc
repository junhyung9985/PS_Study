#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll power(ll n, ll k, ll mod){
    ll ret = 1;
    while(k){
        if(k%2){
            ret *= (n%mod);
            ret %= mod;
        }
        n *= (n%mod);
        n %= mod;
        k /= 2;
    }
   // cout << n << " "<< k<<" "<<mod <<" "<<ret<<"\n";
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c, l, k;
    cin >> a >> b >> c >> k >> l;
    
    ll ans = 0, pow_a = 0, div_a = 0, offset_1 = 0, offset_2 = 0;
    
    pow_a = power(b,c,6);
    offset_1 = power(a, pow_a, 7);
    
    if((offset_1+k)%7 == l) ++ans;
    
    offset_2 = power(b,c,7);
    div_a = power(a,5,7);
    
    offset_2 *= div_a;
    offset_2 %= 7;
    
    if((offset_2+k)%7 == l) ans += 2;
    
    cout << ans;
    
    return 0;
} // Number Theory, FLT, Modular Inverse