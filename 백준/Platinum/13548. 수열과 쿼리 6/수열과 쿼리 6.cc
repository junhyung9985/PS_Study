#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    ll bucket_size = sqrt(N);
    vector<ll> v(N);
    
    for(int i =0; i<N; ++i)
        cin >> v[i];
    
    ll Q;
    cin >> Q;
    vector<tuple<ll,ll,ll,ll,ll>> queries(Q);
    vector<ll> answer(Q);
    for(int i =0; i<Q; ++i){
        ll x, y;
        cin >> x >> y;
        --x;--y;
        queries[i] = {x/bucket_size, y,x,0,i};
    }
    
    sort(queries.begin(), queries.end());
    
    ll idx, s,e, ans, tmp,tmp2;
    tie(idx,e,s,tmp, tmp2) = queries[0];
    
    vector<ll> how_many(100'001,0);
    vector<ll> count(100'001,0);
    ans = 0;
    
    for(int i = s; i<=e; ++i){
        if(how_many[v[i]] > 0) --count[how_many[v[i]]];
        ++how_many[v[i]];
        ++count[how_many[v[i]]];
        if(how_many[v[i]] > ans) ans = how_many[v[i]];
    } 
    answer[tmp2] = ans;
    
    
    for(int i = 1; i<Q; ++i){
        ll n_s, n_e;
        tie(idx, n_e, n_s, tmp, tmp2) = queries[i];
        
        while(n_s < s){
            --s;
            if(how_many[v[s]] > 0) --count[how_many[v[s]]];
            ++how_many[v[s]];
            ++count[how_many[v[s]]];
            if(how_many[v[s]] > ans) ans = how_many[v[s]];
        }
        while(n_e > e){
            ++e;
            if(how_many[v[e]] > 0) --count[how_many[v[e]]];
            ++how_many[v[e]];
            ++count[how_many[v[e]]];
            if(how_many[v[e]] > ans) ans = how_many[v[e]];
        }
        
        while(n_s > s){
            if(how_many[v[s]] > 0) --count[how_many[v[s]]];
            if(count[how_many[v[s]]] == 0 && ans == how_many[v[s]]) --ans;
            --how_many[v[s]];
            if(how_many[v[s]] > 0) ++count[how_many[v[s]]];
            ++s;
        }
        while(n_e < e){
            if(how_many[v[e]] > 0) --count[how_many[v[e]]];
            if(count[how_many[v[e]]] == 0 && ans == how_many[v[e]]) --ans;
            --how_many[v[e]];
            if(how_many[v[e]] > 0) ++count[how_many[v[e]]];
            --e;
        }
        
        answer[tmp2] = ans;
    }
    
    for(int i =0; i<Q; ++i)
        cout << answer[i]<<"\n";
    
    return 0;
} // Mo's Algorithm, Offline Query