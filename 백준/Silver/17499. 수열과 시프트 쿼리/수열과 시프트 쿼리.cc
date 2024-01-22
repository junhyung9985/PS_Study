#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q;
    cin >> N >> Q;
    
    vector<ll> v(N);
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }
    ll start = 0;
    
    while(Q--){
        ll q, x;
        cin >> q >> x;
        if(q == 1){
            ll val;
            cin >> val;
            v[(x+start-1)%N] += val;
        } 
        if(q == 2){
            start = (start + N - x) % N;
        }
        if(q == 3){
            start = (start+x)%N;
        }
    }
    
    for(int i =0; i<N; ++i){
        cout << v[start]<<" ";
        start = (start+1)%N;
    }
    
    return 0;
} // Ad_hoc, Math