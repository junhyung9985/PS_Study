#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K;
vector<ll> parents;
vector<ll> eff;
unordered_map<ll,unordered_map<ll,ll>> m;
vector<ll> A;

vector<unordered_set<ll>> distinct_eff;
vector<unordered_multiset<ll>> group_eff;
multiset<ll> group_rank;

ll f(ll n){
    if(parents[n] == n) return n;
    return parents[n] = f(parents[n]);
}

void u(ll a, ll b){
    ll pa = f(a);
    ll pb = f(b);
    if(pa == pb) return;

    if(group_eff[pa].size() < group_eff[pb].size()){
        ll tmp = pa;
        pa = pb;
        pb = tmp;
    }
    parents[pb] = pa;
    
    auto itr = group_rank.find(eff[pa]);
    group_rank.erase(itr);
    itr = group_rank.find(eff[pb]);
    group_rank.erase(itr);
    eff[pa] += eff[pb];
    group_rank.insert(eff[pa]);
    
    for(auto itr : group_eff[pb]){
        group_eff[pa].insert(itr);
    }
    
    for(auto itr : distinct_eff[pb]){
        distinct_eff[pa].insert(itr);
    }
    
    return;
}

unordered_set<ll> dfs;
    
void DFS(int n , int p){
    u(p,n);
    //cout << n <<" "<<p<<"\n";
    bool flag = true;
    while(!dfs.empty() && flag){
        flag = false;
        for(auto itr2 = dfs.begin(); itr2!=dfs.end();){
            auto itr = itr2;
            itr2++;
            int next_n = *itr;
            if(m[n][next_n]>= K) {continue;}
            else {
                dfs.erase(itr);
                DFS(next_n,p);
                flag = true;
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll Q;
    cin >> N >> K;

    A.resize(N);
    parents.resize(N);
    eff.resize(N);
    distinct_eff.resize(N);
    group_eff.resize(N);

    for(int i =0; i<N; ++i){
        cin >> A[i];
        parents[i] = i;
        eff[i] += A[i];
    }

    cin >> Q;
    vector<vector<pair<ll,ll>>> edges(Q);
    vector<ll> query_type(Q);
    vector<ll> ans(Q);
    vector<pair<ll,ll>> q_3(Q);

    for(int i = 0; i < Q; ++i){
        ll q;
        cin >> q;
        query_type[i] = q;
        if(q == 1){
            vector<ll> b(2*N);
            vector<ll> vis(N);
            for(int j =0 ;j <2*N; ++j){
                cin >> b[j];
                --b[j];
            }
            bool flag = true;
            for(int j =0; j<2*N; ++j){
                if(j > 0){
                    if(m[b[j-1]][b[j]] >= K){
                        flag = false;
                        break;
                    }
                }
                vis[b[j]] = 1;
            }
            if(!flag){
                ans[i] = -1;
                continue;
            }
            for(int j =1; j<2*N; ++j){
                if(b[j] == b[j-1]) continue;
                ++m[b[j]][b[j-1]];
                ++m[b[j-1]][b[j]];
                if(m[b[j]][b[j-1]] >= K){
                    edges[i].push_back({b[j],b[j-1]});
                } 
            }
            for(int j = 0; j<N; ++j){
                ans[i] += vis[j]*A[j];
            }
        }
        if(q == 2){
            ll s, t, x;
            cin >> s >> t >> x;
            if(m[s-1][t-1] >= K) continue;
            m[s-1][t-1] += x;
            m[t-1][s-1] += x;
            if(m[s-1][t-1] >= K)
                edges[i].push_back({s-1, t-1});
        }
        if(q == 3){
            ll s, x;
            cin >> s >> x;
            --s;
            q_3[i] = {s,x};
            A[s] += x;
            eff[s] += x;
            
        }
    }

    for(int i =0 ;i<N; ++i){
        group_eff[i].insert(eff[i]);
        distinct_eff[i].insert(eff[i]);
        group_rank.insert(eff[i]);
    }

    for(int i =0; i<N; ++i){
        dfs.insert(i);
    }

    while(!dfs.empty()){
        auto itr = dfs.begin();
        int n = *itr;
        //cout << n <<"\n";
        dfs.erase(itr);
        DFS(n, n);
    }

    for(int i = Q-1; i >-1; --i){
        if(query_type[i] == 2){
            auto itr = group_rank.end();
            itr --;
            ans[i] = *(itr);
        }
        if(query_type[i] == 3){
            ll node, down;
            tie(node, down) = q_3[i];
            
            ll p_node = f(node);
            ans[i] = distinct_eff[p_node].size();

            auto itr = group_rank.find(eff[p_node]);
            group_rank.erase(itr);
            eff[p_node] -= down;
            group_rank.insert(eff[p_node]);

            auto itr2 = group_eff[p_node].find(A[node]);
            group_eff[p_node].erase(itr2);
            if(group_eff[p_node].find(A[node]) == group_eff[p_node].end()){
                distinct_eff[p_node].erase(A[node]);
            }
            A[node] -= down;
            group_eff[p_node].insert(A[node]);
            distinct_eff[p_node].insert(A[node]);

        }
        for(pair<ll,ll> edge : edges[i]){
            u(edge.first, edge.second);
        }
    }

    for(int i = 0; i<Q; ++i){
        cout << ans[i]<<"\n";
    }

    return 0;
}

// Subtask 5 solution , q <= 3, Amortized DFS solution