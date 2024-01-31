#include<bits/stdc++.h>
#define ll long long

using namespace std;
template <typename T>
class LazySegmentTree{
    public: 
        ll N;
        vector<T> tr;
        vector<T> lazy;
        vector<T> arr;

        void push(ll n, ll s, ll e){
            tr[n] += (e-s+1) * lazy[n];
            if(s != e){
                lazy[2*n] += lazy[n];
                lazy[2*n+1] += lazy[n];
            }
            lazy[n] = 0;
            return;
        }// Needs to be implemented by user.
        // Define this based on the type of the query

        T func(T a, T b){
            return a+b;
        }// Needs to be implemented by user.
        // Define this based on the type of the query

        T init(ll n, ll s, ll e){
            if(s == e) return this->tr[n] = this->arr[s];
            ll mid = (s+e)/2;
            return this->tr[n] = func(init(2*n, s, mid), init(2*n+1, mid+1, e));
        }

        LazySegmentTree(vector<T> v){
            this->N = v.size();
            this->arr.resize(this->N);
            this->tr.resize(4 * (this->N));
            this->lazy.resize(4 * (this->N));
            for(int i =0; i<N; ++i)
                this->arr[i] = v[i];

            init(1,0,N-1);
        }

        T _update(ll n, ll s, ll e, ll l, ll r, T val){
            if(lazy[n]) push(n, s, e);
            if(r < s || l > e) return this->tr[n];
            if(l <= s && e <= r){
                lazy[n] = val;
                push(n,s,e);
                return this->tr[n];
            }
            ll mid = (s+e)/2;
            return this->tr[n] = func(_update(2*n, s, mid, l, r, val), _update(2*n+1, mid+1, e, l, r, val));
        }

        T update(ll l, ll r, T val){
            return _update(1,0,this->N-1, l, r, val);
        }

        T _query(ll n, ll s, ll e, ll l, ll r){
            if(lazy[n]) push(n, s, e);
            if(e < l || r < s) return 0; // this also should be changed from user
            if(l <= s && e <= r) return tr[n];
            ll mid = (s+e)/2;
            return func(_query(2*n, s, mid, l, r), _query(2*n+1, mid+1, e, l, r));
        }

        T query(ll l, ll r){
            return _query(1,0,this->N-1, l, r);
        }

};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M, K;
    cin >> N>> M >> K;

    vector<ll> v(N);
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }
    
    LazySegmentTree<ll> seg(v);
    
    ll Q = M+K;
    while(Q--){
        ll q, a, b;
        cin >> q >> a >> b;
        //cout << q <<" "<<a <<" "<<b<<"\n";
        if(q == 1) {
            ll value;
            cin >> value;
            seg.update(a-1, b-1, value);
        }
        else cout << seg.query(a-1,b-1)<<"\n";
    }

    return 0;
} // Lazy SegmentTree
