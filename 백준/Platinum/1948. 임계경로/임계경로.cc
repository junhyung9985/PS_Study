#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    vector<vector<pair<ll,ll>>> E(N+1);
    vector<deque<pair<ll,ll>>> E2(N+1);
    vector<ll> dp(N+1);
    vector<ll> ind(N+1);
    vector<bool> vis(N+1);
    vector<bool> vis2(N+1);
    
    for(int i =0; i<M; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b,c});
        E2[b].push_back({a,c});
        dp[a] = 0;
        dp[b] = 0;
        ind[b]++;
        vis2[a] = false;
        vis2[b] = false;
    }

    ll a, b;
    cin >> a >> b;
    deque<ll> q;
    q.push_back(a);
    while(!q.empty()){
        ll n= q.front();
        q.pop_front();
        
        ll cur_cost = dp[n];
        
        for(pair<ll,ll> next : E[n]){
            ll down, cost;
            tie(down, cost) = next;
            if(cur_cost + cost > dp[down]){
                dp[down] = cur_cost + cost;
            }
            --ind[down];
            if(ind[down] == 0) q.push_back(down);
        }
    }
    

    
    cout << dp[b] <<"\n";
    q.clear();
    q.push_back(b);
    ll cnt = 0;
    vis2[b] = true;
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        while(!E2[n].empty()){
            ll up, cost;
            tie(up, cost) = E2[n].front();
            E2[n].pop_front();
            if(dp[n]-cost == dp[up]){
                ++cnt;
                if(!vis2[up]) q.push_back(up);
                vis2[up] = true;
                //cout << up <<" "<<cost<<"\n";
                
            }
        }
    }
    
    cout << cnt<<"\n";
    
    return 0;
} // Topological Sort + Backtracking