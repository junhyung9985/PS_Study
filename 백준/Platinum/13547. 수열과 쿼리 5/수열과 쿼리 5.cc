#include <bits/stdc++.h>
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
        if(how_many[v[i]] == 0) ++curr_ans;
        ++how_many[v[i]];
    }
    ans[idx] = curr_ans;
    /// Logics end

    for(int i = 1; i < Q; ++i){
        ll sqrt_s, n_e, n_s, idx;
        tie(sqrt_s, n_e, n_s, idx) = Queries[i];

        while(n_s < s){
            --s;
            /// Logics start
            if(how_many[v[s]] == 0) ++curr_ans;
            ++how_many[v[s]];
            /// Logics end
        }

        while(n_s > s){
            /// Logics start
            --how_many[v[s]];
            if(how_many[v[s]] == 0) --curr_ans;
            /// Logics end
            ++s;
        }

        while(n_e < e){
            /// Logics start
            --how_many[v[e]];
            if(how_many[v[e]] == 0) --curr_ans;
            /// Logics end
            --e;
        }

        while(n_e > e){
            ++e;
            /// Logics start
            if(how_many[v[e]] == 0) ++curr_ans;
            ++how_many[v[e]];
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
    
    cin >> N;
    vector<ll> v(N);    
    for(int i =0; i<N; ++i) cin >> v[i];
    
    cin >> Q;
    vector<pair<ll,ll>> q(Q);
    for(int i =0; i<Q; ++i){
        cin >> q[i].first >> q[i].second; 
        --q[i].first; --q[i].second;
    } 
    
    vector<ll> ans = Mos(v,q);

    for(auto itr : ans) cout << itr<<"\n";

    return 0;
} // Example : BOJ 13547 Example 1