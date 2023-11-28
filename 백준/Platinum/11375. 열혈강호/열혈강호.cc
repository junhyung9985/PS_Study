#include <bits/stdc++.h>
#define ll long long
#define INF 987654321
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<ll,ll>, null_type, less_equal<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>

ll N, M;
vector<ll> A(1001,-1), B(1001,-1);
vector<vector<ll>> m(1001);
vector<bool> visited;

bool DFS(ll n){
    visited[n] = true;
    for(auto itr : m[n]){
        if(B[itr] == -1 || !visited[B[itr]] && DFS(B[itr])){
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
    ll N, M;
    cin >> N >> M;
    for(int i = 1; i<=N; ++i){
        ll t;
        cin >> t;
        while(t--){
            ll work;
            cin >> work;
            m[i].push_back(work);
        }
    }
    
    ll ans = 0;
    for(int i = 1; i<=N; ++i){
        if(A[i] == -1){
            visited.clear();
            visited.resize(N+1, false);
            if(DFS(i)) ++ ans;
        }
    }
    
    cout << ans;
    
	return 0;
} 
// Bipartite Matching