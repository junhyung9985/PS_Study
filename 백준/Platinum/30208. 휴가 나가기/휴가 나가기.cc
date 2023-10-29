#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, W;
    cin >> N >> W;
    
    vector<pair<ll,ll>> v(N+1);
    vector<pair<ll,ll>> s_v(N+1);
    vector<vector<ll>> dp (2, vector<ll>(100001, INT_MAX));
    vector<ll> A(N+1);
    vector<ll> ind(N+1);
    vector<ll> ch(N+1);
    for(int i =1; i<=N; ++i)
        cin >> v[i].first;

    for(int i =1; i<=N; ++i)
        cin >> v[i].second;
    
    for(int i =1; i<=N; ++i){
        ll c;
        cin >> c;
        if(c == 0) continue;
        ch[c] = i;
        ++ind[i];
    }
    dp[0][0] = 0;
    dp[1][0] = 0;
    vector<ll> s_vidx(N+1);

    int curr_count = 1;
    deque<pair<ll,ll>> q;
    
    int new_c;
    for(int i =1; i<=N; ++i){
        if(ind[i] == 0){            
            q.push_back({i,curr_count});
            while(!q.empty()){
                
                ll a, curr;
                tie(a, curr) = q.front();
                q.pop_front();
                s_vidx[curr_count] = a;
                A[curr_count++] = curr;
                ll cha = ch[a];
                if(cha == 0) continue;
                
                v[cha].first += v[a].first;
                v[cha].second += v[a].second;
                q.push_back({cha, curr});

            }
        }
    }

    for(int i =1; i<=N; ++i){
        s_v[i] = v[s_vidx[i]];
    }
    
    int bef = A[1];
    for(int i = 1; i<=N; ++i){
        ll weight, t;
        tie(weight, t) = s_v[i];
        if(A[i] != bef){
            for(int j=0; j<= 100000; ++j){
                dp[0][j] = dp[1][j];
            }
            bef = A[i];

        }
        dp[1][weight] = min(t, dp[1][weight]);
        for(int j = weight+1; j<=100000; ++ j){
            dp[1][j] = min(dp[1][j], dp[0][j-weight] + t);
        }
    }

    ll ans = INT_MAX;
    ll ans_cand = INT_MAX;
    for(int i = 100000; i>=W; --i){
        ans = min(dp[1][i], ans);
    }

    if(ans == INT_MAX){
        ans = -1;
    }

    cout << ans;

    
    return 0;
}
/*

최대 1개의 각자 다른 선행업무 -> 선행 업무끼리는 skewed-tree 형태로 구성이 됨.

그렇다면, topological sort를 돌리고 knapsack dp를 쓰면 쉽게 풀릴듯?

https://stackoverflow.com/questions/31497021/knapsack-with-requirement-to-select-one-item-each-from-many-sets
-> 이런 식으로!

*/