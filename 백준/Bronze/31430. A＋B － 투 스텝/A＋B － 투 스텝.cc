#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    ll T;
    cin >> T;
    if(T == 1){
        ll a, b;
        cin >> a >> b;
        ll s = a+b;
        
        deque<ll> q;
        for(int i =0; i<13; ++i){
            q.push_front(s%26);
            s/=26;
        }
        for(int i =0; i<13; ++i){
            cout << (char)(q[i]+'a');
        }
    }
    else{
        string s;
        cin >> s;
        ll ans = 0;
        for(int i =0; i<13; ++i){
            ans = 26*ans + (s[i]-'a');
        }
        cout << ans;
    }

    return 0;
} // Hashing...?
// 18 * log10 / log26 < 13 이므로 저렇게 압축이 가능함.