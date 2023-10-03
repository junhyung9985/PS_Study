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
    ll N, M, L, K;
    cin >> N >> M >> L >> K;

    vector<pair<ll, ll>> v(K);
    for(int i =0; i<K; ++i){
        cin >> v[i].first >> v[i].second;
    }

    ll ans = 0;

    for(int i =0; i<K; ++i){
        for(int j =0; j<K; ++j){
            ll ans1 = 0, ans2 = 0, ans3 =0, ans4 = 0;
            ll x = v[i].first, y = v[j].second;
            for(int k = 0; k<K; ++k){
                ll x1, y1;
                tie(x1,y1) = v[k];
                ll x_cord = 0;
                if(x >= x1 && x-L <= x1){
                    if(y >= y1 && y-L <= y1){
                        ++ans1;
                    }
                    if(y <= y1 && y+L >= y1){
                        ++ans2;
                    }
                }
                if (x <= x1 && x+L >= x1){
                    if(y >= y1 && y-L <= y1){
                        ++ans3;
                    }
                    if(y <= y1 && y+L >= y1){
                        ++ans4;
                    }
                }
            }
            //cout << x <<" "<<y <<" : "<<ans1 <<" "<<ans2 <<" "<<ans3 <<" "<<ans4<<"\n";
            ans = max(ans1, ans);
            ans = max(ans2, ans);
            ans = max(ans3, ans);
            ans = max(ans4, ans);
        }
    }
    cout << K- ans;

    return 0;
} // Brute-Force, 커버하는 점들 중에서 제일 모난 부분 한 군데를 기준을 커버하는 영역의 꼭짓점으로 잡을 수가 있다.
// Time Complexity : O(K^3)