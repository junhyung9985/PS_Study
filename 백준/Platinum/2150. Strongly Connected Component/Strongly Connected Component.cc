#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M;
ll cnt = 1;

vector<vector<ll>> E;
vector<vector<ll>> SCC;
vector<ll> dfs_n;
vector<bool> finished;
vector<ll> stck;

ll DFS(ll n){
    dfs_n[n] = cnt++; // 몇 번째로 DFS로 찾았는 가를 갱신
    ll ret = dfs_n[n]; // 현재 노드로 부터 제일 높이 올라갈 수 있는 노드 번호
    stck.push_back(n); // 스택에 삽입
    
    for(auto itr : E[n]){
        if(!dfs_n[itr]) ret = min(DFS(itr), ret); // 아직 탐색 안 한 노드
        else if(!finished[itr]) ret = min(ret, dfs_n[itr]); // 이미 탐색했으나 어느 SCC에도 속하지 않은 노드
    } // 그래프 탐색
    
    if(ret == dfs_n[n]){
        vector<ll> scc;
        while(stck.back() != n){
            ll num = stck.back();
            stck.pop_back();
            scc.push_back(num);
            finished[num] = true;
        }
        stck.pop_back();
        scc.push_back(n);
        finished[n] = true;
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    }
    
    return ret;
} // SCC - Tarjan Algorithm 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    E.resize(N+1, vector<ll>());
    dfs_n.resize(N+1, 0);
    finished.resize(N+1, false);
    
    for(int i =0; i<M; ++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
    }
    
    for(int i =1; i<=N; ++i){
        if(!dfs_n[i]) DFS(i);
    }
    
    sort(SCC.begin(), SCC.end());
    
    cout << SCC.size()<<"\n";
    for(auto itr : SCC){
        for(auto itr2 : itr)
            cout << itr2<<" ";
        cout <<"-1\n";
    }
    
    return 0;
} // SCC - Tarjan Algorithm