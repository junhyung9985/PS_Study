#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll p[301];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

bool u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa == pb) return false;
    p[pb] = pa;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;

    deque<tuple<ll,ll,ll>> E;
    
    for(int i =1; i<=N; ++i){
        p[i] = i;
        ll val;
        cin >> val;
        E.push_back({val,0,i});
    }
    for(int i =1; i<=N; ++i){
        for(int j =1; j<=N; ++j){
            ll tmp;
            cin >> tmp;
            if(i < j) E.push_back({tmp, i, j});
        }
    }
    sort(E.begin(), E.end());

    ll ans = 0;
    while(!E.empty()){
        ll val, a, b;
        tie(val, a, b) = E.front();
        E.pop_front();
        if(u(a,b)) ans += val;
    }
    cout << ans;

    return 0;
} // MST