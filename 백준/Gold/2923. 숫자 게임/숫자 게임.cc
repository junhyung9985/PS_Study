#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    
    vector<ll> a(100);
    vector<ll> b(100);
    
    for(int i =0; i<N; ++i){
        ll t1, t2;
        cin >> t1 >> t2;
        ++a[t1]; ++b[t2];
        ll s1 = 0, s2 = 0;
        ll maxx = 0;
        ll idx2 = 0;
        for(ll j = 99; j>0; --j){
            if(a[j] == 0) continue;
            s2 += a[j];
            while(s1 < s2){
                s1 += b[idx2];
                ++idx2;
            }
            maxx = max(j+idx2-1, maxx);
        }
        cout << maxx<<"\n";
    }
    
    return 0;
} 
// Greedy, Two-Pointer
// O(100*N)