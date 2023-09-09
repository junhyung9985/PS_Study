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
    if(idx == 32) return;
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
    while(bi.size() < 32)
        bi.push_front(0);
}

void get(node* tree, int idx){
    if(idx == 32) return;
    int x = bi[idx];
    if(!tree->childs[1-x]){
        get(tree->childs[x], idx+1);
    }
    else{
        val+=(1LL<<(long long)(31-idx));
        get(tree->childs[1-x], idx+1);
    }
}




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        node * root = new node();
        cin >> n;
        vector<ll> v(n);
        vector<ll> s(n);    
        vector<ll> rev(n);
        ll maxx = INT_MIN;
        for(int i =0; i<n; i++){
            cin >> v[i];
            s[i] = v[i];
            if(i > 0) s[i] ^= s[i-1];
            add_n(s[i]);
            val = 0;
            add(root, 0);
            get(root , 0);
            maxx = max(maxx, s[i]);
            maxx = max(maxx, val);
            
        }
        
        cout << maxx<<"\n";
    }
    return 0;
}
/*

= CF 882 C번 - 트라이 풀이


*/