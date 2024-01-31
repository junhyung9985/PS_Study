#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;
vector<ll> tr;
vector<tuple<ll,ll,ll,ll>> lazy;
vector<ll> arr;
bool q3 = false;

void push(ll n, ll s, ll e){
    if(s == e){
        ll a, b, c, d;
        tie(a,b,c,d) = (lazy[n]);
        //cout<<a <<" " << b <<" "<< c <<" " << d<<" : "<< s<<", "<<tr[n] <<"\n";
    }
    if(get<3>(lazy[n])) tr[n] = (e-s+1) *(((get<2>(lazy[n])+get<0>(lazy[n])) % 1'000'000'007)% 1'000'000'007);
    else{
        tr[n] *= get<1>(lazy[n]);
        tr[n] %= 1'000'000'007;
        tr[n] += ((e-s+1) * get<0>(lazy[n])) % 1'000'000'007;
    } 
    tr[n] %= 1'000'000'007;
    if(s != e){
        if(get<3>(lazy[n])){
            lazy[2*n] = lazy[n];
            lazy[2*n+1] = lazy[n];
        }
        else {
            get<0>(lazy[2*n]) *= get<1>(lazy[n]);
            get<0>(lazy[2*n+1]) *= get<1>(lazy[n]);
            get<0>(lazy[2*n]) %= 1'000'000'007;
            get<0>(lazy[2*n+1]) %= 1'000'000'007;
            get<0>(lazy[2*n]) += get<0>(lazy[n]);
            get<0>(lazy[2*n+1]) += get<0>(lazy[n]);
            get<0>(lazy[2*n]) %= 1'000'000'007;
            get<0>(lazy[2*n+1]) %= 1'000'000'007;
            
            if(get<3>(lazy[2*n])) get<2>(lazy[2*n]) *= get<1>(lazy[n]);
            else get<1>(lazy[2*n]) *= get<1>(lazy[n]);
            
            get<1>(lazy[2*n]) %= 1'000'000'007;
            get<2>(lazy[2*n]) %= 1'000'000'007;
            
            if(get<3>(lazy[2*n+1])) get<2>(lazy[2*n+1]) *= get<1>(lazy[n]);
            else get<1>(lazy[2*n+1]) *= get<1>(lazy[n]);
            
            get<1>(lazy[2*n+1]) %= 1'000'000'007;
            get<2>(lazy[2*n+1]) %= 1'000'000'007;
        }
    }
    lazy[n] = {0,1,0,0};
    return;
}// Needs to be implemented by user.
// Define this based on the type of the query

ll func(ll a, ll b){
    return (a + b) % 1'000'000'007;
}// Needs to be implemented by user.
// Define this based on the type of the query

ll init(ll n, ll s, ll e){
    if(s == e) return tr[n] = arr[s];
    ll mid = (s+e)/2;
    return tr[n] = (init(2*n, s, mid)+ init(2*n+1, mid+1, e)) % 1'000'000'007;
}

ll _update(ll n, ll s, ll e, ll l, ll r, tuple<ll,ll,ll,ll> val){
    if(get<0>(lazy[n]) || get<1>(lazy[n]) != 1 || get<3>(lazy[n])) push(n, s, e);
    if(r < s || l > e) return tr[n];
    if(l <= s && e <= r){
        if(get<3>(val)) lazy[n] = val;
        else if (get<3>(lazy[n])){
            get<0>(lazy[n]) += get<0>(val);
            get<0>(lazy[n]) %= 1'000'000'007;
            get<0>(lazy[n]) *= get<1>(val);
            get<0>(lazy[n]) %= 1'000'000'007;
            get<2>(lazy[n]) *= get<1>(val);
            get<2>(lazy[n]) %= 1'000'000'007;
        }
        else{
            get<0>(lazy[n]) += get<0>(val);
            get<0>(lazy[n]) %= 1'000'000'007;
            get<0>(lazy[n]) *= get<1>(val);
            get<0>(lazy[n]) %= 1'000'000'007;
            get<1>(lazy[n]) *= get<1>(val);
            get<1>(lazy[n]) %= 1'000'000'007;
        }
        push(n,s,e);
        return tr[n];
    }
    ll mid = (s+e)/2;
    return tr[n] = (_update(2*n, s, mid, l, r, val) + _update(2*n+1, mid+1, e, l, r, val))% 1'000'000'007;
}

ll update(ll l, ll r, tuple<ll,ll,ll,ll> val, ll q){
    if(q == 3) q3 = true;
    else q3 = false;
    return _update(1,0,N-1, l, r, val);
}

ll _query(ll n, ll s, ll e, ll l, ll r){
    if(get<0>(lazy[n]) || get<1>(lazy[n]) != 1 || get<3>(lazy[n]) ) push(n, s, e);
    if(e < l || r < s) return 0; // this also should be changed from user
    if(l <= s && e <= r) return tr[n];
    ll mid = (s+e)/2;
    return (_query(2*n, s, mid, l, r) + _query(2*n+1, mid+1, e, l, r))% 1'000'000'007;
}

ll query(ll l, ll r){
    return _query(1,0,N-1, l, r);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N ;
    arr.resize(N);
    tr.resize(4*N+4);
    lazy.resize(4*N+4, {0,1,0,0});
    
    for(int i =0 ;i<N ;++i)
        cin >> arr[i];
    
    init(1,0,N-1);
    
    ll Q;
    cin >> Q;
    ll cnt = 1;
    while(Q--){
        // cout << cnt++<<"\n";
        ll q, x, y;
        cin >> q >> x >> y;
        if(q == 1){
            ll val;
            cin >> val;
            update(x-1, y-1, make_tuple(val,1,0,0), q);
        }
        if(q == 2){
            ll val;
            cin >> val;
            update(x-1, y-1, make_tuple(0,val,0,0), q);
        }
        if(q == 3){
            ll val;
            cin >> val;
            update(x-1,y-1, make_tuple(0,0,val,1), q);
        }
        if(q == 4){
            cout << query(x-1, y-1)<<"\n";
            // for(int i = 0; i<N; ++i){
            //     cout << query(i, i)<<" ";
            // }
            // cout<<"\n";
        }
    }
    return 0;
} // Lazy Segment Tree