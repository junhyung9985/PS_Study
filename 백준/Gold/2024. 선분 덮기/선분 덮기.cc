#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll tr[400004];
ll arr[100001];

ll init(ll N, ll S, ll E){
    if(S == E) return tr[N] = arr[S];
    return tr[N] = max(init(2*N, S, (S+E)/2), init(2*N+1, (S+E)/2+1, E));
}

ll query(ll N, ll S, ll E, ll idx){
    if(idx < S) return 0;
    if(idx >= E) return tr[N];
    return max(query(2*N, S, (S+E)/2, idx), query(2*N+1, (S+E)/2+1, E, idx));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll M;
    while(cin >> M){
        while(1){
            ll l, r;
            cin >> l >> r;
            if(l == 0 && r == 0) break;
            arr[l+50000] = max(arr[l+50000], r+50000);
            //cout << l+50000 <<" "<<arr[l+50000]<<"\n";
        }
        init(1,0,100000);
        ll start = 50000, end = 50000+M;
        ll cnt = 0;
        bool can = true;
        while(can){
            ++cnt;
            ll until = query(1,0,100000, start);
            //cout << start <<" : "<<until<<"\n";
            if(until > start){
                start = until;
            }
            else can = false;
            if(until >= end) break;
        }
        //cout << start <<" "<<can <<" " << end<<"\n";
        if(can) cout << cnt<<"\n";
        else cout << 0<<"\n";
    }
    
    return 0;
} // Segment Tree