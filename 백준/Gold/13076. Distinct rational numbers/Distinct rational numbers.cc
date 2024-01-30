#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> p;
bool primes[1000001];
map<ll, int> m;

ll Euler(ll k){
    return pow(k,m[k])-pow(k,m[k]-1);
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i =2; i<=1000000; i++){
        if(!primes[i]){
            p.push_back(i);
            for(int j=i*2; j<=1000000; j+=i)
                primes[j] = true;
        }
    } // Prime numbers
        
    vector<ll> ans(10001);
    
    for(int n = 1; n<=10000; ++n){
        m.clear();
        ll N = n;
        while(N > 1){
            bool flag = true;
            for(int prime : p){
                if(N%prime ==0){
                    m[prime]++;
                    N/=prime;
                    flag = false;
                    break;
                }
            }
            if(flag) {
                m[N] = 1;
                N = 1;
            }
        } // Factorization
    
        ll cnt = 1;
        for(auto iter = m.begin(); iter != m.end(); iter++){
            cnt *= Euler(iter->first);
        }
        ans[n] = cnt + ans[n-1];
    }
    
    ll T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        cout << ans[n] + 1<<"\n";
    }
    
    return 0;
}
/*
Euler-Phi function
*/