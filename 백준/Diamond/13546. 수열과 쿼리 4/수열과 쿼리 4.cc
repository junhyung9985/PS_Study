#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll K;

vector<ll> Mos(vector<ll> v, vector<pair<ll,ll>> queries){ // vector of array with values, vector of pairs {start, end} queries 
    
    ll N = v.size();
    ll bucket_size = sqrt(N);
    ll Q = queries.size();

    vector<tuple<ll,ll,ll,ll>> Queries(Q);
    vector<ll> ans(Q);
    
    for(int i = 0; i < Q; ++i){
        Queries[i] = {queries[i].first/bucket_size, queries[i].second, queries[i].first, i};
    }

    sort(Queries.begin(), Queries.end());

    ll sqrt_s, e, s, idx;
    tie(sqrt_s, e, s, idx) = Queries[0];
    
    /// Logics start
    ll bck_size = 400;
    vector<deque<ll>> val(100'001);
    vector<ll> curr(400,0);
    vector<ll> buckets(160'001,0);

    for (int i = s; i <= e; ++i){
        if(!val[v[i]].empty()){
            ll diff = val[v[i]].back()-val[v[i]].front();
            -- buckets[diff];
            -- curr[diff/bck_size];
        }
        val[v[i]].push_back(i);
        ll diff = val[v[i]].back()-val[v[i]].front();
        ++ curr[diff/bck_size];
        ++ buckets[diff];
    }
    
    for(int l = 399; l>=0; l--){
        if(curr[l]){
            for(int j = l*400+399; j>= l*400; --j){
                if(buckets[j]){
                    ans[idx] = j;
                    break;
                }
            }
        }
        if(ans[idx] !=0) break;
    }
    /// Logics end
    /// Logic for Initializing

    for(int i = 1; i < Q; ++i){
        ll sqrt_s, n_e, n_s, idx;
        tie(sqrt_s, n_e, n_s, idx) = Queries[i];

        while(n_s < s){
            --s;
            /// Logics start
            if(!val[v[s]].empty()){
                ll diff = val[v[s]].back()-val[v[s]].front();
                -- buckets[diff];
                -- curr[diff/bck_size];
            }
            val[v[s]].push_front(s);
            ll diff = val[v[s]].back()-val[v[s]].front();
            ++ curr[diff/bck_size];
            ++ buckets[diff];
            /// Logics end
        }

        while(n_e > e){
            ++e;
            /// Logics start
            if(!val[v[e]].empty()){
                ll diff = val[v[e]].back()-val[v[e]].front();
                -- buckets[diff];
                -- curr[diff/bck_size];
            }
            val[v[e]].push_back(e);
            ll diff = val[v[e]].back()-val[v[e]].front();
            ++ curr[diff/bck_size];
            ++ buckets[diff];
            /// Logics end
        }
        
        while(n_s > s){
            /// Logics start
            ll diff = val[v[s]].back()-val[v[s]].front();
            -- curr[diff/bck_size];
            -- buckets[diff];  
            
            val[v[s]].pop_front();
            
            if(val[v[s]].size() > 0){
                ll diff = val[v[s]].back()-val[v[s]].front();
                ++curr[diff/bck_size];
                ++buckets[diff];
            }
            /// Logics end
            ++s;
        }

        while(n_e < e){
            /// Logics start
            ll diff = val[v[e]].back()-val[v[e]].front();
            -- curr[diff/bck_size];
            -- buckets[diff];  
            
            val[v[e]].pop_back();
            
            if(val[v[e]].size() > 0){
                ll diff = val[v[e]].back()-val[v[e]].front();
                ++curr[diff/bck_size];
                ++buckets[diff];
            }
            /// Logics end
            --e;
        }
        
        
    
        for(int l = 399; l>=0; l--){
            if(curr[l]){
                for(int j = l*400+399; j>= l*400; --j){
                    if(buckets[j]){
                        ans[idx] = j;
                        break;
                    }
                }
            }
            if(ans[idx] !=0) break;
        }
    }

    return ans;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q;
    cin >> N >> K;

    vector<ll> v(N);

    for(int i =0; i<N; ++i)
        cin >> v[i];
    
    cin >> Q;
    vector<pair<ll,ll>> q(Q);
    
    for(int i =0; i<Q; ++i){
        ll a,b;
        cin >> a >> b;
        q[i] = {a-1,b-1};
    }
    vector<ll> ans = Mos(v,q);
    for(auto itr : ans)
        cout << itr <<"\n";
        
    return 0;
} // Mo's, Offline Query, Sqrt Decomposition
// O((N+Q)sqrt(N))
