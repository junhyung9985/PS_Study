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
    for(int i =0; i<N; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    ll n;
    cin >> n;
    ll idx = lower_bound(v.begin(), v.end(), n) - v.begin();
    ll upper = v[idx];
    ll lower = 0;
    if(idx > 0){
        lower = v[idx-1];
    }
    
    lower = n - lower;
    upper = upper-n;
    ll ans = lower * upper;
    if(ans > 0) -- ans;
    cout << ans;
    
    return 0;
} // Combinatorics, Binary Search