#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<ll> v(N);
    set<ll> s;
    
    for(int i =0; i<N; ++i){
        cin >> v[i];
        s.insert(v[i]);
    }
    ll ans = 0;
    
    while(s.size() > 1){
        auto itr = s.begin();
        ll n = *itr;
        s.erase(itr);
        ll next = *(s.begin());
        bool bef = false;
        for(int i = 0; i<N; ++i){
            if(v[i] == n){
                v[i] = next;
                if(!bef){
                    bef = true;
                    ans += next - n;
                }
            }
            else bef = false;
        }
    }
    
    cout << ans;
    
    return 0;
} // Greedy, Sorting