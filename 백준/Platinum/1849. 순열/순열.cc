#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll tr[400001];

ll init(ll N, ll S, ll E){
    if(S == E) return tr[N] = 1;
    ll mid = (S+E)/2;
    return tr[N] = init(2*N, S, mid)+init(2*N+1, mid+1, E);
}

ll update(ll N, ll S, ll E, ll idx){
    if(idx < S || E < idx) return tr[N];
    if(S == E) return tr[N] = 0;
    ll mid = (S+E)/2;
    return tr[N] = update(N*2, S, mid, idx) + update(N*2+1,mid+1,E,idx);
}

ll query(ll N, ll S, ll E, ll val, ll s){
    if(S == E) return S;
    if(s+tr[2*N] < val) return query(2*N+1, (S+E)/2+1, E, val, s+tr[2*N]);
    else return query(2*N, S, (S+E)/2, val, s);
}


int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  ll N;
  cin >> N;
  vector<ll> v(N);
  init(1,0,N-1);
  for(int i =1; i<=N; ++i){
    ll a;
    cin >> a;
    ll idx = query(1,0,N-1, a+1, 0);
    v[idx] = i;
    update(1,0,N-1, idx);
  }
  
  for(int i =0; i<N; ++i){
      cout << v[i]<<"\n";
  }

  return 0;
} // Segment-Tree, Binary Search