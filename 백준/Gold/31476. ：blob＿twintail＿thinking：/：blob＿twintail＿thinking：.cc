#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll D, N, U, T;
ll total = 0;
vector<ll> cant(5000);
ll pony = 0;
ll pony_cnt = 0;
ll visited = 0;

void DFS(ll n){
    --visited;
    if(visited == 0) pony = pony_cnt;
    if(2*n >= total) return;
    if(cant[2*n] == 0){
        pony_cnt += U;
        DFS(2*n);
        pony_cnt += U;
    }
    if(cant[2*n+1] == 0){
        pony_cnt += U;
        DFS(2*n+1);
        pony_cnt += U;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> D >> N >> U >> T;
    total = pow(2,D);
    while(N--){
        ll s, e;
        cin >> s >> e;
        cant[e] = 1;
    }

    ll twin = 0;
    vector<ll> dp(5000);
    deque<pair<ll,ll>> q;
    q.push_back({1,U});
    
    while(!q.empty()){
        ++visited;
        ll n, t;
        tie(n, t) = q.front();
        q.pop_front();
        if(2*n >= total) continue;
        if(!cant[2*n]&& !cant[2*n+1]){
            t += T;
        }
        if(!cant[2*n]){
            dp[2*n] = dp[n]+t;
            q.push_back({2*n, t});
        }
        if(!cant[2*n+1]){
            dp[2*n+1] = dp[n]+t;
            q.push_back({2*n+1, t});
        }
    }
    DFS(1);
    
    for(int i =1 ;i<=5000; ++i) twin = max(twin, dp[i]);
    //cout << twin <<" "<<pony<<"\n";
    if(twin == pony){
        cout << ":blob_twintail_thinking:";
    }
    else if(twin > pony){
        cout << ":blob_twintail_sad:";
    }
    else cout << ":blob_twintail_aww:";
    
    return 0;
} // DFS, BFS, DP