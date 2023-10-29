#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll p[501];
bool tr[501];

ll f (ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u(ll a, ll b){
    ll pa = f(a);
    ll pb = f(b);
    if(pa == pb){
        tr[pa] = false;
        return;
    }
    p[pb] = pa;
    tr[pa] = tr[pa] && tr[pb];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc = 0;
    while(true){

        ll n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) return 0;
        
        ++tc;
        cout << "Case "<<tc<<": ";
        set<ll> s;
        for(int i=0; i<=n; ++i){
            p[i] = i;
            tr[i] = true;
        }
        for(int i =0; i<m; ++i){
            ll a, b;
            cin >> a >> b;
            u(a,b);
        }
        for(int i=1; i<=n; ++i){
            ll pi = f(i);
            if(tr[pi]) s.insert(pi);
        }

        if(s.size() == 0) cout <<"No trees.\n";
        else if(s.size() == 1) cout <<"There is one tree.\n";
        else cout <<"A forest of "<<s.size()<<" trees.\n";
    }

    return 0;
} // DSU