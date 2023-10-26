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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
        
    cin >> N;
    set<pair<ll,string>> v;

    for(int i =0; i<N; i++){
        string tmp;
        cin >> tmp;
        v.insert({tmp.size(), tmp});
    }
    for(auto itr : v){
        cout << itr.second <<"\n";
    }
    
    return 0;
}
/*
Tree_Set
*/