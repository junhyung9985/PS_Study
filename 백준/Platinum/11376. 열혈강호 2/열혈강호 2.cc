#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, M;
int A[2001], B[1001];
vector<int> m[1001];
int visited[2001];

bool DFS(int n){
    visited[n] = 1;
    int check = n;
    if(check > N) check -= N;
    for(auto itr : m[check]){
        if(B[itr] == 0 || !visited[B[itr]] && DFS(B[itr])){
            A[n] = itr;
            B[itr] = n;
            return true;
            // 아직 일이 할당되지 않았거나, 
            // 아니면 할당이 되어 있는데 할당 된 얘에 대해서는 아직 보지를 않았던가
            // 확인 후 얘에 대해서 매칭 가능하면 참을 리턴함!
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i<=N; ++i){
        int t;
        cin >> t;
        while(t--){
            int work;
            cin >> work;
            m[i].push_back(work);
        }
    }
    
    int ans = 0;
    for(int i = 1; i<=2*N; ++i){
        if(A[i] == 0){
            fill(visited, visited+2*N, 0);
            if(DFS(i)) ++ ans;
        }
    }
    
    cout << ans;
    
	return 0;
} 
// Bipartite Matching