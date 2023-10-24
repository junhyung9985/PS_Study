#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

struct Node{
    bool end;
    map<int, Node *> low;
    Node (){
        end = false;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, M;
    cin >> N >> M;

    Node * head1 = new Node();
    Node * head2 = new Node();

    for(int i =0; i<N; ++i){
        string s;
        cin >> s;
        Node * curr = head1;
        for(int j =0; j<s.size(); ++j){
            int idx = s[j]-'a';
            if(curr->low.find(idx) == curr->low.end()) curr->low[idx] = new Node();
            curr = curr->low[idx];
        }
        curr->end = true;        
    }
    for(int i =0; i<M; ++i){
        string s;
        cin >> s;
        Node * curr = head2;
        for(int j =s.size()-1; j>-1; --j){
            int idx = s[j]-'a';
            if(curr->low.find(idx) == curr->low.end()) curr->low[idx] = new Node();
            curr = curr->low[idx];
        }
        curr->end = true;        
    }

    ll Q;
    cin >> Q;
    for(int i =0; i<Q; ++i){
        string q;
        cin >> q;

        bool flag = false;
        Node * curr = head1;
        int j = 0;
        int sz = q.size();
        vector<ll> v;
        while(true){
            if(curr->end){
                v.push_back(j);
            }
            if(j == sz) break;
            int idx = q[j] - 'a';
            if(curr->low.find(idx) == curr->low.end()) break;
            curr = curr->low[idx];
            ++j;
        }

        curr = head2;
        j = sz-1;
        while(true){
            if(curr->end){
                auto itr = lower_bound(v.begin(), v.end(), j+1);
                if(itr == v.end());
                else if(*itr == j+1){
                    flag = true;
                    break;
                }
            }
            if(j == -1) break;

            int idx = q[j] - 'a';
            if(curr->low.find(idx) == curr->low.end()) break;
            curr = curr->low[idx];
            --j;
        }
        //  for(int i : v){
        //      cout << i<<" ";
        // }
        
        if(flag) cout <<"Yes\n";
        else cout <<"No\n";
    }
    
    return 0;
} // Trie
// O((Q+N+M)|S|)