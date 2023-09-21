#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, K;
    cin >> N >> K;
    
    vector<vector<ll>> E(N+1);
    vector<set<ll>> E2(N+1);
    vector<ll> ind(N+1);
    
    for(int i =0; i<K;++i){
        ll a, b;
        cin >> a >> b;
        E[a].push_back(b);    
        ++ind[b];
        E2[b].insert(a);
    }
    
    deque<ll> q;
    for(int i =1; i<=N; ++i){
        if(ind[i] == 0){
            q.push_back(i);
        }
    }
    while(!q.empty()){
        ll n = q.front();
        q.pop_front();
        for(int i : E[n]){
            for(auto itr : E2[n]){
                E2[i].insert(itr);
            }
            E2[i].insert(n);
            --ind[i];
            if(ind[i] == 0) q.push_back(i);
        }
    }
    
    ll Q;
    cin >> Q;
    while(Q--){
        ll a, b;
        cin >> a >> b;
        if(E2[b].find(a) != E2[b].end())cout <<-1<<"\n";
        else if (E2[a].find(b) != E2[a].end()) cout << 1 <<"\n";
        else cout << 0<<"\n";
    }
    
    return 0;
} // Topological sort + set