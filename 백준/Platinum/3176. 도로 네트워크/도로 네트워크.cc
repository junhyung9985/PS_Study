#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<ll> depths;
vector<vector<ll>> parents;
vector<vector<ll>> min_cost;
vector<vector<ll>> max_cost;

vector<vector<pair<ll,ll>>> E;

void DFS(ll n, ll d){
    depths[n] = d;
    for(auto itr : E[n]){
        ll b, c;
        tie(b,c) = itr;
        if(depths[b]) continue;
        parents[0][b] = n;
        min_cost[0][b] = max_cost[0][b] = c;
        DFS(b, d+1);
    }
    return;
}

pair<ll, ll> lca(ll a, ll b){

    ll maxx = INT_MIN, minn = INT_MAX;

    if(depths[a] < depths[b]){
        ll tmp = b;
        b =a;
        a= tmp;
    }
    ll da = depths[a];
    ll db = depths[b];
    ll cng = da -db;
    int cnt = 0;
    while(cng>0){
        if(cng%2){
            maxx = max(maxx, max_cost[cnt][a]);
            minn = min(minn, min_cost[cnt][a]);
            a = parents[cnt][a];
        }
        ++cnt;
        cng /=2;
    }
    bool flag = false;
    while(a != b){
        //cout << a <<" "<<b <<"\n";
        flag = true;
        for(int i = 19; i >=0; --i){
            if(parents[i][a] == -1 || parents[i][b] == -1) continue;
            if(parents[i][a] == parents[i][b]) continue;
            flag = false;
            minn = min(min(min_cost[i][b], min_cost[i][a]), minn);
            maxx = max(max(max_cost[i][b], max_cost[i][a]), maxx);
            a = parents[i][a];
            b = parents[i][b];
            break;
        }
        if(flag) {
            minn = min(min(min_cost[0][b], min_cost[0][a]), minn);
            maxx = max(max(max_cost[0][b], max_cost[0][a]), maxx);
            a = parents[0][a];
            b = parents[0][b];
        }        
    }

    return {minn, maxx};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, K;
    cin >> N;
    E.resize(N+1);
    depths.resize(N+1);
    parents.resize(20,vector<ll>(N+1,-1));
    min_cost.resize(20, vector<ll>(N+1, INT_MAX));
    max_cost.resize(20, vector<ll>(N+1, INT_MIN));

    for(int i =0; i<N-1; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        E[a].push_back({b,c});
        E[b].push_back({a,c});
    }
    
    DFS(1, 1);

    for(int i =1; i<20; ++i){
        for(int j = 1; j<= N; ++j){
            if(parents[i-1][j] == -1) continue;
            parents[i][j] = parents[i-1][parents[i-1][j]];
        }
    }
    // for(int i =0; i<20; ++i){
    //     for(int j =1; j<=N; ++j){
    //         cout << parents[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    for(int i =1; i<20; ++i){
        for(int j = 1; j<= N; ++j){
            if(parents[i-1][j] == -1) continue;
            min_cost[i][j] = min(min_cost[i-1][parents[i-1][j]], min_cost[i-1][j]);
            max_cost[i][j] = max(max_cost[i-1][parents[i-1][j]], max_cost[i-1][j]);
        }
    }
    
    cin >> K;

    for(int i =0; i<K; ++i){
        ll a, b;
        cin >> a >> b;
        ll minn, maxx;
        tie(minn, maxx) = lca(a, b);
        cout << minn <<" "<<maxx<<"\n";
    }
    
    
    return 0;
} // LCA
/*

LCA를 찾아서, 이제 뭐하지?

-> https://everenew.tistory.com/96 여기서 아이디어를 알아옴.

-> 이렇게 DP가 되는 건 또 몰랐네;;

*/