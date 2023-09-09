/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll a, ll b){
    if(a%b ==0) return b;
    return gcd(b, a%b);
}


int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll N;
    ll arr[500001];
    ll arr2[500001];
    map<ll, vector<ll>> m;

    cin >> N;
    for(int i =0; i<N; i++){
        cin >> arr[i]; 
        arr2[i] = arr[i];
    }
    
    sort(arr2, arr2+N);
    
    for(int i =0; i<N; i++){
        if(arr[i]!= arr2[i]) {
            m[arr2[i]].push_back(arr[i]);
        }        
    }
    
    bool ans = true;
    for(auto itr = m.begin(); itr != m.end(); itr++){
        
        ll value = itr->first;
        for(ll check : m[value]){
            ll larger = check;
            ll smaller = value;
            if(smaller > larger){
                larger = value;
                smaller = check;
            }
            ll result = gcd(larger,smaller);
        
            larger/=result;
            smaller /=result;
        
            ll larger2 = sqrt(larger);
            ll smaller2 = sqrt(smaller);
            if(larger2*larger2 != larger) ans = false;
            if(smaller2*smaller2 != smaller) ans = false;
        }
    }
    
    if(ans) cout << "YES";
    else cout <<"NO";
    
    
    return 0;
}
/*

Ai Aj 가능 , Aj Ak 가능하면 Ai Ak도 가능!

그러므로 Ai 가 i번째로 가야하는 수면
현재 i번째 있는 수와 교환이 가능해야함

*/