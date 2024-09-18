//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
// Compiler Optimization Options

#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension
// Rope


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string ans = "";
    deque<ll> q;
    
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i =0 ; i<N; ++i)
        cin >> a[i];
    
    ll idx = 0;
    ll curr = 0;
    while(idx < N){
        if(curr == N+1) break;
        if(q.empty()){
            ans += "+";
            q.push_back(++curr);
        }
        if(a[idx] == q.back()){
            q.pop_back();
            ans+="-";
            ++idx;
        }
        else if(a[idx] > curr){
            ans += "+";
            q.push_back(++curr);
        }
        else{
            cout <<"NO";
            return 0;
        }
    }
    
    while(idx < N){
        ll n = q.back();
        q.pop_back();
        if(n != a[idx++]){
            cout << "NO";
            return 0;
        }
        ans += "-";
    }
    
    for(auto itr : ans) cout << itr <<"\n";
    
} // String, Ad_hoc(?)
/*

1 -> 1 
01110 -> 5
0011101011100 -> 13 
총 층의 수 2*(L-1)+3 
패티 수 2*(L-1)+1



*/