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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> v(N);
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<ll>());

    vector<pair<ll,ll>> b(K);

    for(int i =0; i<K; ++i){
        ll p, q;
        cin >> p >> q;
        b[i] = {p,q};
    }

    ll ans = 0;
    for(int j =0; j<M; ++j){
        ll maxx_j =0;
        for(int i =0; i<pow(2,K); ++i){
            ll tmp = i;
            ll tmp_ans = 0;
            int idx = 0;
            bool flag = true;
            ll time = 0;
            for(int idx = 0; idx <K; ++idx){
                if(tmp%2){
                    ll p , q;
                    tie(p,q) = b[idx];
                    time += (p/v[j]);
                    if(p%v[j]) ++time;
                    tmp_ans += q;
                }
                tmp/=2;
            }
            if(time <= 900) maxx_j = max(maxx_j, tmp_ans);
        }
        //cout << maxx_j <<"\n";
        ans += maxx_j;
    }
    cout << ans<<"\n";


    return 0;
}
/*
M(2^13) = Greedy + Sorting + Bruteforce

*/