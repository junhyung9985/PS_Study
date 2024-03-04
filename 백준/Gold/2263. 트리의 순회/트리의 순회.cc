/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll in[100001];
ll post[100001];
ll pre[100001];
ll m[100001];
ll m2[100001];
ll tree[400004];
ll N;

int idx = 0;
// bool chck[100001];

ll init(int node, int left, int right){
    if(left == right) return tree[node] = in[left];
    int mid = (left+right)/2;
    ll tree_l = init(node*2, left ,mid);
    ll tree_r = init(node*2+1, mid+1, right);
    if(m2[tree_l] < m2[tree_r]) tree[node] = tree_r;
    else tree[node] = tree_l;
    return tree[node];
    
}

ll query(int node, int left, int right, int start ,int end){
    if(left > end || start > right) return 0;
    if(start <= left && right <= end) return tree[node];
    int mid = (left+ right)/2;
    ll tree_l = query(node*2, left ,mid, start, end);
    ll tree_r = query(node*2+1, mid+1, right, start, end);
    if(m2[tree_l] < m2[tree_r]) return tree_r;
    return tree_l;
}


void sol(int start, int end, int n){
    pre[idx++] = post[n];
    //cout << start << " " << end <<" " <<n << " "<<post[n]<<"\n";
    int where = m[post[n]];

    if(start < where){
        int idx = query(1, 0, N-1, start, where-1);
        sol(start, where-1, m2[idx]);
    }
    
    if(where+1 <= end){
        int idx = query(1,0,N-1, where+1, end);
        sol(where+1, end, m2[idx]);
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for(int i =0; i<N; i++){
        cin >> in[i];
        m[in[i]] = i;
    }
    
    for(int i =0; i<N; i++){
        cin >> post[i];
        m2[post[i]] = i;
    }
    
    init(1,0,N-1);
    sol(0,N-1,N-1);
    
    
    
    for(int i=0; i<N; i++){
        cout << pre[i] <<" ";
    }
    
    return 0;
}
/*
    5
  2.  6
 1 3 7. 4

1 2 3 5 7 6 4
1 3 2 7 4 6 5



i, N-1 
k, i-1

      
5 2 1 3 6 7 9

l node r
l r node

node l r 

*/

