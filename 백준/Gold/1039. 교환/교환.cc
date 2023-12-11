#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string N;
    ll K;
    
    cin >> N >> K;
    
    deque<pair<string,ll>> q;
    vector<unordered_set<string>> lvl(K+1);
    
    ll ans = 0;
    ll maximum = 0;
    q.push_back({N, 0});
    while(!q.empty()){
        string n; ll k;
        tie(n, k) = q.front();
        q.pop_front();
        maximum = k;
        if(k == K){
            ll tmp = 0;
            for(char ch : n){
                tmp = tmp * 10 + ch - '0';
            }
            ans = max(ans, tmp);
            continue;
        }
        for(int i = 0; i<n.size(); ++i){
            for(int j = i+1; j<n.size(); ++j){
                if(i == 0 && n[j] == '0') continue;
                swap(n[i],n[j]);
                if(lvl[k+1].find(n) == lvl[k+1].end()){
                    q.push_back({n,k+1});
                    lvl[k+1].insert(n);
                }
                swap(n[i],n[j]);
            }
        }
    }
    if(maximum < K) ans = -1;
    cout << ans;
    
    return 0;
} // BFS
// 범위가 생각보다 작아서 가능한듯...?