#include<bits/stdc++.h>
#define ll long long

using namespace std;

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

    ll curr_ans = 0;
    ll sqrt_s, e, s, idx;
    tie(sqrt_s, e, s, idx) = Queries[0];
    
    /// Logics start
    vector<ll> how_many(1000001);
    for (int i = s; i <= e; ++i){
        curr_ans -= how_many[v[i]]*how_many[v[i]]*v[i];
        ++how_many[v[i]];
        curr_ans += how_many[v[i]]*how_many[v[i]]*v[i];
    }
    ans[idx] = curr_ans;
    /// Logics end

    for(int i = 1; i < Q; ++i){
        ll sqrt_s, n_e, n_s, idx;
        tie(sqrt_s, n_e, n_s, idx) = Queries[i];

        while(n_s < s){
            --s;
            /// Logics start
            curr_ans -= how_many[v[s]]*how_many[v[s]]*v[s];
            ++how_many[v[s]];
            curr_ans += how_many[v[s]]*how_many[v[s]]*v[s];
            /// Logics end
        }

        while(n_s > s){
            /// Logics start
            curr_ans -= how_many[v[s]]*how_many[v[s]]*v[s];
            --how_many[v[s]];
            curr_ans += how_many[v[s]]*how_many[v[s]]*v[s];
            /// Logics end
            ++s;
        }

        while(n_e < e){
            /// Logics start
            curr_ans -= how_many[v[e]]*how_many[v[e]]*v[e];
            --how_many[v[e]];
            curr_ans += how_many[v[e]]*how_many[v[e]]*v[e];
            /// Logics end
            --e;
        }

        while(n_e > e){
            ++e;
            /// Logics start
            curr_ans -= how_many[v[e]]*how_many[v[e]]*v[e];
            ++how_many[v[e]];
            curr_ans += how_many[v[e]]*how_many[v[e]]*v[e];
            /// Logics end
        }
        ans[idx] = curr_ans;
    }

    return ans;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q;
    cin >> N >> Q;

    vector<ll> v(N);
    vector<pair<ll,ll>> q(Q);

    for(int i =0; i<N; ++i)
        cin >> v[i];
    
    for(int i =0; i<Q; ++i){
        ll a,b;
        cin >> a >> b;
        q[i] = {a-1,b-1};
    }
    vector<ll> ans = Mos(v,q);
    for(auto itr : ans)
        cout << itr <<"\n";
        
    return 0;
} // Mo's, Offline Query

