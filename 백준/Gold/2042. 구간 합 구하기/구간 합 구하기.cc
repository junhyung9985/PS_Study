#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, M, K;
ll arr[1000001];
ll tree[4000001];

ll init(ll node, ll start, ll end){
    if(start == end) return tree[node] = arr[start];
    ll mid = (start + end)/2;
    return tree[node] = init(node*2, start , mid) + init(node*2+1, mid+1, end);
}

ll query(ll node, ll start , ll end , ll left, ll right){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    ll mid = (start+end)/2;
    return query(node*2, start, mid, left, right)+ query(node*2+1, mid+1, end, left, right);
}

void update(ll node, ll start, ll end, ll idx, ll diff){
    if(end < idx || idx < start) return;
    if(start == end) {
        tree[node] += diff;
        return;
    }
    if(start <= idx && idx <= end){
        tree[node] += diff;
    }
    ll mid = (start+end)/2;
    update(node*2, start, mid, idx, diff);
    update(node*2+1, mid+1, end, idx, diff);
    return;
    
}

int main()
{
    cin >> N >> M >> K;
    for(int i =0; i<N; i++){
        cin >> arr[i];
    }
    init(1,0,N-1);

    for(int i=0; i<M+K; i++){
        ll a, b, c;
        cin >> a>>b>>c;
        if(a == 1){
            update(1,0,N-1, b-1, c-arr[b-1]);
            arr[b-1] = c;
        }
        if(a==2){
            cout << query(1,0,N-1,b-1,c-1)<<"\n";
        }
    }
    
    
    return 0;
}

// Segment Tree를 활용한 제일 기본 문제
// update는 내가 대략 이렇게 업데이트 될 것이다고 짐작하여 구현해서 정확하지 않을 수 있음