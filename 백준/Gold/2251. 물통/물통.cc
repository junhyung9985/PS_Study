#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

vector<vector<vector<ll>>> v(201, vector<vector<ll>>(201, vector<ll>(201)));
ll A, B, C;
    
void dfs(ll a, ll b ,ll c){
    v[a][b][c] = 1;
    if(B >= b+a){
        if(v[0][b+a][c] == 0) dfs(0,b+a, c);
    }
    else{
        if(v[a+b-B][B][c] == 0) dfs(a+b-B, B, c);
    }

    if(B >= b+c){
        if(v[a][b+c][0] == 0) dfs(a, b+c, 0);
    }
    else {
        if(v[a][B][b+c-B] == 0) dfs(a, B, b+c-B);
    }

    if(C >= c+a){
        if(v[0][b][c+a] == 0) dfs(0, b, c+a);
    }
    else {
        if(v[c+a-C][b][C] == 0) dfs(c+a-C, b, C);
    }

    if(C >= c+b){
        if(v[a][0][c+b] == 0) dfs(a, 0, c+b);
    }
    else {
        if(v[a][b+c-C][C] == 0) dfs(a, b+c-C, C);
    }

    if(A >= a+b){
        if(v[a+b][0][c] == 0) dfs(a+b, 0, c);
    }
    else {
        if(v[A][a+b-A][c] == 0) dfs(A, a+b-A, c);
    }
    if(A >= a+c){
        if(v[a+c][b][0] == 0) dfs(a+c, b, 0);
    }
    else {
        if(v[A][b][c+a-A] == 0) dfs(A, b, c+a-A);
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B >> C;

    dfs(0,0,C);

    for(int i =0; i<=C; ++i){
        if(v[0][C-i][i] ==  1){
            cout << i<<" ";
        }
    }

    return 0;
} // Backtracking, DP(Memoization?)