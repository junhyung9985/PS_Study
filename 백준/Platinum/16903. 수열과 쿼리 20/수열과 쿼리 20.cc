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
    int cnt = 0;
    node(){
        childs[0] = nullptr;
        childs[1] = nullptr;
        cnt = 0;
    }
};

void add(node * tree, int idx){
    tree->cnt++;
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
    else if(tree->childs[1-x]->cnt <= 0){
        get(tree->childs[x], idx+1);
    }
    else{
        val+=(1LL<<(long long)(39-idx));
        get(tree->childs[1-x], idx+1);
    }
}

void erase_t(node* tree, int idx){
    if(idx > 0) tree->cnt--;
    if(idx == 40) return;
    ll x = bi[idx];
    erase_t(tree->childs[x], idx+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll Q;
    cin >> Q;
    node * root = new node();
    add_n(0);
    add(root ,0);
    while(Q--){
        ll q, x;
        cin >> q >> x;
        add_n(x);
        if(q == 1){
            add(root, 0);
        }
        else if(q == 2){
            erase_t(root, 0);
        }
        else {
            val = 0;
            get(root, 0);
            cout << val <<"\n";
        }
    }

    return 0;
}
/*

Trie

*/