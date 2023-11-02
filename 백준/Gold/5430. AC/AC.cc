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
        int n;
        string p;
        bool flip = false;
        bool error =false;
        char tmp;
        cin >> p;
        cin >> n;
        cin >> tmp;
        deque<int> q(n);
        for(int i =0; i<n; i++){
            cin >> q[i];
            cin >> tmp;
        }
        if(n == 0) cin >> tmp;
        
        for(char c : p){
            if(c == 'R') flip = !flip;
            else {
                if(q.empty()) error = true;
                else if(flip) q.pop_back();
                else q.pop_front();
                if(!error) n--;
            }
            
        }
        if(error) cout << "error\n";
        else if(flip){
            cout <<"[";
            for(int i =n-1; i>0; i--)
                cout << q[i] <<",";
            if(!q.empty()) cout<<q[0];
            cout << "]\n";
        }
        else{
            cout <<"[";
            for(int i =0 ; i<n-1; i++)
                cout << q[i] <<",";
            if(!q.empty()) cout<<q[n-1];
            cout <<"]\n";
        }
        
    }

    return 0;
}