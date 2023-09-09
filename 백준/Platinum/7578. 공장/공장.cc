#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

ll m[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    int idx = 0;
    cin >> N;

    ordered_set s;

    for(int i =0; i<N; i++){
        ll a;
        cin >> a;
        m[a] = idx++;
    }

    ll ans = 0;
    for(int i = 0 ; i<N; i++){
        ll b;
        cin >> b;
        b = m[b];
        ans += s.size()-s.order_of_key(b);
        s.insert(b);
    }

    cout << ans;

    return 0;
}
// 아마도 세그?
// map이나 array를 써서 이를 index로 변형 
    // -> 순서대로 받은 아이디를 index로 변형해서 index+1 ~ N-1 까지의 합을 구하는 문제였을 듯?
// 아니면 진짜 LIS인가 싶가도 하고...
// 근데 세그일 가능성이 더 높음 ㅇㅇ