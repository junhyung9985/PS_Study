/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N;
vector<ll> v;
ll arr[1000001];
ll dp[1000001];
vector<ll> ans;

int main()
{
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i =0; i<N; i++){
        int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
        if(idx == v.size()){
            v.push_back(arr[i]);
        }
        else v[idx] = arr[i];
        dp[i] = idx;
    }
    
    cout << v.size()<<"\n";
    ll found = v.size()-1;

    for(int i = N-1; i>-1; i--){
        if(dp[i] == found){
            ans.push_back(arr[i]);
            found --;
        }
    }
    while(!ans.empty()){
        cout << ans.back() <<" ";
        ans.pop_back();
    }
    
    
    return 0;
}
/*
NlogN 으로 풀면 된다.
실질적으로 500000log500000 해도 될듯?

좌표 압축으로 pair를 쓰면 더 빠르게 처리가 가능하다.
다만, 이 문제에서는 좌표 압축까지 안해도 풀리기 때문에 안함.

*/

