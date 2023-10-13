#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll _N;
    string s;
    
    cin >> _N;
    cin >> s;
    
    vector<ll> v;
    vector<char> ops;

    for(auto ch : s){
        if(ch == '+' || ch == '-' || ch == '*') ops.push_back(ch);
        else v.push_back(ch-'0');
    }
    
    ll N = v.size();
    ll ans = INT_MIN;
    
    for(int i =0; i<pow(2,N-1); ++i){
        ll tmp = i;
        vector<pair<ll,ll>> comp;
        bool flag = true;
        bool bef = true;
        for(int j =0; j<N; ++j){
            if(tmp%2 == 0){
                comp.push_back({v[j],j});
                
            }
            else{
                if(ops[j] =='+') comp.push_back({v[j]+v[j+1],j+1});
                else if(ops[j] =='-') comp.push_back({v[j]-v[j+1],j+1});
                else comp.push_back({v[j]*v[j+1], j+1});
                tmp/=2;
                ++j;
            }
            tmp/=2;
        }
        if(!bef){
            comp.push_back({v[N-1],N-1});
        }
        if(!flag) continue;
        
        tmp = comp[0].first;
        for(int j =1; j<comp.size(); ++j){
            char bef = ops[comp[j-1].second];
            if(bef =='+'){
                tmp += comp[j].first;
            }
            if(bef =='*'){
                tmp *= comp[j].first;
            }
            if(bef =='-'){
                tmp -= comp[j].first;
            }
        }
        
        ans = max(ans, tmp);
    }
    
    cout<<ans<<"\n";
    return 0;
} // BruteForce, O(2^(N/2))