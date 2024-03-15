#include <bits/stdc++.h>
#define ll long long

using namespace std;

class SCC{
    public : 
        ll N;
        vector<vector<ll>> sccs;
        vector<ll> depth;
        vector<ll> top;
        vector<vector<ll>> e;
        vector<ll> curr;
        vector<bool> finished;
        ll cnt = 0;

        void scc_dfs(ll n){
            
            this->curr.push_back(n);
            this->depth[n] = this->cnt++;
            this->top[n] = this->depth[n];
            
            for(auto itr : this->e[n]){
                if(this->depth[itr] == -1){
                    this->depth[itr] = this->depth[n]+1;
                    scc_dfs(itr);
                }
                if(!finished[itr]) 
                    this->top[n] = min(this->top[n], this->top[itr]);
            }
            
            if(this->top[n] == this->depth[n]){
                vector<ll> scc;
                while(!this->curr.empty()){
                    this->finished[curr.back()] = true;
                    scc.push_back(this->curr.back());
                    this->curr.pop_back();
                    if(scc.back() == n) break;
                }
                
                this->sccs.push_back(scc);
            }
            return;
        }

        SCC(ll N, vector<vector<ll>> G){
            this->N = N;
            this->cnt = 0;
            this->depth.resize(N+1, -1);
            this->top.resize(N+1, -1);
            this->e.resize(N+1, vector<ll>());
            this->finished.resize(N+1, false);
            for(int i = 0; i<=N; ++i)
                for(auto itr : G[i])
                    this->e[i].push_back(itr);
        }

        void clear(){
            this->N = 0;
            this->cnt = 0;
            this->depth.clear();
            this->top.clear();
            this->sccs.clear();
            this->e.clear();
        }

        vector<vector<ll>> run_scc(){
            for(int i =1; i<=this->N; ++i){
                if(this->depth[i] == -1){
                    scc_dfs(i);
                }
            }
            return sccs;
        }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N  >> M;
    vector<vector<ll>> E(N+1);
    for(int i =0; i<M; ++i){
        ll a, b;
        cin >> a>> b;
        E[a].push_back(b);
    }
    
    SCC scc (N, E);
    vector<vector<ll>> sccs = scc.run_scc();
    
    for(int i =0 ;i<sccs.size(); ++i)
        sort(sccs[i].begin(), sccs[i].end());
        
    sort(sccs.begin(), sccs.end());
    
    cout << sccs.size()<<"\n";
    for(auto itr : sccs){
        for(auto itr2 : itr) cout << itr2 <<" ";
        cout<<-1<<"\n";
    }
    return 0;
}