#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<ll> v(N);
    unordered_set<ll> s;
    for(int i=0; i<N; ++i){
        cin >> v[i];
        s.insert(v[i]);
    }
    
    vector<ll> ans;
    for(int i =1; i<N; ++i){
        int diff = v[i] - v[0];
        bool flag =true;
        for(int j =0; j<N; ++j){
            if(s.find(v[j]+diff) == s.end() && s.find(v[j]-diff) == s.end() ){
                flag= false;
                break;
            }
        }
        if(flag){
            ans.push_back(diff);
        }
    }
    cout << ans.size()<<"\n";
    for(ll a : ans){
        cout << a <<" ";
    }
    
    
    return 0;
}