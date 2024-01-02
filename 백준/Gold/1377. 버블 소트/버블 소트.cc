#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<pair<ll,ll>> v(N);
    for(int i =0; i<N; ++i){
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin() ,v.end());
    
    ll ans = INT_MIN;
    for(int i =0; i<N; ++i){
        ans = max(ans, v[i].second - i + (ll)1);
    }
    cout << ans;
    return 0;
} // Greedy...?, Ad-hoc