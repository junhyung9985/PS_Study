#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<ll> v(N);
    vector<ll> ans(N);
    for(int i =0; i<N; ++i){
        cin >> v[i];
        for(int j =i-1; j>-1; --j){
            ll to = v[j];
            ll cnt = i-j;
            ll diff = v[i]-v[j];
            bool flag = true;
            for(int k = j+1; k<i; ++k){
                ll diff2 = v[i]-v[k];
                ll cnt2 = i-k;
                //cout << i <<" "<<j <<" : "<< i <<" "<<k <<" "<<diff*cnt2 <<" "<<diff2*cnt<<"\n";
                if(diff * cnt2 >= diff2 * cnt) flag = false;
            }
            if(flag){
                ++ans[i];
                ++ans[j];
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.back();
    
    return 0;
} // Geometry, Bruteforcing
