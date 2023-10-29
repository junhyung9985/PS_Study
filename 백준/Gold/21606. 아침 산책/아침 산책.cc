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
    string s;
    ll ans = 0;
    
    cin >> N;
    cin >> s;
    
    vector<ll> cnt(N+1);
    vector<vector<ll>> E(N+1);
    vector<ll> ind(N+1);
    vector<bool> vis(N+1, false);
    
    for(int i =0;i<N-1; ++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
        ind[a]++;
        ind[b]++;
    }

    deque<ll> q;
    for(int i =1; i<=N; ++i){
        if(ind[i] == 1) {
            q.push_back(i);
        }
    }

    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        ll p = 0;
        vis[n] = true;
        for(int i : E[n]){
            if(!vis[i]) p = i;
        }

        if(s[n-1] =='1'){
            cnt[p]++;
            ans += cnt[n]*2;
        }
        else {
            ans += cnt[n]*(cnt[n]-1);
            cnt[p] += cnt[n];
        }

        --ind[p];
        if(ind[p] == 1){
            q.push_back(p);
        }
        //cout << n <<" "<<cnt[n] <<" " << ans<<"\n";
    }

    cout << ans;

    return 0;
} // Combinatorics, Trees, Topological Sort