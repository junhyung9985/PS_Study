#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    OS.erase(it);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, D;    
    cin >> N;
    vector<pair<ll,ll>> v;
    vector<pair<ll,ll>> v2;
    for(int i =0; i<N; i++){
        ll h, o;
        cin >> h >> o;
        if( h > o) {
            ll tmp = h;
            h = o;
            o = tmp;
        }
        v.push_back({h,o});
        v2.push_back({o,h});
    }
    cin >> D;
    sort(v.begin() ,v.end());

    ordered_set s;
    for(int i =0; i<N; i++)
        s.insert(v[i].second);
        
    ll ans = 0;
    ll l_val = 0;

    for(int i =0 ;i<N; i++){
        l_val = v[i].first;
        ll cnt2 = s.order_of_key(l_val+D+1);
        ans = max(ans, cnt2);
        m_erase(s, v[i].second);
    }
    cout << ans;
    
    return 0;
}
// PBDS로는 쉽게 풀리는 문제
// 아마도 스위핑 이분탐색 같긴한데 흠...