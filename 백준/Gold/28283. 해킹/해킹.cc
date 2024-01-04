#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M, X, Y;
    cin >> N >> M >> X >> Y;
    
    vector<ll> a(N+1,0);
    for(int i =1 ;i<=N; ++i){
        cin >> a[i];
    }
    vector<vector<ll>> E(N+1);
    for(int i =0; i<M; ++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    
    vector<ll> dist(N+1,-1);
    deque<ll> q;
    for(int i =0; i<Y; ++i){
        ll a;
        cin >> a;
        dist[a] = 0;
        q.push_back(a);
    }
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        ll d = dist[n];
        for(auto itr : E[n]){
            if(dist[itr] == -1){
                dist[itr] = d+1;
                q.push_back(itr);
            }
        }
    }
    
    for(int i =0; i<=N; ++i){
        if(dist[i] == -1 && a[i] != 0){
            cout << -1;
            return 0;
        }
        a[i] *= dist[i];
    }
    
    sort(a.begin(), a.end(), greater<ll>());
    
    ll ans = 0;
    for(int i =0; i<X; ++i)
        ans += a[i];
    cout << ans;
    
    return 0;
} // BFS, Greedy, Sorting
// O(N+M+NlogN)

// 2분 패널티.
