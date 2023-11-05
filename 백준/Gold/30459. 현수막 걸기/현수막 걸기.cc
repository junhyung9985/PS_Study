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

    ll N, M, R;
    cin >> N >> M >> R;

    cout.precision(1);
    cout << fixed;
    
    double ans = 0.0;
    
    vector<ll> a(N);
    vector<ll> b(M);

    for(int i =0; i<N; ++i) cin >> a[i];
    for(int j =0; j<M; ++j) cin >> b[j];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i =0; i<N; ++i){
        for(int j =i+1; j<N; ++j){
            ll base = (a[j]-a[i]) * 1.0;
            ll l = -1 , r = M;

            while(l+1 < r){
                ll mid = (l+r)/2;
                if(b[mid] * base * 1.0 > 2*R) r = mid;
                else l = mid;
            }
            if( l == -1) continue;
            ans = max(ans, (double)(base * b[l]) * 0.5);
        }
    }

    if(ans == 0.0){
        cout << "-1";
        return 0;
    }

    cout << ans;

    return 0;
} // Binary Search, Bruteforcing
// O(N^2logM)