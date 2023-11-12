#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<ll> visited;
set<ll> AP;
vector<vector<ll>> E;

ll DFS(ll n, bool flag){
    ll val  = visited[n]; // 현재 노드의 방문번호
    ll minn = visited[n]; // 현재까지 Back Edge중에서 제일 빠른 방문 번호
    ll cnt = 0;
    for(auto itr : E[n]){
        ll ret = visited[itr]; // 이미 탐색했다면 방문 번호가 더욱 빠를 것이므로 일단 이렇게 찾음.
        
        if(visited[itr] == -1){ // 아직 탐색하지 못한 경우에는 탐색
            visited[itr] = val+1;
            ret = DFS(itr, false);
            ++cnt;
            if(val <= ret && !flag){
                AP.insert(n);
            } // 검색 결과 현재 노드보다 더 빠른 방문 번호를 못 찾았으면 AP임.
        }

        minn = min(minn, ret);
    }
    if(flag && cnt >= 2) AP.insert(n); // 루트 노드 예외 처리

    return minn;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;
    visited.resize(N+1, -1);
    E.resize(N+1);
    for(int i = 0; i<M; ++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    for(int i = 1; i<=N; ++i){
        if(visited[i] == -1){
            visited[i] = 1;
            DFS(i, true);            
        }
    }

    cout << AP.size()<<"\n";
    for(auto itr : AP)
        cout << itr <<" ";

    return 0;
} // Articulation Point
// https://codingsmu.tistory.com/95