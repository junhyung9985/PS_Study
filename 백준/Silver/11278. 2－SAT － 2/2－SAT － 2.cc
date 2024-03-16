#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    vector<pair<ll,ll>> v(M);
    for(int i =0; i<M; ++i){
        cin >> v[i].first >> v[i].second;
    }
    
    for(int i =0; i<1'048'576; ++i){
        int tmp = i;
        vector<ll> ans(N+1);
        for(int j = 1; j<=N; ++j){
            ans[j] = tmp%2;
            tmp/=2;
        }
        bool flag = true;
        for(int j =0; j<M; ++j){
            ll a,b;
            tie(a,b) = v[j];
            ll a_t = 1, b_t = 1;
            if(a < 0) a_t = 0, a *= -1;
            if(b < 0) b_t = 0, b *= -1;
            flag = flag &&(a_t == ans[a] || b_t == ans[b]);
            if(!flag) break;
        }
        if(flag){
            cout << "1\n";
            for(int i = 1; i<=N; ++i)
                cout << ans[i]<<" ";
            return 0;
        }
    }
    cout << "0";
    
    return 0;
}