#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    priority_queue<ll> pq;
    for(int i =0; i<N; ++i){
        ll tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    
    for(int i =0; i<M; ++i){
        ll tmp;
        cin >> tmp;
        if(pq.top() < tmp){
            cout << 0;
            return 0;
        }
        pq.push(pq.top()-tmp);
        pq.pop();
    }
    cout << 1;
    
    return 0;
}
/*

Priority Queue

*/