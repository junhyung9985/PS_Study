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
    int cnt = 0;
    bool end = false;
    map<int, Node *> low;
    Node (){
        cnt = 0;
        end = false;
    }
};


void print_trie(Node * ptr, int times){
    for(auto itr : ptr->low){
        for(int i =0; i<times; ++i) cout << "- ";
        cout << (char)(itr.first+'a');
        cout<<"\n";
        print_trie(itr.second, times+1);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    
    cout.precision(2);
    cout <<fixed;
    while (cin >> N){

        Node * head1 = new Node();
        vector<string> v(N);
        for(int i =0; i<N; ++i){
            string s ;
            cin >> s;
            v[i] = s;
            Node * curr = head1;
            for(int j =0; j<s.size(); ++j){
                int idx = s[j] -'a';
                if(curr->low.find(idx) == curr->low.end()) {
                    curr->cnt++;
                    curr->low[idx] = new Node();
                }
                curr = curr->low[idx];
            }
            curr->cnt++;
            curr->end = true;
                
        }

        // print_trie(head1,0);

        
        ll cnt = 0;
        for(string s: v){
            Node * curr = head1;
            ++cnt;
            for(int i = 0; i<s.size()-1; ++i){
                curr = curr->low[s[i]-'a'];
                if(curr->cnt > 1) {
                    // cout << s[i]<<" ";
                    // for(auto itr2 : curr->low){
                    //     cout << (char)(itr2.first+'a')<<" ";
                    // }
                    
                    // cout<< curr->end<<", ";
                    ++cnt;
                }
            }
            //cout << cnt<<"\n";
        }
        double ans = cnt * 100.0;
        ans /= (N*1.0);
        ans = round(ans)/100.0;
        cout << ans <<"\n";
        
    }
    
    return 0;
} // Trie