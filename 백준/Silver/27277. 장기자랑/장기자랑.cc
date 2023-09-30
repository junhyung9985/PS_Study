#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<ll> v(N+1);
    for(int i =0; i<N; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    
    int l = 0, r = N;
    ll ans = 0;
    while(l < r){
        ans += max(v[r]-v[l], (ll)0);
        --r;
        ++l;
    }
    cout << ans ;
    return 0;
}