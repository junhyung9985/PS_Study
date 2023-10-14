#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    deque<pair<ll,ll>> q;
    ll N;
    cin >> N;
    vector<ll> v(N);
    vector<pair<ll,ll>> v2(N);
    
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }
    for(int i=0; i<N; ++i){
        ll val = v[i];
        v2[i].first = i;
        while(!q.empty()){
            if(q.back().first >= val){
                v2[q.back().second].second = i;
                v2[i].first= v2[q.back().second].first;
                q.pop_back();
            }
            else break;
        }
        q.push_back({v[i], i});
    }
    while(!q.empty()){
        v2[q.back().second].second = N;
        q.pop_back();
    }
    
    ll ans = 0;
    for(int i =0; i<N; ++i){
        //cout << v[i] <<" "<<v2[i].second <<" "<<v2[i].first<<"\n";
        ans = max(ans, v[i]*(v2[i].second-v2[i].first));
    }
    cout << ans;
    
    return 0;
} // Stack, Monotone Stack Technique