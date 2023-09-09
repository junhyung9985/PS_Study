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
    if(*it == val) OS.erase(it);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, K;
    cin >> N >> K;
    
    vector<ll> v(N);
    ordered_set s;
    ll ans = 0;
    
    for(int i =0;i<N; i++){
        cin >> v[i];
        s.insert(v[i]);
        if(s.size() > K){
            m_erase(s, v[i-K]);
        }
        if(s.size() == K){
            auto itr = s.find_by_order((K-1)/2);
            ans += *itr;
        }
    }

    cout << ans;

    return 0;
}
/*

원래 풀이는 아마 이분탐색 세그일텐데
PBDS로 깔끔하게 해결~

*/