#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll MOD = 1'000'000'007;
ll inv(ll n){
  ll ret = 1;
  ll p = MOD - 2;
  while(p){
    if(p%2) {
      ret *= n;
      ret %= MOD;
    }
    n *= n;
    n %= MOD;
    p/=2;
  }
  return ret;
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;

  ll n = s.size();

  vector<ll> v(n);
  vector<ll> v2(n);
  vector<ll> p(n), p2(n);

  v[0] = s[0];
  v2[n-1] = s[n-1];
  p[0] = 1;
  p2[n-1] = 1;

  ll mul = 26;
  for(int i = 1; i<n; ++i){
    v[i] = s[i] * mul + v[i-1]; 
    v[i] %= MOD;
    p[i] = mul;
    mul *= 26;
    mul %= MOD;
  }
  mul = 26;
  for(int i = n-2; i > -1; --i){
    v2[i] = s[i] * mul + v2[i+1];
    v2[i] %= MOD;
    p2[i] = mul;
    mul *= 26;
    mul %= MOD;
  }

  ll l1 = 0, r1 = n;
  ll l2 = 0, r2 = n;
  while(l1+1 < r1){
    ll mid = (l1+r1)/2;
    ll val = 2*mid;
    bool f = false;
    for(int i =0; i<n-val+1; ++i){
      ll hash1 = v[i+val-1];
      if(i > 0) {
        hash1 -= v[i-1];
        hash1 = (hash1+MOD) % MOD;
        ll inv1 = inv(p[i]);
        hash1 = (hash1 * inv1) % MOD;
      }

      ll hash2 = v2[i];
      if(i+val < n){
        hash2 -= v2[i+val];
        hash2 = (hash2+MOD)%MOD;
        ll inversion = inv(p2[i+val-1]);
        hash2 *= inversion;
        hash2 %= MOD;
      
      }
      //cout << i <<" "<<val <<" "<<hash1 <<" "<<hash2<<"\n";
      if(hash1 == hash2) {
        f = true;
        break;
      }
    }
    if(f) l1 = mid;
    else r1 = mid;
  }

  ll ans = l1*2;

  while(l2+1 < r2){
    ll mid = (l2+r2)/2;
    ll val = 2*mid+1;
    bool f = false;
    for(int i =0; i<n-val+1; ++i){
      ll hash1 = v[i+val-1];
      if(i > 0) {
        hash1 -= v[i-1];
        hash1 = (hash1+MOD) % MOD;
        ll inv1 = inv(p[i]);
        hash1 = (hash1 * inv1) % MOD;
      }

      ll hash2 = v2[i];
      if(i+val < n){
        hash2 -= v2[i+val];
        hash2 = (hash2+MOD)%MOD;
        ll inversion = inv(p2[i+val-1]);
        hash2 *= inversion;
        hash2 %= MOD;
      
      }
      //cout << i <<" "<<val <<" "<<hash1 <<" "<<hash2<<"\n";

      if(hash1 == hash2) {
        f = true;
        break;
      }
    }
    if(f) l2 = mid;
    else r2 = mid;
  }

  ans = max(ans, l2*2+1);

  cout << ans;
  return 0;
} // Rabin-Karp...?