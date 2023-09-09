#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll arr[1000001];
ll tree[4000005];

ll init(int node, int s, int e){
    if(s == e) return tree[node] = arr[s];
    int m = (s+e)/2;
    return tree[node] = init(node*2, s, m) + init(node*2+1, m+1, e);
}

ll query(int node, int s, int e, int r){
    if( r < s) return 0;
    if(e<=r) return tree[node];
    int mid = (s+e)/2;
    ll ret = 0;
    if(mid <= r) ret = tree[node*2] + query(node*2+1, mid+1, e, r);  
    else ret = query(node*2,s,mid,r);
    return ret;
    
}

void update(int node, int s, int e, int idx, ll diff){
    if(e < idx || idx < s) return;
    tree[node] += diff;
    if(s == e) return;
    int mid = (s+e)/2;
    update(node*2, s, mid, idx, diff);
    update(node*2+1, mid+1, e, idx, diff);
    return;
}


int main()
{
    ll n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        ll a, b, c;
        cin >> a ;
        if(a == 1) {
            cin >> b;
            ll l =0, r=1000001;
            while(l+1 < r){
                ll mid = (l+r)/2;
                ll ret = query(1,0,1000000,mid);
                //cout << l <<" "<<r << " "<<ret<<"\n";
                if( ret < b) l = mid;
                else r =mid;
            }
            cout << r<<"\n";
            update(1,0,1000000,r,-1);
            arr[r]--;
        }
        else {
            cin >> b >> c;
            update(1,0,1000000, b, c);
            arr[b] += c;
        }
    }
    
    
    return 0;
}
/*
사탕 맛을 array로 구간합을 계속 갱신
이후에 얼마나 잘했는지는 이분탐색을 통해서 찾기

결론 : Segtree + BS 
*/