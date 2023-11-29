#include <bits/stdc++.h>
#define ll long long
#define INF 987654321
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<vector<ll>> E(203, vector<ll>());
    vector<vector<ll>> f(203, vector<ll>(203));
    vector<vector<ll>> c(203, vector<ll>(203));
    
    
    vector<tuple<ll,ll,ll>> info(N+1);
    for(int i =1; i<=N; ++i){
        ll a,b,c;
        cin >> a >> b >> c;
        info[i] = {a,b,c};
    }
    
    for(int i =1; i<=N; ++i){
        ll t1, t2, t3;
        tie(t1,t2,t3) = info[i];
        for(int j = 1 ;j<=N; ++j){
            if(i == j) continue;
            ll a,b,k;
            tie(a,b,k) = info[j];
            if(t1 >= a && t2 >= b && t3 >= k){
                if(t1 == a && t2 == b && t3 == k && j > i) continue;
                E[i].push_back(100+j);
                E[50+i].push_back(100+j);
                c[i][100+j] = 1;
                c[50+i][100+j] = 1;
                E[100+j].push_back(50+i);
                E[100+j].push_back(i);
            }
            
        }
        
        E[0].push_back(i);
        E[0].push_back(50+i);
        E[50+i].push_back(0);
        E[i].push_back(0);
        c[0][i] = 1;
        c[0][50+i] = 1;
        E[100+i].push_back(201);
        E[201].push_back(100+i);
        c[100+i][201] = 1;
    }
    
    ll s = 0, e = 201;
    
    ll ans = 0;
    while(true){
        vector<ll> visited(203, -1);
        deque<ll> q;
        q.push_back(s);
        while(!q.empty()){
            ll n = q.front();
            q.pop_front();
            for(auto itr:  E[n]){
                if(visited[itr] == -1 && c[n][itr] - f[n][itr] > 0){
                    visited[itr] = n;
                    q.push_back(itr);
                    if(itr == e) break;
                }
            }
        }
        if(visited[e] == -1) break;
        ll curr = e;
        ll minn = INT_MAX;
        while(curr != s){
            ll next = visited[curr];
            minn = min(minn, c[next][curr] - f[next][curr]);
            curr = next;
        }
        curr = e;
        while(curr != s){
            ll next = visited[curr];
            f[next][curr] += minn;
            f[curr][next] -= minn;
            curr = next;
        }
        ans += minn;
    }
    
    cout << N-ans;
    
	return 0;
} // Edmond-Karp, Max-flow