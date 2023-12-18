#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M, T, P;
    cin >> N >> M >> T;
    vector<ll> v(N);
    for(int i =0; i<N; ++i){
        cin >> v[i];
    }
    cin >> P;
    
    --P;
    M -= v[P];
    if(M < 0) {
        cout <<"NO";
        return 0;
    }
    
    ll minn = INT_MAX;
    for(int i =0; i<=P; ++i){
        for(int j =P; j<N; ++j){
            
            ll minn = min(P-i, j-P);
            if(minn + j-i > T) continue;
            
            unordered_set<ll> s = {0};
            vector<bool> found(100001, false);
            for(int k= i; k<=j; ++k){
                if(k == P) continue;
                deque<ll> q;
                for(auto itr : s){
                    if(!found[itr+v[k]]){
                        found[itr+v[k]] = true;
                        q.push_back(itr+v[k]);
                    }
                }
                for(auto itr : q){
                    s.insert(itr);
                }
            }
            if(s.find(M) != s.end()){
                cout <<"YES";
                return 0;
            }
        }
    } 
    cout <<"NO";
    return 0;
} // DP