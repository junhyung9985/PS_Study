#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll p[500001];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u(ll a, ll b){
    ll pa = f(a), pb = f(b);
    if(pa < pb){
        ll tmp = pb;
        pb = pa;
        pa = tmp;
    }
    p[pb] = pa;
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    
    for(int i =1; i<=N; ++i)
        p[i] = i;
    
    ll ans = 0;
    ll left = 0;
    for(int i =0; i<M; ++i){
        left += 1;

        ll l, r, ret = 0; 
        cin >> l >> r;
        l = f(l);
        while(l < r){
            u(l, l+1);
            ++l;
            ++ret;
            l = f(l);
            //cout << l <<"\n";
        }
        //cout << ret <<" "<<left<<"\n";

        if(ret > left){
            ans += ret - left;
            left = 0;
        }
        else left -= ret;
        //cout << ans <<"\n";
    }
    cout << ans;

    return 0;
} // DSU, Greedy?