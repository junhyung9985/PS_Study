/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> arr;
vector<ll> tree;


void update(int node, int start, int end, int idx, int val){
    if(idx < start || end < idx ) return;
    if(start == end){
        tree[node] += val;
        return;
    }
    if(start <= idx && idx <= end){
        tree[node] += val;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, idx, val);    
    update(node*2+1, mid+1, end, idx, val);
    return;
}
 

ll query(int node, int start, int end, int left, int right){
    if(end < left || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/2;
    return query(node*2, start,mid,left,right) + query(node*2+1, mid+1, end,left,right);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    cin >> N;
    arr.resize(N+2);
    tree.resize(4*N+4);
    for(int i =0; i<N; i++)
        cin >> arr[i];
        
    cin >> M;
    while(M--){
        ll which, a, b;
        cin >> which >> a;
        if(which == 2){
            cout << arr[a-1]+query(1,0,N-1,0,a-1) <<"\n";
        }
        else{
            ll k;
            cin >> b >> k;
            update(1,0,N-1, a-1,k);
            update(1,0,N-1, b,-k);
        }
    }
    
    return 0;
}
/*

SegTree + Difference Array

*/