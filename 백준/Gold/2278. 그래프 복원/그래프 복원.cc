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

    ll N, M;

    cin >> N >> M;
    if(M < N-1){
        cout << 0;
        return 0;
    }
    if(N == 1){
        cout << 0;
        return 0;
    }


    deque<tuple<ll,ll,ll>> q;
    vector<vector<ll>> v(N, vector<ll>(N, INT_MAX));
    vector<vector<ll>> f(N, vector<ll>(N));
    vector<vector<bool>> check(N, vector<bool>(N, false));

    for(int i =0; i<N-1; ++i){
        for(int j = i+1; j<N; ++j){
            ll v;
            cin >> v;
            f[i][j] = v;
            f[j][i] = v;
            q.push_back({v,i+1,j+1});
        }
        v[i][i] = 0;
    }
    v[N-1][N-1] = 0;
    sort(q.begin(), q.end());

    vector<tuple<ll,ll,ll>> ans;
    
    while(!q.empty()){
        ll val, a, b;
        tie(val, a, b) = q.front();
        q.pop_front();
        if(v[a-1][b-1] == val) continue;
        else if(v[a-1][b-1] > val){
            if(M<=0){
                cout << 0;
                return 0;
            }
            ans.push_back({a,b,val});
            --M;
            v[a-1][b-1] = val;
            v[b-1][a-1] = val;
            vector<ll> dist_a(N, INT_MAX);
            dist_a[a-1] = 0;
            vector<ll> dist_b(N, INT_MAX);
            dist_b[b-1] = 0;
            check[a-1][b-1] = check[b-1][a-1] = true;
            priority_queue<pair<ll,ll>> pq;
            pq.push({0,a-1});
            while(!pq.empty()){
                ll d, n;
                tie(d,n) = pq.top();
                pq.pop();
                d *= -1;
                if(dist_a[n] < d) continue;
                for(int j =0; j<N; ++j){
                    if(j == n) continue;
                    if(v[n][j] == INT_MAX) continue;
                    if(dist_a[j] > d + v[n][j]){
                        dist_a[j] = d + v[n][j];
                        dist_a[j] = d + v[n][j];
                        pq.push({-dist_a[j], j});
                    }    
                }
            }
            pq.push({0,b-1});
            while(!pq.empty()){
                ll d, n;
                tie(d,n) = pq.top();
                pq.pop();
                d *= -1;
                if(dist_b[n] < d) continue;
                for(int j =0; j<N; ++j){
                    if(j == n) continue;
                    if(v[n][j] == INT_MAX) continue;
                    if(dist_b[j] > d + v[n][j]){
                        dist_b[j] = d + v[n][j];
                        dist_b[j] = d + v[n][j];
                        pq.push({-dist_b[j], j});
                    }    
                }
            }

            for(int i =0; i<N; ++i){
                for(int j =0; j<N; ++j){
                    if(v[i][j] > dist_a[i]+v[a-1][b-1]+dist_b[j]){
                        v[i][j] = dist_a[i]+v[a-1][b-1]+dist_b[j];
                        v[j][i] = dist_a[i]+v[a-1][b-1]+dist_b[j];
                    }
                }
            }
            
        }
        else {
            cout << 0;
            return 0;
        }

    } // O(N^2+M(N^2logN+N^2))

    bool flag = true;
    for(int i =0; i<N; ++i){
        for(int j =0; j<N; ++j){
            //cout << v[i][j]<<" ";
            flag = flag && (v[i][j] == f[i][j]);
        }
        //cout<<"\n";
    }

    if(!flag){
        cout <<0;
        return 0;
    }


    for(int i = 0 ;i<N; ++i){
        for(int j =0; j<N; ++j){
            if(i == j) continue;
            if(!check[i][j]){
                if(M > 0){
                    --M;
                    ans.push_back({i+1,j+1,500});
                }
            }
        }
    }
    if(M > 0){
        cout << 0;
        return 0;
    }


    cout<<1<<"\n";
    for(auto itr : ans){
        ll a, b, c;
        tie(a,b,c) = itr;
        cout << a <<" "<<b <<" "<<c<<"\n";
        check[a-1][b-1] = check[b-1][a-1] = true;
    }


    return 0;
} // Dijkstra, Constructive, Greedy, Sorting