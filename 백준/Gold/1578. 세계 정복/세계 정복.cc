#include <bits/stdc++.h>
#define ll unsigned long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N, K;
    ll ans = 0;
    
    vector<ll> v;
    cin >> N >> K;
    for(int i =0; i<N; i++){
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    ll l = 0, r = 1e13;
    
    while(l+1 < r){
        ll mid = (l+r) / ((ll)2);
        ll result = 0;
        for(int i =0; i<v.size(); i++){
            result += min(v[i], mid);
        }
        //cout << result <<" "<<mid << " " << K<< " " << mid*K << "\n";
        if(result >= (ll)mid * K) l = mid;
        else r= mid;
        
    }
    
    
    
    cout << l;
    
    return 0;
}
/*

f d c b a  
e d c b a
e d c b a


*/