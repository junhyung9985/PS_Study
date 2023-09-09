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
    vector<ll> dist1(500001, INT_MAX);
    vector<ll> dist2(500001, INT_MAX);
    ll N, K;
    cin >> N >> K;
    deque<pair<ll,ll>> q;
    q.push_back({N,0});
    dist2[N] = 0;
    while(!q.empty()){
        ll node, d;
        tie(node, d) = q.front();
        q.pop_front();
        if(d%2 == 0){
            if(node *2 <= 500000){
                if(dist1[node*2] > d+1){
                    dist1[node*2] = d+1;
                    q.push_back({node*2, d+1});
                }
            }
            if(node < 500000){
                if(dist1[node+1] > d+1){
                    dist1[node+1] = d+1;
                    q.push_back({node+1, d+1});
                }
            }
            if(node > 0){
                if(dist1[node-1] > d+1){
                    dist1[node-1] = d+1;
                    q.push_back({node-1, d+1});
                }
            }
        }
        else{
            if(node *2 <= 500000){
                if(dist2[node*2] > d+1){
                    dist2[node*2] = d+1;
                    q.push_back({node*2, d+1});
                }
            }
            if(node < 500000){
                if(dist2[node+1] > d+1){
                    dist2[node+1] = d+1;
                    q.push_back({node+1, d+1});
                }
            }
            if(node > 0){
                if(dist2[node-1] > d+1){
                    dist2[node-1] = d+1;
                    q.push_back({node-1, d+1});
                }
            }
        }
    }
    ll ans = -1;
    ll t = 0;
    while(K <= 500000){
        if(t%2){
            if(dist1[K] <= t){
                ans = t;
                break;
            }
        }
        else{
            if(dist2[K] <= t){
                ans = t;
                break;
            }
        }
        t++;
        K+=t;
        
    }

    cout << ans;
    return 0;
}
/*

BFS -> 2번 반복하면 다시 돌아오는게 가능하므로 시간이 홀수 일때, 짝수일때를 고려해서 BFS

*/