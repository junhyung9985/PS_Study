#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

deque<ll> dc;
ll val = 0;
ll N, M;

struct node{
    node *childs[10];
    node(){
        for(int i =0 ;i<10; ++i){
            childs[i] = nullptr;
        }
    }
};

void add(node * tree, int idx){
    if(idx == N) return;
    ll x = dc[idx];
    if(!tree -> childs[x])
        tree->childs[x] = new node();
    add(tree->childs[x], idx+1);
}

void add_n(ll n){
    dc.clear();
    while(n > 0){
        dc.push_front(n%10);
        n/=10;
    }
    while(dc.size() < N)
        dc.push_front(0);
}

void get(node* tree, int idx){
    if(idx == N) return;
    int x = dc[idx];
    int seek = 9-x;
    for(int i =0; i<10; ++i){
        if(tree->childs[seek]){
            val= val*10 + (seek+x)%10;
            get(tree->childs[seek], idx+1);
            return;
        }
        seek = (seek+9)%10;                
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    vector<ll> a(M);
    vector<ll> b(M);
    node * root = new node();
    node * root2 = new node();
    for(int i =0; i<M; ++i){
        cin >> a[i];
    }

    for(int i =0; i<M; ++i){
        cin >> b[i];
    }
    add_n(a[0]);
    add(root, 0);
    add_n(b[0]);
    add(root2, 0);

    ll maxx1 = 0, maxx2 = 0;

    for(int i =1; i<M; ++i){
        val = 0;
        add_n(a[i]);
        get(root2, 0);
        maxx1 = max(maxx1, val);
        add(root, 0);

        val = 0;
        add_n(b[i]);
        get(root, 0);
        maxx2 = max(maxx2, val);
        add(root2, 0);
        //cout << maxx1 <<" "<<maxx2<<"\n";
    }

    if(maxx1 > maxx2) {
        cout << "J";
    }
    else if (maxx1 < maxx2){
        cout <<"S";
    }
    else cout <<"D";

    return 0;
}
/*

Trie Solution

*/