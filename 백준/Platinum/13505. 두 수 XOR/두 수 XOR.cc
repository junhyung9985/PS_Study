#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

deque<ll> bi;
ll val = 0;

struct node{
    node *childs[2];
    node(){
        childs[0] = nullptr;
        childs[1] = nullptr;
    }
};

void add(node * tree, int idx){
    if(idx == 40) return;
    ll x = bi[idx];
    if(!tree -> childs[x])
        tree->childs[x] = new node();
    add(tree->childs[x], idx+1);
}

void add_n(ll n){
    bi.clear();
    while(n > 0){
        bi.push_front(n%2);
        n/=2;
    }
    while(bi.size() < 40)
        bi.push_front(0);
}

void get(node* tree, int idx){
    if(idx == 40) return;
    int x = bi[idx];
    if(!tree->childs[1-x]){
        get(tree->childs[x], idx+1);
    }
    else{
        val+=(1LL<<(long long)(39-idx));
        get(tree->childs[1-x], idx+1);
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    vector<ll> v(N);
    node * root = new node();
    for(int i =0; i<N; i++){
        cin >> v[i];
        add_n(v[i]);
        add(root, 0);
    }
    ll l =0, r = 1e10;

    ll maxx = 0;
    for(int i =0; i<N; i++){
        val = 0;
        add_n(v[i]);
        get(root , 0);
        maxx = max(maxx , val);
    }

    cout << maxx;

    return 0;
}
/*

Trie

*/