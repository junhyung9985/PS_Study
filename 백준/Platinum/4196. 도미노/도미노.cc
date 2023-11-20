#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M;
ll cnt = 1;

vector<vector<ll>> E;
//vector<vector<ll>> SCC;
vector<ll> dfs_n;
vector<bool> finished;
vector<ll> stck;

vector<ll> which_SCC; // 각 노드가 어느 SCC에 속해있는가?
vector<ll> ind_SCC; // 해당 SCC의 in-degree
ll idx = 0;

ll DFS(ll n){
    dfs_n[n] = cnt++; // 몇 번째로 DFS로 찾았는 가를 갱신
    ll ret = dfs_n[n]; // 현재 노드로 부터 제일 높이 올라갈 수 있는 노드 번호
    stck.push_back(n); // 스택에 삽입
    
    for(auto itr : E[n]){
        if(!dfs_n[itr]) ret = min(DFS(itr), ret); // 아직 탐색 안 한 노드
        else if(!finished[itr]) ret = min(ret, dfs_n[itr]); // 이미 탐색했으나 어느 SCC에도 속하지 않은 노드
    } // 그래프 탐색
    
    if(ret == dfs_n[n]){
        // vector<ll> scc;
        while(stck.back() != n){
            ll num = stck.back();
            stck.pop_back();
            finished[num] = true;
            which_SCC[num] = idx;
        }
        stck.pop_back();
        
        finished[n] = true;
        which_SCC[n] = idx;
        ++idx;
        
        ind_SCC.push_back(0);
    }
    
    return ret;
} // SCC - Tarjan Algorithm 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--){
        cin >> N >> M;
        E.resize(N+1, vector<ll>());
        dfs_n.resize(N+1, 0);
        finished.resize(N+1, false);
        which_SCC.resize(N+1, -1);
        
        for(int i =0; i<M; ++i){
            ll a, b;
            cin >> a >> b;
            E[a].push_back(b);
        }
        
        for(int i =1; i<=N; ++i){
            if(!dfs_n[i]) DFS(i);
        } // Find SCC
        
        for(int i =1; i<=N; ++i){
            for(auto itr : E[i]){
                if(which_SCC[i] != which_SCC[itr]){
                    ind_SCC[which_SCC[itr]]++;
                }
            }
        }
        
        ll ans = 0;
        for(int i =0; i<idx; ++i){
            if(ind_SCC[i] == 0) ++ans;
        }
        
        cout << ans <<"\n";
        
        E.clear();
        dfs_n.clear();
        finished.clear();
        which_SCC.clear();
        ind_SCC.clear();
        idx = 0;
        cnt = 1;
    }
    return 0;
} // SCC, Topological Sorting
/*

SCC를 하나의 노드라고 생각하면 항상 DAG 구조의 그래프가 만들어지는 걸 확인할 수 있음.

이를 활용하는 문제!

*/