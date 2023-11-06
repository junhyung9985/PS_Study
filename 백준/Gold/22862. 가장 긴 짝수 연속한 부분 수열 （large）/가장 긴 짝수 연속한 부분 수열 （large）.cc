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
    ll N, K;
    cin >> N >> K;

    vector<ll> v(N);
    vector<ll> vals;
    vector<ll> pf;
    vector<ll> s;
    bool first = false;
    ll cnt = 0;
    for(int i =0; i<N; ++i){
        cin >> v[i];
        if(v[i] % 2 == 0){
            ++cnt;
            first = true;
        }
        else if(first){
            if(cnt > 0){
                vals.push_back(cnt);
                cnt = 0;
                s.push_back(1);
            }
            else s.back()++;
        }
    }
    if(cnt > 0){
        vals.push_back(cnt);
    }
    else if(!s.empty()) s.pop_back();
    if(vals.empty()){
        cout << 0;
        return 0;
    }
    else if(s.empty()){
        cout << vals[0];
        return 0;
    }

    pf.resize(vals.size());
    pf[0] = vals[0];
    for(int i = 1 ;i <s.size(); ++i){
        s[i] += s[i-1];
    }
    for(int i =1; i<vals.size(); ++i){
        pf[i] = vals[i]+pf[i-1];
    }

    ll ans = 0;
    for(int i =0; i < vals.size(); ++i){
        ll tmp = vals[i];
        ll l = i-1, r = s.size();
        while(l+1 < r){
            ll mid = (l+r)/2;
            ll val = s[mid];
            if(i > 0){
                val -= s[i-1];
            }
            if(val > K) r = mid;
            else l = mid; 
        } 
        if(l > i-1){
            tmp += pf[l+1] - pf[i];
        }
        //cout << tmp <<" "<< l <<"\n";
        ans = max(ans, tmp);
    }

    cout << ans;
    
    return 0;
} // Binary Search, Prefix Sum
// O(NlogN)