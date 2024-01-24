#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll tr[32769][320];
ll v[100001];
ll curr = 0;

void update(ll idx, ll val){
    tr[idx+16384][curr] += val;   
    ll node = idx+16384;
    while(node >> 1 != 0){
        tr[node >> 1][curr] = tr[node][curr]+tr[node^1][curr];
        node >>= 1;
    }
    return;
}

ll query(ll k){
    ll left = k+16385;
    ll right = 26384;
    ll ret = 0;
    while(left <= right){
        if(left%2){
            ret += tr[left++][curr];
        }
        if(right%2 == 0){
            ret += tr[right--][curr];
        }
        left >>=1;
        right >>=1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, Q;
    cin >> N;

    for(int i =0; i<N; ++i){
        cin >> v[i];
        curr = i/512;
        update(v[i],1);
    }
    
    cin >> Q;
    while(Q--){
        ll q, i, j;
        cin >> q >> i >> j;
        if(q == 1){
            --i;
            curr = i/512;
            update(v[i],-1);
            v[i] = j;
            update(v[i],1);
        }
        else{
            ll k;
            cin >> k;
            ll ans = 0;
            --i; --j;
            for(int cnt =0; cnt<320; ++cnt){
                curr = cnt;
                if(i <= cnt*512 && cnt*512+511<=j) ans += query(k);
                else if(cnt*512 <= j && i <= cnt*512+511){
                    for(int l = cnt*512; l<=cnt*512+511; ++l)
                        if(i <= l && l <= j) if(v[l] > k) ++ ans;
                }
            }
            cout << ans <<"\n";
        }
    }

    return 0;
} // Sqrt Decomposition + Segment Tree
// O(Q(sqrt(N)log(10000))
