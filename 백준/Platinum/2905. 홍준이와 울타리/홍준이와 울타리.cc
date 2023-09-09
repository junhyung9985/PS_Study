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

    ll N , X;
    cin >> N >> X;
    vector<ll> v(N+1);
    deque<pair<ll,ll>> q;
    vector<bool> did(N, false);

    ll area = 0, cnt = 0;
    for(int i =0; i<N; i++){
        cin >> v[i];
        area += v[i];
    }
    v[N] = 0;
    int bef_idx = 0; 
    ll bef = 0;

    for(int i =0; i<=N; i++){

        
        while(!q.empty()){
            if(q.back().first > v[i]) q.pop_back();
            else break;
        }

        q.push_back({v[i], i});
        if(i > X-1){
            if(bef != q.front().first){
                area  -= bef*(i-bef_idx);
                cnt += (i-bef_idx-1)/X+1;
                bef = q.front().first;
                bef_idx = i;
            }
        }
        else bef = q.front().first;
        
        while(!q.empty()){
            if(q.front().second <= i-X) {
                ll idx_2 = q.front().second;
                q.pop_front();

                if(bef != q.front().first){
                    area  -= bef*(idx_2-bef_idx+1);
                    cnt += (idx_2-bef_idx)/X+1;
                    bef = q.front().first;
                    bef_idx = idx_2+1;
                }
            }
            else break; 
        }


    }  
    
    
    cout << area <<"\n" << cnt;    

    return 0;
}
/*
1+2+1 = 4 
1...X

2...X+1
3...X+2


N-X+1 ... N


필수 : 1...X, N-X+1 ... N

-> 겹치면 stop

9
8 -> 1 remains


-> Monotone Queue를 활용하는걸 알았는데 이후에 어떻게 풀어나갈지가 문제였다.
-> 이걸 그냥 prefix_sum을 활용해서 빼는걸 아래 사이트 통해서 알았다.
    -> https://jaimemin.tistory.com/832



*/