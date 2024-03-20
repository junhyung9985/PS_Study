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
    deque<ll> stck;
    deque<ll> in_case;
    for(int i = 0; i < N; ++i) cin >> v[i];
    
    ll cnt = 0;
    ll ans = -1;
    for(int i = 0; i < N; ++i){
        if(!stck.empty()){
            if(stck.back() == v[i]){
                in_case.push_back(stck.back());
                in_case.push_front(stck.back());
                stck.pop_back();
                if(stck.empty()){
                    ++cnt;
                    in_case.clear();
                }
            }
            else{
                while(!in_case.empty()){
                    stck.push_back(in_case.front());
                    in_case.pop_front();
                }
                stck.push_back(v[i]);
            } 
        }
        else stck.push_back(v[i]);
    }
    
    if(stck.empty()) ans = cnt;
    cout << ans;
    
    
    return 0;
} // Greedy...?

// 1 2 3 3 2 2 3 3 2 1