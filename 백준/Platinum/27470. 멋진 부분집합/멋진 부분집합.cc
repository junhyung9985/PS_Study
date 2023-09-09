#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS


ll prime[3]={2,7,61};
 
ll gob(ll x,ll y,ll MOD)
{
    return (ll)((__int128)x*y%MOD);
} 
 
ll jegob(ll x,ll y, ll MOD)
{
    if(y<=0) return 1;
    
    ll ret=jegob(x,y/2,MOD);
    
    if(y%2) return gob(gob(ret,ret,MOD),x,MOD);
    return gob(ret,ret,MOD);
} 
 
int Miller_Rabin(ll n, ll p)
{
    if(n%p==0) return 1;
    
    ll d=n-1;
    while(d%2==0) d/=2;
    
    ll imsi=jegob(p,d,n);
    if(imsi==1||imsi==n-1) return 1;
    
    while(d*2<n-1)
    {
        d*=2;
        if(jegob(p,d,n)==n-1) return 1;
    } return 0;
} 
 
int Check_Prime(ll n)
{
    for(int i=0;i<3;i++)
    {
        if(n==prime[i]) return 1;
        if(!Miller_Rabin(n,prime[i])) return 0;
    } return 1;
}
//////////////// Miller //////////////////////


void rec(ll n, vector<ll>& v) {
		if (n == 1) return;
		if (n % 2 == 0) {
			v.push_back(2);
			rec(n / 2, v);
			return;
		}
		if (Check_Prime(n)) {
			v.push_back(n);
			return;
		} // 소수는 밀러 라빈으로 처리
		ll a, b, c, g = n;
        auto f = [&](ll x) {
            return (c + (x*x)%n) % n;
        }; // X^2+C 

        do {
            if (g == n) {
                a = b = rand() % (n - 2) + 2;
                c = rand() % 20 + 1;
            } // n이면 crash 났으므로 새로운 값으로 변경
            a = f(a);
            b = f(f(b)); // 한칸, 두칸 앞으로 전진 했을 때
            g = gcd(abs(a - b), n); // 1 < g < n이면 g가 약수임
        } while (g == 1);

		rec(g, v);
		rec(n / g, v);
}
vector<ll> factorize(ll n) {
    vector<ll> ret;
    rec(n, ret);
    sort(ret.begin(), ret.end());
    return ret;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<ll> v(N);
    unordered_map<ll, ll> p_f;
    ll val = 1; 
    for(int i =0; i<N ;i++){
        cin >> v[i];
    }

    for(int i =0; i<min((ll)10, N); i++){
        vector<ll> primes = factorize(v[i]);
        ll bef= 1;
        for(ll j : primes){
            if(j != bef ){
                ll cnt = 0;
                for(int k =0; k<N; k++){
                    if(cnt == N/2+N%2) break;
                    if(__gcd(v[k], j) > 1) cnt++;
                }
                if(cnt == N/2+N%2){
                    val = j;
                }
                //cout << cnt <<" "<< j<<" "<< val << "\n";
            }
        }
        if(val > 1) break;
    }

    if(val == 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    ll cnt = 0;
    for(int i =0; i<N; i++){
        if(cnt == N/2+N%2) break;
        if(__gcd(v[i], val) != 1){
            cout << v[i] <<" ";
            cnt ++;
        }
    }

    return 0;
}

/*

3732 primes between 1 to 35000 -> 3732 * 10^5*5

__gcd(x, y)

--> Prime factorization, Sieve, Miller-Rabin

*/