#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  
    ll N, M;
    cin >> N >> M;
  
    vector<vector<ll>> v(26);
    vector<ll> ind(26);
    vector<bool> has_appeared(26, false);
    vector<bool> arrested(26, false);
    vector<bool> can(26, false);
  
    while(M--){
        char a, b;
        cin >> a >> b;
        v[a-'A'].push_back(b-'A');
        ++ind[b-'A'];
        has_appeared[a-'A'] = has_appeared[b-'A'] = true;
    }
  
    ll K;
    cin >> K;
    while(K--){
        char ch;
        cin >> ch;
        arrested[ch-'A'] = true;
    }
  
    deque<ll> q;
    for(int i =0; i<26; ++i){
        if(ind[i] == 0 && !arrested[i]) {
            q.push_back(i);
            //can[i] = true;  
        }
    }
    
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        //cout << n <<" ";
        for(ll next : v[n]){
            if(!can[next] && !arrested[next]){
                can[next] = true;
                q.push_back(next);
            }
        }
    }
    
    ll ans = 0;
    for(int i =0; i<26; ++i)
        if(can[i] && has_appeared[i]) ++ans;
  
    cout << ans;
    
    return 0;
} // BFS, Topological Sort(?)