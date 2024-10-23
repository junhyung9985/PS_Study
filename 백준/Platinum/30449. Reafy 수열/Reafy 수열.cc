#include <bits/stdc++.h>
#define ll int

using namespace std;

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    return a.first * b.second <= b.first * a.second; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    
    
    vector<pair<ll,ll>> ans;
    vector<vector<bool>> able(n+1, vector<bool>(n+1, true));
    ans.push_back({0,1});
    ans.push_back({1,1});
    for(int i =2; i<=n; ++i){
        for(int j =1; j<=i/2; ++j){
            if(able[i][j]){
                ans.push_back({j,i});
                if(j*2 != i) ans.push_back({i-j, i});
                ll n_i = i*2, n_j = j*2;
                while(n_i <=n && n_j <= n/2){
                    able[n_i][n_j] = false;
                    n_j += j;
                    n_i += i;
                }
            }
        }
    } 
    
    nth_element(ans.begin(), ans.begin()+k-1, ans.end(), cmp);
    cout << ans[k-1].first <<" "<<ans[k-1].second;
    

    return 0;
}