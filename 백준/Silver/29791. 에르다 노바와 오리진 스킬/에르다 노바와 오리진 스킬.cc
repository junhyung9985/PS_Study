#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> B(M);

    ll bef = -100;
    ll bef2 = -360;
    ll cnt = 0, cnt2= 0;

    for(int i =0; i<N; ++i)
        cin >> A[i];
    
    for(int i=0; i<M; ++i)
        cin >> B[i];
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i =0; i<N; ++i){
        if(A[i]-bef >=100){
            cnt++;
            bef = A[i];
        }
    }

    for(int i =0; i<M; ++i){
        if(B[i]-bef2 >=360){
            cnt2++;
            bef2 = B[i];
        }
    }
    cout << cnt <<" "<< cnt2<<"\n";

    return 0;
}