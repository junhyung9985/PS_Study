#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<ll> A(1001,-1), B(1001,-1);
vector<vector<ll>> m(1001);
vector<bool> visited;
ll excluded = 0; // 첫 번째 원소와 이미 매칭된 원소의 인덱스

bool DFS(ll n){
    visited[n] = true;
    for(auto itr : m[n]){
        if(itr == excluded) continue;
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    set<ll> primes;
    vector<bool> prime(5001, false);
    for(int j = 2; j<=5000; ++j){
        if(prime[j]) continue;
        primes.insert(j);
        prime[j] = true;
        for(int i = 2*j; i<=5000; i+=j)
            prime[i] = true;
    }


    ll N;
    cin >> N;
    if(N%2){
        cout << -1;
        return 0;
    }

    vector<ll> v(N);
    for(int i =0; i<N; ++i)
        cin >> v[i];
    
    for(int i =1; i<N; ++i){
        if(v[i]%2 == v[0]%2){
            for(int j = 1; j<N; ++j){
                if(i == j) continue;
                if(primes.find(v[i]+v[j]) != primes.end()){
                    m[i].push_back(j);
                }
            }
        }
    }

    vector<ll> ans;
    for(int i =1; i<N; ++i){
        if(primes.find(v[i]+v[0]) == primes.end()) continue;        
        excluded = i;
        fill(A.begin(), A.end(), -1);
        fill(B.begin(), B.end(), -1);
        ll match = 1;
        for(int j = 1; j<N; ++j){
            if(v[j]%2 == v[0]%2 && A[j] == -1){
                visited.clear();
                visited.resize(N+1, false);
                if(DFS(j)) ++ match;
            }
        }
        if(match * 2 == N){
            ans.push_back(v[i]);
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size() == 0){
        cout << -1;
    }
    for(auto itr : ans){
        cout << itr <<" ";
    }

    return 0;
} // 이분 매칭, 중복이 없으므로 짝홀 나눠서 그룹을 만들면 된다!