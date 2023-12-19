#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<ll> A(N);
    ll ans = 0;
    for(int i =0; i<N; ++i){
        cin >> A[i];
        ans ^= (A[i]*A[i]);
    }
    sort(A.begin(), A.end());
    for(int i =0; i<N-1; ++i){
        ans ^= (A[i]*A[i+1]);
    }
    cout << ans;
    
    return 0;
} // Bitmasking, Math
// X가 k번째로 큰 수라면 k번째가 제일 작고, l번째가 제일 큰 수인 조합은 2^(l-k-1)가지의 경우가 나온다.
// 이걸 생각하면 k와 k+1번째의 수를 곱한 것만 XOR에 반영이 된다. (홀수번 XOR해야 반영이 됨.)
// 또한 (k,k)는 딱 한 번씩만 나오므로 ans에 XOR이 반영된다.