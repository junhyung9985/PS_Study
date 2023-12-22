#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<vector<ll>> s(N, vector<ll>(N));
    ll total = 0;
    for(int i =0; i<N; ++i)
        for(int j =0; j<N; ++j)
            cin >> s[i][j];
    
    ll minn = INT_MAX;
    for(int i = 0; i<pow(2,N); ++i){
        ll idx = 0;
        ll t = i;
        vector<bool> count(N, false);
        while(t){
            if(t%2){
                count[idx] = true;
            }
            ++idx;
            t/=2;
        }
        ll sum = 0;
        ll rest = 0;
        for(int i =0; i<N; ++i){
            for(int j =0; j<N; ++j){
                if(count[i] == count[j]){
                    if(count[i]) sum += s[i][j];
                    else rest += s[i][j];
                }
            }
        }

        minn = min(minn, abs(sum-rest));
    }
    cout << minn;
    
    return 0;
} // Bitmasking, Bruteforcing