#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, C;
    cin >> N >> C;
    
    vector<ll> v1;
    vector<ll> v2;
    
    for(int i =0; i<N; ++i){
        ll tmp;
        cin >> tmp;
        if(i < N/2) v1.push_back(tmp);
        else v2.push_back(tmp);
    }
    
    ll n1 = v1.size(), n2 = v2.size();
    
    vector<ll> va, vb;
    
    for(ll i =0; i<pow(2,n1); ++i){
        ll tmp = i;
        ll idx = 0;
        ll weight = 0;
        while(tmp){
            if(tmp%2) weight += v1[idx];
            ++idx;
            tmp/=2;
        }
        va.push_back(weight);
    }
    for(ll i =0; i<pow(2,n2); ++i){
        ll tmp = i;
        ll idx = 0;
        ll weight = 0;
        while(tmp){
            if(tmp%2) weight += v2[idx];
            ++idx;
            tmp/=2;
        }
        vb.push_back(weight);
    }
    
    sort(vb.begin(), vb.end());
    
    ll ans = 0;
    for(ll a : va){
        ll t = C-a;
        ans += upper_bound(vb.begin(), vb.end(), t) - vb.begin();
        //cout << a << " "<<ans<<"\n";
    }
    cout << ans;
    
    return 0;
}
/* Bitmasking, MITM */
