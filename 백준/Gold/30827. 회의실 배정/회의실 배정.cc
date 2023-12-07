#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, K;
    cin >> N >> K;
    
    multiset<ll> ms;
    vector<pair<ll,ll>> v(N);

    for(int i =0; i<K; ++i){
        ms.insert(0);
    }

    for(int i =0; i<N; ++i){
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(), v.end());
    
    ll ans = 0;
    for(int i =0; i<N; ++i){
        ll e, s;
        tie(e,s) = v[i];
        auto itr = ms.lower_bound(s);
        if(itr == ms.begin()){
            continue;
        }
        --itr;
        ms.insert(e);
        ms.erase(itr);
        ++ans;
    }
    cout << ans;
    
    return 0;
}