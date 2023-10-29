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
    int cnt;
    node(){
        childs[0] = nullptr;
        childs[1] = nullptr;
        cnt = 0;
    }
};

void add(node * tree, int idx){
    if(idx > 0) tree->cnt++;
    if(idx == 26) return;
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
    while(bi.size() < 26)
        bi.push_front(0);
}

void get(node* tree, int idx){
    if(idx == 26) return;
    int x = bi[idx];
    if(!tree->childs[1-x]){
        get(tree->childs[x], idx+1);
    }
    else if(tree->childs[1-x]->cnt <=0){
        get(tree->childs[x], idx+1);
    }
    else{
        val+=(1LL<<(long long)(25-idx));
        get(tree->childs[1-x], idx+1);
    }
}

void get2(node* tree, int idx){
    if(idx == 26) return;
    int x = bi[idx];
    if(!tree->childs[x]){
        val+=(1LL<<(long long)(25-idx));
        get2(tree->childs[1-x], idx+1);
    }
    else if(tree->childs[x]->cnt<=0){
        val+=(1LL<<(long long)(25-idx));
        get2(tree->childs[1-x], idx+1);
    }
    else{
        get2(tree->childs[x], idx+1);
    }
}

void erase_t(node* tree, int idx){
    if(idx > 0) tree->cnt--;
    if(idx == 26) return;
    ll x = bi[idx];
    erase_t(tree->childs[x], idx+1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--){
        ll N, Q;
        cin >> N >> Q;
        node * root = new node();
        set<ll> s;
        for(int i =0; i<N; ++i){
            ll n;
            cin >> n;
            if(s.find(n) == s.end()){
                add_n(n);
                add(root ,0);
                s.insert(n);
            }
        }
        while(Q--){
            ll q, x;
            cin >> q;
            if(q == 1){
                cin >> x;
                val = 0;
                add_n(x);
                get2(root, 0);
                cout << val<<"\n";
            }
            if(q == 2){
                cin >> x;
                val = 0;
                add_n(x);
                get(root, 0);
                cout << val<<"\n";
            }
            if(q == 3){
                cin >> x;
                if(s.find(x) == s.end()){
                    add_n(x);
                    add(root, 0);
                    s.insert(x);
                }
                cout << s.size()<<"\n";
            }
            if(q == 4){
                val = *(s.begin());
                cout << val<<"\n";
                add_n(val);
                erase_t(root, 0);
                s.erase(val);
            }
            if(q == 5){
                val = *(s.rbegin());
                cout << val<<"\n";
                add_n(val);
                erase_t(root, 0);
                s.erase(val);
            }
        }
    }
    return 0;
}
/*

Trie, Tree_Set

*/