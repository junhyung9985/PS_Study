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
    bool can = true;
    int diff =  0;
    for(int i =0; i<N; ++i){
        cin >> v[i];
        if(i > 0){
            if(i == 1) diff = v[i]-v[i-1];
            if(diff != v[i]-v[i-1]){
                cout <<"NO"; return 0;
            }
        }
        
    }
    
    cout <<"YES\n";
    for(int i =0; i<N; ++i)
        cout << v[i]<<" ";
    cout<<"\n";
    for(int i =0; i<N; ++i)
        cout << 0<<" ";
    cout<<"\n";
    
    

    
    
    return 0;
}

