#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<ll>v(3);
    for(int i =0; i<3; ++i)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    cout << v[1];
    
    return 0;
} // Implementation