
#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    cin >> N;
    
    vector<ll> cnt(100'001);
    for(int i =0; i<N; ++i){
        ll tmp;
        cin >> tmp;
        cnt[tmp]++;
    }

    for(int i =0; i<100'001; ++i){
        if(cnt[i] > (N+1)/2){
            cout << "NO";
            return 0;
        }
    }    
    cout << "YES";

    return 0;
}