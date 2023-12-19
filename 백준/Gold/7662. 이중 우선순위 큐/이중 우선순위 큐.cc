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
    
    ll T;
    cin >> T;
    while(T--){
        ll n;
        multiset<ll> s;
        cin >> n;
        for(int i =0; i<n; i++){
            char ch;
            ll tmp;
            cin >> ch >> tmp;
            if(ch == 'I') s.insert(tmp);
            else{
                if(s.begin() == s.end()) continue;
                if(tmp == 1){
                    auto itr = s.end();
                    itr --;
                    s.erase(itr);
                }
                else {
                    auto itr = s.begin();
                    s.erase(itr);
                }    
            }
            
        }

        auto st = s.begin();
        auto e = s.rbegin();
    
        if(s.begin() == s.end()) cout << "EMPTY\n";
        else cout << *e <<" "<<*st<<"\n";

    }
    
    return 0;
}