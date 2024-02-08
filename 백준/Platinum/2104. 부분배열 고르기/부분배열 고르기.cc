#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<pair<ll,ll>> range(N+1);
    vector<ll> v(N+1);
    vector<ll> p(N+1);
    deque<pair<ll,ll>> stck;
    
    for(int i =1; i<=N; ++i){
        cin >> v[i];
        range[i] = {i,i};
        p[i] = v[i] + p[i-1];
        while(!stck.empty()){
            ll val, idx;
            tie(val, idx) = stck.back();
            if(val >= v[i]){
                range[i].first = range[idx].first;
                range[idx].second = i-1;
                stck.pop_back();
            }
            else break;
        }
        stck.push_back({v[i], i});
    }
    
    while(!stck.empty()){
        ll val, idx;
        tie(val, idx) = stck.back();
        range[idx].second = N;
        stck.pop_back();
    }
    
    ll ans = 0;
    for(int i =1; i<=N; ++i){
        ll l, r;
        tie(l, r) = range[i];
        ans = max(ans, v[i] * (p[r] - p[l-1]));
    }
    
    cout << ans;
    
    return 0;
} // Monotone Stack