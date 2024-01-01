#include <bits/stdc++.h>
#define ll long long

using namespace std;




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    map<ll, ll> m;
    vector<ll> v(N);
    vector<ll> p(N);
    vector<ll> cnt(N);
    
    for(int i =0; i<N; ++i){
        cin >> v[i];
        if(m.find(v[i]) == m.end()){
            m[v[i]] = i;
        }
        p[i] = m[v[i]];
    }
    
    ll Q;
    cin >> Q;
    vector<tuple<ll,ll,ll,ll>> queries(Q);
    vector<ll> ans(Q);
    for(int i =0; i<Q; ++i){
        ll l, r;
        cin >> l >> r;
        --l; --r;
        queries[i] = {l/sqrt(N), r, l, i};
    }
    sort(queries.begin(), queries.end());
    
    ll idx, l, r, tmp;
    tie(tmp,r,l,idx) = queries[0];
    
    ll answer = 0;
    for(int i =l; i<=r; ++i){
        if(cnt[p[i]] == 0) ++answer;
        ++cnt[p[i]];
    }
    ans[idx] = answer;
    ll L = l, R = r;
    
    for(int i = 1; i<Q; ++i){
        tie(tmp, r, l, idx) = queries[i];
        while(L < l){
            --cnt[p[L]];
            if(cnt[p[L]] == 0) --answer;
            ++L;
        }
        while(L > l){
            --L;
            if(cnt[p[L]] == 0) ++answer;
            ++cnt[p[L]];
        }
        while(R < r){
            ++ R;
            if(cnt[p[R]] == 0) ++answer;
            ++cnt[p[R]];
        }
        while(R > r){
            --cnt[p[R]];
            if(cnt[p[R]] == 0) -- answer;
            --R;
        }
        ans[idx] = answer;
    }
    
    for(int i =0; i<Q; ++i)
        cout << ans[i] <<"\n";
    
    return 0;
} // Mo's + Offline Query + Value Compression / Map 