#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

ll tree[8000010];

void update(ll n, ll s ,ll e, ll idx, int flag){
    if(e < idx || idx < s) return;
    tree[n]+= flag;
    if(s == e) return; 
    update(2*n, s, (s+e)/2, idx, flag);
    update(2*n+1, (s+e)/2+1, e, idx, flag);
    return;    
}

ll query(ll n, ll s, ll e, ll x, ll S){
    if(s == e) return s;
    if(tree[2*n]+S < x) return query(2*n+1, (s+e)/2+1, e, x, S+tree[2*n]);
    else return query(2*n, s, (s+e)/2,x,S);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll Q;
    cin >> Q;
    ll  maxx = 0, minn = INT_MAX;
    while(Q--){
        ll q, x;
        cin >> q >> x;
        if(q == 1){
            update(1,0,2000000,x, 1);
            maxx = max(maxx , x);
            minn = min(minn , x);
        }
        else {
            ll ret = query(1,0,2000000, x, 0);
            cout << ret <<"\n";
            update(1,0,2000000,ret, -1);
        }
    }

    return 0;
} // Segment Tree + Binary Search