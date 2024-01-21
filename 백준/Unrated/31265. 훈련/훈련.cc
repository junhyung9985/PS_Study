#include<bits/stdc++.h>
#define ll long long
using namespace std;
// Default

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
// PBDS

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, M;
    cin >> N >> M;

    vector<ll> cnt(N);
    vector<vector<ll>>items(N);

    for(int i =0 ;i<N; ++i){
        cin >> cnt[i];
        items[i].resize(cnt[i]);
    }

    ll ans1 = 0;
    for(int i =0; i<N; ++i){
        for(int j =0; j<cnt[i]; ++j){
            cin >> items[i][j];
            ans1 += items[i][j];
        }
    }

    vector<ll> bef(M+1,0);
    ll last = 0;
    vector<ll> last_idx(M+1, -1);
    vector<vector<ll>> dp(2, vector<ll>(M+1));

    for(int l =0; l<N; ++l){

        for(int i =0; i<cnt[l]; ++i){
            for(int j =0; j<M+1; ++j)
                dp[last%2][j] = dp[1-last%2][j];

            
            for(int j =M; j>items[l][i]; --j){
                if(dp[1-last%2][j-items[l][i]] && last_idx[j-items[l][i]] >= l-1){
                    dp[last%2][j] = 1;
                    last_idx[j] = l;
                }
                //cout << dp[last%2][j]<<" "<<last_idx[j]<<"\n";
            }
            if(l == 0 && items[l][i]<=M){
                dp[last%2][items[l][i]] = 1;
                last_idx[items[l][i]] = l;
            }
            ++last;
        }

        for(int i =0; i<=M; ++i){
            bef[i] = dp[1-last%2][i];
            //cout << bef[i]<<" ";
        }

       //cout<<"\n";
    }
    ll ans = -1;
    for(int j = M; j>-1; --j){
        //cout << bef[j]<<" ";
        if(bef[j] && last_idx[j] == N-1){
            ans = j;
            break;
        }        
    }
    //cout<<"\n";
    cout << ans;
    // Subtask 2 

    return 0;
} // Knapsack