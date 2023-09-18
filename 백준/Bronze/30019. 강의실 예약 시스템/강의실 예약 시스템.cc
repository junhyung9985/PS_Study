#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    cin >> N >> M;
    
    vector <ll> E (N+1);
    for(int i= 0; i<M; ++i){
        ll k, s, e;
        cin >> k >> s >> e;
        if(E[k] > s){
            cout <<"NO\n";
        }
        else {
            E[k] = e;
            cout <<"YES\n";
        }
    }
    
    
    return 0;
}