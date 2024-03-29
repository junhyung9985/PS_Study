#include <bits/stdc++.h>
#define ll long long

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll N;
    cin >> N;
    
    list<ll> v;
    
    for(int i = N; i > 0; --i){
        auto which = v.end();
        ll diff = INT_MAX;
        ll total = N * (N+1)/2 - i * (i+1) / 2;
        ll curr_sum = 0;
        for(auto itr = v.begin(); itr!= v.end(); ++itr){
            if(diff > abs(total - curr_sum)){
                diff = abs(total - curr_sum);
                which = itr;
            }
            curr_sum += *itr;
            total -= *itr;
        }
        v.insert(which, i);
    }
    
    for(auto itr : v){
        cout << itr <<" ";
    }
    
    
    
    return 0;
} /*
3 2 1 4 

1 3 6 0


3 1 3 
2 + 2 = 4 

3 1 2 4 

1 5 3 0

3 1 2 3 
2 1 2 3 
2 1 2 2 


*/