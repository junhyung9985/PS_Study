#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M, K;
char arr[10][10];
vector<string> v;
    

ll dfs(int i, int j, int depth, int curr){
    if(arr[i][j] != v[curr][depth]){
        return 0;
    }
    if(depth == v[curr].length()-1) return 1;
    ll ret = 0;
    ret += dfs((i+N-1)%N, (j+M-1)%M, depth+1, curr);
    ret += dfs((i+N)%N, (j+M-1)%M, depth+1, curr);
    ret += dfs((i+N+1)%N, (j+M-1)%M, depth+1, curr);
    ret += dfs((i+N-1)%N, (j+M)%M, depth+1, curr);
    ret += dfs((i+N+1)%N, (j+M)%M, depth+1, curr);
    ret += dfs((i+N-1)%N, (j+M+1)%M, depth+1, curr);
    ret += dfs((i+N)%N, (j+M+1)%M, depth+1, curr);
    ret += dfs((i+N+1)%N, (j+M+1)%M, depth+1, curr);
    
    return ret;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<string, ll> if_exist;
    
    cin >> N >> M >> K;
    
    for(int i =0; i<N ;i++)
        for(int j =0; j<M ; j++)
            cin >> arr[i][j];
    
    for(int i =0; i<K; i++){
        string tmp;
        cin >> tmp;
        v.push_back(tmp);
        if(if_exist.find(tmp) != if_exist.end()){
            cout << if_exist[tmp]<<"\n";
            continue;
        }
        
        ll ans = 0;
        for(int j = 0;j <N; j++)
            for(int k =0; k<M; k++)
                ans += dfs(j, k, 0, i);
        if_exist[v[i]] = ans;
        cout << ans<<"\n";
    }
    
    
    
    
    
    
    
    
    return 0;
}