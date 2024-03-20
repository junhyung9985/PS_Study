/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<pair<ll,ll>>> E;
vector<ll> cost;
vector<bool> visited;
const ll MOD = 1'000'000'007;

ll ans = 0;
ll DFS(ll n){
    visited[n] = true;
    ll bef = 0;
    for(auto itr : E[n]){
        ll child, c;
        tie(child, c) = itr;
        if(!visited[child]){
            ll val = (c*DFS(child))%MOD+c;
            ans += bef * val;
            bef += val;
            bef %= MOD;
            ans %= MOD;
        }
    }
    return cost[n] = bef;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    E.resize(N+1);
    cost.resize(N+1);
    visited.resize(N+1, false);
    
    for(int i =0; i<N-1; ++i){
        ll a, b,c;
        cin >> a >> b >> c;
        E[a].push_back({b,c});
        E[b].push_back({a,c});
    }
    
    DFS(1);
    
    //cout << ans <<"\n";
    for(int i =1; i<=N; ++i){
        //cout << cost[i]<< " ";
        ans += cost[i];
        ans %= MOD;
    }
    //cout<<"\n";
    cout << ans;
    
    return 0;
}