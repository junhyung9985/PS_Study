#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q;
    cin >> N >> Q;
    
    vector<ll> v(N);
    vector<ll> v2(N);
    
    for(int i =0; i<N; ++i){
        cin >> v[i];
        v2[i] = -v[i];
    }
    
    vector<ll> d(N);
    vector<ll> d2(N);
    deque<ll> q, q2;
    
    for(int i =0; i<N; ++i){
        ll idx = lower_bound(q.begin(), q.end(), v[i]) - q.begin();
        d[i] = idx+1;
        if(idx == q.size()) q.push_back(v[i]);
        q[idx] = v[i];
    }
    
    for(int i = N-1; i>-1; --i){
        ll idx = lower_bound(q2.begin(), q2.end(), v2[i]) - q2.begin();
        d2[i] = idx+1;
        if(idx == q2.size()) q2.push_back(v2[i]);
        q2[idx] = v2[i];
    }
    
    while(Q--){
        ll n;
        cin >> n;
        cout << d[n-1] + d2[n-1] - 1 <<"\n";
    }
    
    return 0;
} // nlogn LIS
// 가장 긴 바이토닉 수열 nlogn 버젼 같음