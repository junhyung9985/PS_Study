#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

map<pair<ll,ll>, pair<ll,ll>> p;
map<pair<ll,ll>, set<pair<ll,ll>>> except;

pair<ll,ll> f(pair<ll,ll> n){
    if(p[n].first == n.first && p[n].second == n.second) return n;
    return p[n] = f(p[n]);
}

void u(pair<ll,ll> a, pair<ll,ll> b){
    pair<ll,ll> pa = f(a), pb = f(b);
    if(pa.first == pb.first && pa.second == pb.second) return;
    p[pa] = pb;
    return;
}

ll dy[4] = {1,-1,0,0};
ll dx[4] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, K, R;
    cin >> N >> K >> R;

    for(int i =1; i<=N; ++i)
        for(int j=1; j<=N; ++j)
            p[{i,j}] = {i,j};

    for(int i =0; i<R; ++i){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;    
        except[{a,b}].insert({c,d});
        except[{c,d}].insert({a,b});
    }

    for(int i =1; i<=N; ++i){
        for(int j =1; j<=N; ++j){
            for(int k =0; k<4; ++k){
                if(i+dy[k] <= 0 || i+dy[k] > N || j+dx[k] <=0 || j+dx[k] > N) continue;
                if(except[{i,j}].find({i+dy[k], j+dx[k]}) == except[{i,j}].end()) u({i,j}, {i+dy[k], j+dx[k]});  
            }
        }
    }

    vector<pair<ll,ll>> cows(K);
    for(int i =0; i<K; ++i){
        ll a, b;
        cin >> a >> b;
        cows[i] = {a,b};
    }

    ll ans = 0;
    for(int i=0; i<K; ++i){
        for(int j =i+1; j<K; ++j){
            if(f(cows[i]) != f(cows[j])) ++ans;
        }
    }

    cout << ans;

    return 0;
} // DSU, Bruteforcing