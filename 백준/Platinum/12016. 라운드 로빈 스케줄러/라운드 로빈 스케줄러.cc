
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> tree(400005,0);

ll update(ll node, ll s, ll e, ll idx){
    if(idx < s || idx > e) return tree[node];
    if(s == e) return tree[node] = -1;
    //cout << s <<" "<<e <<" "<<idx<<"\n";
    ll mid = (s+e)/2;
    return tree[node] = update(node*2, s,mid, idx) + update(node*2+1, mid+1, e, idx);
}

ll sum(ll node, ll s, ll e, ll begin, ll to){
    if(to < s || e < begin) return 0;
    if( begin <= s && e <= to) return tree[node];
    ll mid = (s+e)/2;
    return sum(node*2,s,mid,begin,to) + sum(node*2+1,mid+1, e, begin, to);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, N_T;
    ll T = 0, last_t = 1, last_idx = -1;
    vector<ll> act;
    set<pair<ll,ll>> s;

    cin >> N;
    N_T = N;
    act.resize(N);
    for(int i =0; i<N; i++){
        ll tmp;
        cin >> tmp;
        s.insert({tmp,i});
    }
    ll cnt = 0;
    for(int turn =0; turn<N_T; ++turn){
        ll a, b;
        auto itr = s.begin();
        tie(a,b) = *itr;
        
        int change = 0;
        if(last_t < a){
            if(b<last_idx && last_t == a-1) change = 1;
            else if(b<last_idx) change = 2;
            else{
              N -=cnt;
              cnt = 0;
            } 
        }
        
        s.erase(itr);
        
        if(last_idx == -1) T+= (a-last_t)*N + b -last_idx;
        else if(b < last_idx){
            T += N_T + b-last_idx+sum(1,0,N_T-1,last_idx+1,N_T-1)+sum(1,0,N_T-1,0,b);
            
            if(change == 2){
                N-=cnt;
                cnt = 0;
                T+= (a-last_t-1)*N;
            }
            if(change == 1){
                N -= cnt;
                cnt = 0;
            }
        }
        else{
            T += (a-last_t)*(N)+b-last_idx+sum(1,0,N_T-1,last_idx+1,b);
        }
        //cout <<N<<" "<< a <<" "<<last_idx<<" "<<b<<" "<<T <<"\n";
        cnt ++;
        act[b] = T;
        last_idx = b;
        last_t = a;
        update(1,0,N_T-1,b);
        // cout << b <<" : ";
        // for(int i =0; i<N_T; i++)
        //     cout << sum(1,0,N_T-1,0,i)<<" ";
        // cout<<"\n";
    
        // for(int i =0; i<N_T; i++)
        //     cout << arr[i] <<" ";
        // cout<<"\n";
    }
    
    
    for(int i =0; i<N_T; i++)
        cout << act[i]<<"\n";
    
    return 0;
}
/*

a,i -> b,j

T += (b-a)*N+j-i;

5   0...4
4,3 5,1
1 1 1
1*N + 1-3 = N-2 = 3

4,3 5,3
1 1 1 1 1 
1*5 =

5+1-3 = 6-3 = 3 

SegTree + PQ or Set? (Lazy Seg 쓴다면 더 쉬울듯?)

*/