#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;

    vector<pair<ll,ll>> q(N);
    for(int i =0; i<N; ++i){
        ll a, b;
        cin >> a >> b;
        q[i]={a,b};
    }

    ll curr =0 ;
    sort(q.begin(), q.end());

    for(int i =0; i<N; ++i){
        ll a, b;
        tie(a,b) = q[i];
        if(curr < a) curr = a;
        curr+=b;
    }
    cout << curr;
    return 0;
} // Greedy, Sorting