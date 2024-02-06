#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll tr[400001];
ll arr[100001];

ll init(ll n, ll s, ll e){
    if(s == e) return tr[n] = arr[s];
    ll mid = (s+e)/2;
    return tr[n] = init(2*n,s,mid) + init(2*n+1, mid+1, e);
}
ll update (ll n, ll s, ll e, ll idx){
    if(idx < s || e < idx) return tr[n];
    if(s == e) return tr[n] = arr[s];
    ll mid = (s+e)/2;
    return tr[n] = update(2*n, s, mid, idx) + update(2*n+1, mid+1, e, idx);
}
ll query(ll n, ll s, ll e, ll cnt){
    if(s == e) return s;
    if(tr[2*n+1] < cnt) return query(2*n, s, (s+e)/2, cnt-tr[2*n+1]);
    return query(2*n+1, (s+e)/2+1, e, cnt);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    for(int i =0; i<N; ++i){
        ll tmp;
        cin >> tmp;
        ++arr[tmp];
    }
    init(1,0, 100000);

    vector<pair<ll,ll>> want(M);
    for(int i =0; i<M; ++i){
        cin >> want[i].first;
    }
    
    for(int i =0; i<M; ++i){
        cin >> want[i].second;
    }

    for(int i =0; i<M; ++i){
        ll val = query(1, 0, 100000, want[i].second);
        if(val < want[i].first){
            cout << 0;
            return 0;
        }
        --arr[val];
        update(1, 0, 100000, val);
        ++arr[val-want[i].first];
        update(1, 0, 100000, val - want[i].first);
    }
    
    cout << 1;
    
    return 0;
}
/*

Segment Tree + Binary Search


*/