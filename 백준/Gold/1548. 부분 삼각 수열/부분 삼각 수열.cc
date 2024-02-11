#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    if(N < 3){
        cout << N;
        return 0;
    }
    vector<ll> v(N);
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    ll ans = 0;
    for(int i =0; i<N; ++i){
        for(int j =i+1; j<N; ++j){
            ll idx = lower_bound(v.begin(), v.end(), v[i]+v[j]) - v.begin();
            ans = max(ans, (ll)(idx-j+1));
        }
    }
    cout << ans;
    
    return 0;
} // Sorting, Binary Search