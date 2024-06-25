//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
// Compiler Optimization Options

#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension
// Rope

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M, K;
    cin >> N >> M >> K;
    
    vector<multiset<ll>> ms(M+1);
    vector<ll> which(M+1, -1);
    vector<ll> won(N,0);
    vector<vector<ll>> c(N, vector<ll>(M+1));
    
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<K; ++j){
            ll a, b;
            cin >> a >> b;
            c[i][a] = b;
            if(!ms[a].empty()){
                if(*(ms[a].rbegin()) < c[i][a]){
                    --won[which[a]];
                    which[a] = i;
                    ++won[i];
                }
            }
            else{
                ++won[i];
                which[a] = i;
            }
            ms[a].insert(c[i][a]);
        }
    }

    ll curr = 0;
    for(int i = 0; i<N; ++i){
        if(won[i] == K) ++ curr;
    }

    ll Q;
    cin >> Q;
    while(Q--){
        ll a, b, d;
        cin >> a >> b >> d;
        if(c[a-1][b]+d > *(ms[b].rbegin())){
            --won[which[b]];
            if(won[which[b]] == K-1) -- curr;
            which[b] = a-1;
            ++won[a-1];
            if(won[a-1] == K) ++ curr;
        }
        auto itr = ms[b].find(c[a-1][b]);
        ms[b].erase(itr);
        c[a-1][b] += d;
        ms[b].insert(c[a-1][b]);
        cout << curr <<"\n";
    }
    
    return 0;
} // Implementation, Simulation, Treeset