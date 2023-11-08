#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<vector<ll>> m(N, vector<ll>(N));
    vector<vector<ll>> apply(N, vector<ll>(N, INT_MAX));
    deque<tuple<ll,ll,ll>> E;

    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            cin >> m[i][j];
            if(j>=i) E.push_back({m[i][j],i,j});
        }
    }
    sort(E.begin(), E.end());

    ll ans = 0;
    bool flag = false;
    while(!E.empty()){
        ll d,a,b;
        tie(d,a,b) = E.front();
        E.pop_front();
        if(d > apply[a][b]) break;
        if(d == apply[a][b]) continue;
        
        ans += d;
        apply[a][b] = d;
        apply[b][a] = d;

        for(int k=0; k<N;++k)
            for(int i=0; i<N; ++i)
                for(int j=0; j<N; ++j)
                    apply[i][j] = min(apply[i][j], apply[i][k]+apply[k][j]);
        
        bool done = true;
        for(int i =0; i<N; ++i)
            for(int j =0; j<N; ++j)
                done = done && (apply[i][j] == m[i][j]);
        if(done){
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << -1;
        return 0;
    }

    cout << ans;
    return 0;
} // Sorting, Floyd-Warshall