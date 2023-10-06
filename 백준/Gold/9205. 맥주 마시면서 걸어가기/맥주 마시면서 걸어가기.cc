#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p[101];

ll f(ll n){
    if(p[n] == n) return n;
    return p[n] = f(p[n]);
}

void u(ll a ,ll b){
    ll pa = f(a), pb = f(b);
    p[pb] = pa;
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        n+=2;
        vector<pair<double, double>> con(n);
        for(int i =0; i<n; ++i){
            p[i] = i;
            cin >> con[i].first >> con[i].second;
        }
        
        for(int i =0; i<n; ++i){
            for(int j=0; j<n; ++j){
                ll dist = abs(con[i].first-con[j].first) + abs(con[i].second - con[j].second);
                if(dist <= 50*20){
                    u(i,j);
                }
            }
        }
        if(f(0) == f(n-1)) cout <<"happy\n";
        else cout <<"sad\n";
    }
    return 0;
} // DSU, Graph