#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K;
vector<ll> p;
vector<vector<ll>> must;
vector<ll> group;
map<ll,pair<ll,ll>> groups;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    
    p.resize(N+1);
    group.resize(N+1);
    must.resize(N+1, vector<ll>());
    for(int i =1 ; i<=N; i++){
        cin >> p[i];
    }
    
    for(int i =1; i<=N; i++){
        vector<bool> visited(N+1);
        int to = i;
        while(!visited[to]){
            visited[to] = true;
            must[i].push_back(to);
            to = p[to];
        }
    }
    
    
    for(int i =1; i<=N; i++){
        if(group[i]) continue;
        ll g = i;
        int to = i;
        vector<bool> visited(N+1);
        vector<bool> visited2(N+1);
        
        while(!visited[to]){
            visited[to] = true;
            if(group[to]){
                g = group[to];
                break;
            }
            to = p[to];
        }
        
        group[i] = g; 
        to = i;
        while(!visited2[to]){
            visited2[to] = true;
            if(!group[to]) group[to] = g;
            else {
                break;
            }
            to = p[to];
        }
    }
    
    for(int i =1; i<=N; i++){
        if(groups.find(group[i]) == groups.end()){
            groups[group[i]] = {INT_MAX, 0};
        }
        ll minn = min(groups[group[i]].first, (ll)must[i].size());
        groups[group[i]] = {minn, groups[group[i]].second+1};
    }
    
    vector<pair<ll,ll>> sweep;
    
    for(auto itr : groups){
        //cout << itr.second.first << " "<< itr.second.second<<"\n";
        sweep.push_back(itr.second);
    }
    
    ll dp[1001][1001];
    memset(dp, 0, sizeof(dp));
    for(int i =1; i<=sweep.size();i++){
        ll weight = sweep[i-1].first;
        ll val = sweep[i-1].second;
        
        for(int j =0; j<=K; j++){
            if(j >= weight){
                dp[i][j] = max(dp[i-1][j-weight]+val, dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    // for(int i =1; i<=sweep.size(); i++){
    //     for(int j =0; j<=K; j++)
    //         cout << dp[i][j] <<" ";
    //     cout <<"\n";
    // }
    cout << min(dp[sweep.size()][K], K);
    
    
    return 0;
}
/*
    out-degree가 1인 그래프 -> 사이클 1개만 존재
    
    한 connected component에서 노드들을 뽑을 때 나올 수 있는 개수에 대한 경우의 수 : [cycle 내의 노드 개수 , component 내의 노드 개수]
    
    즉, connected component들을 적절히 조합하여 K 이하 중 최대가 나오도록 해야함.
    -> A = {a,b} , B = {c, d} 라면 A,B를 조합 시 {a+c, b+d}로 된다.
    
    특정 최소 개수에서 range 크기가 최대가 되는 경우의 수를 찾는 것으로 문제를 생각한다면 
    최소 개수를 weight로 최대 개수를 value로 하는 Knapsack으로 변형이 가능하다.
    
    그래서 Knapsack으로 풀었다.
*/