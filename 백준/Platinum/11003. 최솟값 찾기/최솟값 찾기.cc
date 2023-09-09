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
    ll N, L;
    cin >> N >> L;
    deque<pair<ll,ll>> q;
    for(int i =0; i<N; i++){
        ll n;
        cin >> n;
        ll until = i-L+1;
        if(until < 0 ) until = 0;
        while(!q.empty()){
            if(q.front().second < until)
            q.pop_front();
            else break;
        } // 빠른건 여기에 계속 저장
        while(!q.empty()){
            if(q.back().second < until || q.back().first > n)
            q.pop_back();
            else break;
        } // 입력값보다 더 큰것들은 제거  -> 들어올 시점부터는 걔가 필요없으므로!
        
        q.push_back({n,i});

        cout << q.front().first <<" ";
    }
    return 0;
}
