#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    cin >> N;
    --N;
    ll cnt = 2;
    ll count = 1;
    while(true){
        if(N >= cnt) N -= cnt;
        else break;
        cnt *=2;
        ++count;
    }
    
    vector<ll> v;
    for(int i = 0; i<count ; ++i){
        if(N%2) v.push_back(7);
        else v.push_back(4);
        N/=2;
    }
    
    reverse(v.begin(), v.end());
    for(auto itr : v) cout << itr ;
    
    return 0;
} 
/*
4 7 44 47 74 77 444 447
0 1 00 01 10 11 000 001
2, 4, 8, 16, 32, 64, 128, 256, 

0 1 2 

*/