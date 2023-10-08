#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    
    ll ans = 0;
    unordered_map<ll, int> m1;
    unordered_map<ll, int> m2;
    m2[0] = 1;
    
    ll bef_bitwise = 0;
    
    for(ll i =0; i<N; ++i){
        char s;
        cin >> s;
        ll val = 0;
        ll bitwise = 0;
        if(s >= 'a') val = s-'a'+26;
        else val = s - 'A';
        //cout << val <<"\n";
        bitwise = ((ll)1 << val);
        bitwise ^= bef_bitwise;
        bef_bitwise = bitwise;
        
        ll diff = bitwise;
        if(i%2 == 0){
            if(m1.find(diff) != m1.end())
            ans += m1[diff];
            for(ll j =0; j<52; ++j){
                ll offset = ((ll)1<<j);
                ll odd = diff ^ offset;
                if(m2.find(odd) != m2.end())
                ans += m2[odd];
            }
        }
        else {
            if(m2.find(diff) != m2.end())
            ans += m2[diff];
            for(ll j =0; j<52; ++j){
                ll offset = ((ll)1<<j);
                ll odd = diff ^ offset;
                if(m1.find(odd) != m1.end())
                ans += m1[odd];
            }
        }
        
        if(i%2 == 0){
            ++m1[diff];
        }
        else ++m2[diff];
    }
    
    cout << ans;
    return 0;
}
/*
만약에 홀수개 -> 홀수 하나, 나머지는 전부 짝수
만약에 짝수개 -> 전부 짝수

이를 bitwise로 푸는 방법도 있어는 보임.

tag : bitmasking, map

*/