#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll fact[2000001];
ll mod = 1'000'000'007;    
pair<int,pair<int,int>> xGCD(int a, int b) {    // it returns {g, {x,y}}, ax+by=g
    if(b == 0) return {a,{1,0}};
    pair<int,pair<int,int>> ret = xGCD(b, a%b);
    int g, x, y;
    g = ret.first;
    tie(x,y) = ret.second;
    return {g,{y,x-(a/b)*y}};   
}

int mod_inverse(int a) {
    auto res = xGCD(a,mod);
    if(res.first > 1) return -1;
    return (res.second.first + mod) % mod;
}
vector<vector<ll>> comp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M, K;
    cin >> N >> M >> K;
    vector<pair<ll,ll>> v(K);
    comp.resize(K+2, vector<ll>(K+2));
    
    for(int i =0; i<K; ++i){
        ll a, b;
        cin >> a >> b;
        v[i] = {a,b};
    }
    sort(v.begin(), v.end());
    fact[0] = 1;
    for(int i =1; i<=N+M;++i)
        fact[i] = (fact[i-1]*i) % mod;

    for(int i =0; i<K+2; ++i){
        for(int j =0; j<i; ++j){
            ll a1, b1,a2,b2;
            if(i == 0){
                a1 =0; b1=0;
            }
            else if (i == K+1){
                a1 = N, b1 = M;
            }
            else {
                a1 = v[i-1].first, b1 = v[i-1].second;
            }
            if(j == 0){
                a2 =0; b2=0;
            }
            else if (j == K+1){
                a2 = N, b2 = M;
            }
            else {
                a2 = v[j-1].first, b2 = v[j-1].second;
            }
            if(a1 < a2 || b1 < b2) continue;
            comp[i][j] = fact[a1+b1-a2-b2] * mod_inverse(fact[a1-a2]);
            comp[i][j] %= mod;
            comp[i][j] *= mod_inverse(fact[b1-b2]);
            comp[i][j] %= mod;
        }
    }

    ll ans = comp[K+1][0];
    for(ll i =1; i<pow(2,K); ++i){
        ll tmp = i;
        int idx = 0;
        int cnt = 0;
        vector<int> v2;
        while(tmp){
            if(tmp%2){
                ++cnt;
                v2.push_back(idx);
            }
            ++idx;
            tmp/=2;
        }
        int bef = 0 ;
        ll c = 1;
        for(int j =0; j<cnt; ++j){
            c *= comp[v2[j]+1][bef];
            c %= mod;
            bef = v2[j]+1;
        }
        c *= comp[K+1][bef];
        c %= mod;        
        if(cnt%2){
            ans -= c;
        }
        else ans += c;
        ans += mod;
        ans %= mod;
    }

    cout << ans;

    return 0;
}

/*

1 1 1  1 1
1 2 3  4 5
1 3 6 10 15
1 4 10 20 35
1 5 15 35 70
1 6 21 

(2+1)!/N!M!
Modulo inverse가 필요할듯.
아마, 2^20이니깐 특정 폭탄을 지나는 조합들의 개수들을 모두 구할 수 있을거임. 이후에, 전체적인 계산에서 빼주는거고.
근데 내가 모듈로 역원을 못 구함;;
*/