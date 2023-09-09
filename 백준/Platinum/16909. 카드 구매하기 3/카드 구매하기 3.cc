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

    ll N;
    cin >> N;
    vector<ll> v(N);
    vector<tuple<ll,ll>> v1(N);
    vector<tuple<ll,ll>> v2(N);

    ll ans = 0;
    for(int i=0; i<N; i++){
        cin >> v[i];
        v1[i] = {-1, N-1};
        v2[i] = {-1, N-1};
    }

    deque<tuple<ll, ll>> stck;
    deque<tuple<ll, ll>> stck2;

    for(int i =0; i<N; i++){
        
        while(!stck.empty()){
            ll val, idx;
            tie(val, idx) = stck.back();
            if(val >= v[i]){
                get<1>(v2[idx]) = i-1; // 어디까지 영향력이 미치는가?
                get<0>(v2[i]) = get<0>(v2[idx]); // i는 적어도 idx 영향력이 미치기 시작하는 부분 부터는 영향력이 있음.
                stck.pop_back();
            }
            else {
                if(val < v[i]){
                    get<0>(v2[i]) = idx;
                }
                else get<0>(v2[i]) = get<0>(v2[idx]);
                break;
            }
        }
        stck.push_back({v[i], i});
    }

    for(int i =0; i<N; i++){
        
        while(!stck2.empty()){
            ll val, idx;
            tie(val, idx) = stck2.back();
            if(val <= v[i]){
                get<1>(v1[idx]) = i-1; // 어디까지 영향력이 미치는가?
                get<0>(v1[i]) = get<0>(v1[idx]); // i는 적어도 idx 영향력이 미치기 시작하는 부분 부터는 영향력이 있음.
                stck2.pop_back();
            }
            else {
                if(val > v[i]){
                    get<0>(v1[i]) = idx;
                }
                else get<0>(v1[i]) = get<0>(v1[idx]);
                break;
            }
        }
        stck2.push_back({v[i], i});
    }
    ll n_s = 0;
    for(int i =0; i<N; i++){
        ans += ((get<1>(v1[i])+1 - i) * (i - get<0>(v1[i])))*v[i];
        //n_s += ((get<1>(v1[i])+1 - i) * (i - get<0>(v1[i])));
        ans -= ((get<1>(v2[i])+1 - i) * (i - get<0>(v2[i])))*v[i];
    }
    
    cout << ans; //<< " "<< n_s;
    return 0;
}
/*



low .... idx ... high
low+1 -> idx, idx+1 ... high-1
....
idx -> idx, idx+1 ... high-1

그러므로 저 식이 나옴.

ascending / descending order로 sorting 해서 
큰 수의 값 val, 원래 위치 idx를 알아내어
이후 이분탐색으로 이미 본 index중 idx보다 낮은 수 중 최대 및 idx보다 높은 수 중 최소를 찾아서 확인

이후에서 식을 써서 풀면 됨

빼기도 비슷하게

O(NlogN)


-> O(N)으로 구현해야함.

히스토그램 활용 -> {a, b} => a+1 부터 b까지는 일단 내가 최대 / 최소다 이걸 나타내고 이를 계산.

*/