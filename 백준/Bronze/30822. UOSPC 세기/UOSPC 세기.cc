#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    map<char, ll> m;
    string s;
    cin >> s;
    for(int i =0; i<N; ++i){
        m[s[i]]++;
    }
    ll ans = min(m['u'], m['o']);
    ans = min(m['s'],min(m['p'], min(m['c'], ans)));
    cout << ans;
    
    return 0;
}