#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int solution(vector<int> priorities, int location) {
    
    priority_queue<ll> pq;
    deque<pair<ll,ll>> q;
    int idx = 0;
    
    for(int a : priorities){
        pq.push(a);
        q.push_back({a,idx});
        ++idx;
    }
    
    int cnt = 0;
    while(!q.empty()){
        ll n, idx;
        tie(n, idx) = q.front();
        q.pop_front();
        if(n != pq.top()){
            q.push_back({n,idx});
        }
        else {
            pq.pop();
            ++cnt;
            if(idx == location) break;
        }        
    }
    
    return cnt;
}