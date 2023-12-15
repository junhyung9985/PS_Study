#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<ll>v(N+1), p(N+1);
    for(int i = 1; i<=N; ++i){
        cin >> v[i];
        p[i] = v[i] + p[i-1];
    }
    
    ll minn = 0;
    ll ans = v[1];
    for(int i = 1; i<=N; ++i){
        ans = max(ans, p[i]-minn);
        minn = min(minn, p[i]);
    }
    cout << ans;
    return 0;    
} // Prefix Sum O(N)