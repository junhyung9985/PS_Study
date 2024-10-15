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
    ll N, S;
    ll arr[100001];
    ll ans = 100001;
    cin >> N >> S;
    memset(arr, 0, sizeof(arr));
    for(int i =1; i<=N; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    
    ll l =0, r=1;
    while(r<=N){
        ll diff = arr[r]-arr[l];
        if(diff<S){
            r++;
        }
        else if(diff>=S){
            ans = min(r-l, ans);
            l++;
        }
    }
    if(ans == 100001) cout << 0;
    else cout << ans;
    
    
    
    return 0;
}
/*

prefix sum + two pointers

*/

