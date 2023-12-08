#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    ll N, a, b;
    cin >> N >> a >> b;

    
    deque<ll> q;
    
    for(int i =1; i<a; ++i){
        q.push_back(i);
    }
    q.push_back(max(a, b));
    for(int i= b-1; i>=1; --i){
        q.push_back(i);
    }
    if(q.size() > N){
        cout << -1;
        return 0;
    }
    

    cout << q[0]<<" ";
    for(int i =0; i<N-q.size(); ++i){
        cout << 1 <<" ";
    }
    for(int i = 1; i<q.size(); ++i){
        cout << q[i]<<" ";
    }

    
    
    return 0;
} // Ad_hoc, Constructive, Greedy