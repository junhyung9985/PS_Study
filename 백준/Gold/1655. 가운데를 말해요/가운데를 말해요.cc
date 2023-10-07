#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    priority_queue<ll> pq1;
    priority_queue<ll, vector<ll>, greater<ll>> pq2;

    for(int i =1; i<=N; ++i){
        ll a;
        cin >> a;
        if(pq1.empty()) pq1.push(a);
        else if(pq1.top() >= a) pq1.push(a);
        else pq2.push(a);
        while(pq1.size() < pq2.size()+i%2){
            pq1.push(pq2.top());
            pq2.pop();
        }

        while(pq1.size() > pq2.size()+ i%2){
            pq2.push(pq1.top());
            pq1.pop();
        }      
        cout << pq1.top()<<"\n";
    }

    return 0;
} // Priority Queue, Data Structure