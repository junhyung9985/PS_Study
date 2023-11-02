#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll p[1001];
set<ll> ep[1001];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u( ll a ,ll b){
    ll pa = f(a);
    ll pb = f(b);
    if(pa == pb) return;
    p[pb] = pa;
    
    return;
}

//////// DSU ///////

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    for(int i =1; i<=N; ++i){
        p[i] = i;
    }
    
    for(int j =0; j<M; ++j){
        char ch;
        ll a,b;
        cin >> ch >> a >> b ;
        if(ch == 'E'){
            ep[a].insert(b);
            ep[b].insert(a);
        }
        else {
            u(a,b);
        }
    }
    
    for(int i =1 ; i<=N; ++i){
        for(auto itr : ep[i]){
            for(auto itr2 : ep[itr])
                u(i, itr2);
        }
    }

    ll cnt = 0;
    for(int i =1; i<=N; ++i){
        if(f(i) == i) ++cnt;
    }    
    cout << cnt;
    
    return 0;
} // DSU