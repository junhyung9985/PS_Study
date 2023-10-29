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
    vector<ll> bef(N+1);
    vector<vector<ll>> E(N+1);
    vector<ll> depths(N+1, 0);


    for(int i =0;i<N-1; ++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
        
    }
    
    deque<ll> q;
    vector<ll> traverse;
    q.push_back(1);
    depths[1] = 1;
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        traverse.push_back(n);
        for(int i : E[n]){
            if(depths[i] == 0){
                depths[i] = depths[n]+1;
                q.push_back(i);
            }
        }
    } // BFS

    while(!traverse.empty()){
        ll n =  traverse.back();
        traverse.pop_back();
        ll par = 0;
        for(int i : E[n]){
            if(depths[i] < depths[n]){
                par = i;
            }
        }

        if(s[n-1] == '1'){
            ans += cnt[n]*2;
            cnt[par]++;
        }
        else {
            cnt[par] += cnt[n];
            ans += cnt[n]*(cnt[n]-1) - bef[n];
            bef[par] += cnt[n]*(cnt[n]-1);
        }
        //cout << n <<" "<<cnt[n]<<" "<<ans<<"\n";
    }

    cout << ans;

    return 0;
} // Combinatorics, BFS, Trees