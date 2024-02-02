#include <bits/stdc++.h>
#define ll long long

using namespace std;

template <typename T>
class SegmentTree{
    public: 
        ll N;
        vector<T> tr;
        vector<T> lazy;
        vector<T> arr;

        T func(T a, T b){
            return max(a, b);
        }// Needs to be implemented by user.
        // Define this based on the type of the query

        T init(ll n, ll s, ll e){
            if(s == e) return this->tr[n] = this->arr[s];
            ll mid = (s+e)/2;
            return this->tr[n] = func(init(2*n, s, mid), init(2*n+1, mid+1, e));
        }

        SegmentTree(vector<T> v){
            this->N = v.size();
            this->arr.resize(this->N);
            this->tr.resize(4 * (this->N));
            for(int i =0; i<N; ++i)
                this->arr[i] = v[i];
            init(1,0,this->N-1);
        }

        T _update(ll n, ll s, ll e, ll idx){
            if(idx < s || idx > e) return this->tr[n];
            if(s == e) return this->tr[n] = this->arr[s];
            ll mid = (s+e)/2;
            return this->tr[n] = func(_update(2*n, s, mid, idx), _update(2*n+1, mid+1, e, idx));
        }

        T update(ll idx, T val){
            this->arr[idx] = val;
            return _update(1,0,this->N-1, idx);
        }

        T _query(ll n, ll s, ll e, ll l, ll r){
            if(e < l || r < s) return 0; // this also should be changed from user
            if(l <= s && e <= r) return tr[n];
            ll mid = (s+e)/2;
            return func(_query(2*n, s, mid, l, r), _query(2*n+1, mid+1, e, l, r));
        }

        T query(ll l, ll r){
            return _query(1,0,this->N-1, l, r);
        }
};


class HLD{
    /*
        Heavy-Light Decomposition

        Attributes:
            <Integers>
            N : number of nodes
            order : variable for DFS ordering

            <Vector of integers>
            sz : sz[i] -> size of subtree with node i as a root
            depth : depth[i] -> depth of node i
            p : p[i] -> parent of node i
            top : top[i] -> node with the lowest depth among the group that node i is in
            in, out : DFS ordering

            <2D vector of integers>
            g : g[i] -> child nodes of node i
    */
    public : 
        ll N, order;
        vector<ll> chck, sz, depth, p, top, in, out;
        vector<vector<ll>> g, e;

        void dfs(ll n = 1){
            this-> chck[n] = 1;
            for(auto itr : e[n]){
                if(chck[itr]) continue;
                chck[itr] = 1;
                g[n].push_back(itr);
                dfs(itr);
            }
        }

        void dfs1(ll n = 1){

            this->sz[n] = 1;
            ll until = this->g[n].size();

            for(int i =0; i<until; ++i){

                ll itr = this->g[n][i];
                this->depth[itr] = this->depth[n]+1;
                this-> p[itr] = n;

                dfs1(itr);

                this->sz[n] += this->sz[itr];
                if(this->sz[itr] > this->sz[g[n][0]]) swap(this->g[n][i], this->g[n][0]);
            }

        }; // Fill the sz, p, and depth array. 
        // Also, make g[i][0] as the child node of i with the largest subtree size.

        void dfs2(ll n = 1){
            this->in[n] = ++order;
            ll until = this->g[n].size();

            for(int i =0; i<until; ++i){
                if(i == 0) top[g[n][i]] = top[n];
                else top[g[n][i]] = g[n][i];
                dfs2(g[n][i]);
            }
            
            this->out[n] = order;
        }; // DFS Ordering + Decomposition

        HLD(ll N, vector<vector<ll>> E, ll root = 1){
            this->N = N;
            this->order = 0;
            this->chck.resize(N+1);
            this->sz.resize(N+1);
            this->depth.resize(N+1);
            this->p.resize(N+1);
            this->top.resize(N+1);
            this->in.resize(N+1);
            this->out.resize(N+1);
            this->g.resize(N+1, vector<ll>());
            this->e.resize(N+1, vector<ll>());    
            
            for(int i =1; i<=N; ++i){
                for(auto itr : E[i]){
                    e[i].push_back(itr);
                }
            }
            dfs(root);
            dfs1(root);
            dfs2(root);

            return;
        };

        vector<ll> get_sz(){return this->sz;};
        vector<ll> get_depth(){return this->depth;};
        vector<ll> get_p(){return this->p;};
        vector<ll> get_top(){return this->top;};
        vector<ll> get_in(){return this->in;};
        vector<ll> get_out(){return this->out;};
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<vector<ll>> graphs(2*N+1);
    vector<ll> costs(N+1);
    for(int i =0; i<N-1; ++i){
        ll ups = N + i + 1;
        ll a, b, c;
        cin >> a >> b >> c;
        costs[i+1] = c;
        graphs[a].push_back(ups);
        graphs[ups].push_back(b);
        graphs[b].push_back(ups);
        graphs[ups].push_back(a);
    }
    
    HLD hld(2*N, graphs, 1);

    vector<ll> p = hld.get_p();
    vector<ll> dep = hld.get_depth();
    vector<ll> in = hld.get_in();
    vector<ll> top = hld.get_top();
    
    vector<ll> v(in.size(), 0);
    for(int i = 1; i<=N; ++i){
        ll idx = in[i+N];
        v[idx] = costs[i];
    }
    
    SegmentTree<ll> seg(v);
    
    ll Q;
    cin >> Q;
    while(Q--){
        ll q, a, b;
        cin >> q >> a >> b;
        if(q == 1){
            seg.update(in[N+a], b);
        }
        else {
            ll ans = 0;
            while(top[a] != top[b]){
                if(dep[top[a]] < dep[top[b]]) swap(a,b);// 더 아래에 있는 노드를 위로 올린다.
                ll t = top[a];
                ans = max(seg.query(in[t], in[a]), ans);
                a = p[t];
            }
            if(dep[a] > dep[b]) swap(a,b);
            ans = max(ans, seg.query(in[a], in[b]));
            cout << ans <<"\n";
        }
    }
    
    
    return 0;
} // HLD, SegmentTree