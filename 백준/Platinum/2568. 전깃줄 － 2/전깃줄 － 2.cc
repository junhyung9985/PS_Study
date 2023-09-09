/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll N;
    ll arr[500001];
    ll dp[500001];
    vector<ll> v;
    memset(arr,0, sizeof(arr));
    cin >> N;
    for(int i =0; i<500001; i++){
        arr[i] = 500001;
        dp[i] = 500001;
    }
    
    for(int i=0; i<N; i++){
        ll a, b;
        cin >>a >> b;
        arr[a] = b;
    }
    for(int i =0; i<500001; i++){
        int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        if(idx == v.size()){
            v.push_back(arr[i]);
        }
        else v[idx] = arr[i];
        dp[i] = idx;
    }
    
    cout << N-v.size()+1<<"\n";
    ll found = v.size()-2;
    vector<ll> ans;
    for(int i =500000; i>-1; i--){
        if(arr[i] == 500001) continue;
        if(arr[i] == v[found] || dp[i] == found){
            found --;
        }
        else {
            ans.push_back(i);
        }
    }
    while(!ans.empty()){
        cout << ans.back() <<"\n";
        ans.pop_back();
    }
    
    
    return 0;
}
/*
전깃줄 -> LIS 문제와 동일
NlogN 으로 풀면 된다.
실질적으로 500000log500000 해도 될듯?

다만 잘라야 하는걸 계산해야 하므로...

8 2 9 1 4 6 7 10;
2 4 6 7 10;

*/

