#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll N;
    cin >> N;
    
    vector<string> v(N);
    vector<ll> cnt(N);
    map<string, ll> m;
    for(int i =0; i<N; ++i){
        cin >> v[i];
        m[v[i]] = i;
    }
    
    
    ll lied = 0;
    for(int i =0; i<N; ++i){
        for(int j =0; j<2; ++j){
            cout << "? "<<v[i]<<"\n";
            cout << flush;
            
            ll num;
            cin >> num;
            cnt[i] += num;
        }    
        if(cnt[i] == 2){
            cout << "! "<<v[i]<<"\n";
            cout << flush;
            return 0;
        }
        else if (cnt[i] == 1){
            lied = i;
        }
    }
    
    cout << "! "<<v[lied]<<"\n";
    cout << flush;
    return 0;
} // Bruteforcing