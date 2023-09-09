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
vector<vector<ll>> tree;

vector<ll> init(int node, int start, int end){
    if(start == end){
    tree[node].push_back(arr[start]);
    return tree[node]; 
    } 
    int mid = (start+end)/2;
    vector<ll> tree_left = init(node*2, start, mid);
    vector<ll> tree_right = init(node*2+1, mid+1, end);
    vector<ll> new_one;
    int idx1 = 0, idx2= 0;
    while(idx1 < tree_left.size() && idx2 < tree_right.size()){
        if(tree_left[idx1] > tree_right[idx2]){
            new_one.push_back(tree_right[idx2]);
            idx2 ++;
        }
        else {
            new_one.push_back(tree_left[idx1]);
            idx1 ++;
        }
    }
    if(idx1 == tree_left.size()){
        while(tree_right.size() > idx2){
            new_one.push_back(tree_right[idx2++]);    
        }
    }
    else {
        while(tree_left.size() > idx1){
            new_one.push_back(tree_left[idx1++]);    
        }
    }
    tree[node] = new_one;
    return tree[node];
}

ll query(int node, int start , int end, int left, int right, ll K){
    if(right < start || end < left) return 0;
    if(left <= start && end <= right){
        int idx = upper_bound(tree[node].begin(), tree[node].end(), K) - tree[node].begin();
        return tree[node].size()-idx;
    }
    int mid = (start+end)/2;
    return query(node*2, start, mid, left, right, K)+query(node*2+1, mid+1, end, left, right, K);
}

/*

*/


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    cin >> N;
    arr.resize(N+1);
    tree.resize(4*N+1);
    
    for(int i =0; i<N; i++)
        cin >> arr[i];
    init(1,0,N-1);
    cin >> M;
    for(int i =0; i<M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        cout << query(1,0,N-1, a-1,b-1,c)<<"\n";
    }
    
    return 0;
}