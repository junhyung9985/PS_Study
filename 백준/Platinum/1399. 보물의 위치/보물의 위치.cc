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
    ll T, K, M;
    map<ll, ll> m;
    for(int i=1; i<=9 ;i++)
        m[i] = i;
    for(int i=10; i<=10000; i++){
        ll tmp = i;
        ll actual = 0;
        while(tmp){
            actual += tmp%10;
            tmp /=10;
        }
        m[i] = m[actual];
    }
    
    cin >> T;
    while(T--){
    
        ll K, M;
        cin >> K >> M;

        bool check[10];
        int curr = 1;
        ll y = 0, x = 0;
        
        vector<int> cycle;    
        deque<int> y_change(1);
        deque<int> x_change(1);
        memset(check,0,sizeof(check));
        
        while(!check[m[curr]]){
            check[m[curr]] = true;
            cycle.push_back(curr);
            curr = m[M*curr];
        }
        
        if(m[M]%3 == 0){
            for(int i=0; i<2; i++){
                ll size = cycle.size();
                for(int j=0; j<size; j++){
                    cycle.push_back(cycle.back());
                }
            }
        }
        else {
            for(int i=0; i<2; i++){
                ll size = cycle.size();
                for(int j=0; j<size; j++){
                    cycle.push_back(cycle[j]);
                }
            }
        }
        
        for(int i =0; i<cycle.size(); i++){
            if(i%4 == 0){
                y_change.push_back(y_change.back()+cycle[i]);
                x_change.push_back(x_change.back());
            }
            else if(i%4 == 2){
                y_change.push_back(y_change.back()-cycle[i]);
                x_change.push_back(x_change.back());
            }
            else if(i%4 == 1){
                x_change.push_back(x_change.back()+cycle[i]);
                y_change.push_back(y_change.back());
            }
            else{
                x_change.push_back(x_change.back()-cycle[i]);
                y_change.push_back(y_change.back());
            }
        }
        x_change.pop_front();
        y_change.pop_front();
        K--;
        if(K < x_change.size()){
            y = y_change[K];
            x = x_change[K];
        }
        else{
            
            if(m[M]%3 == 0){
                ll times = K/(x_change.size());
                K%= (x_change.size());
                y = y_change.back();
                x = x_change.back();
                if(K%4 == 0){
                    y+= 9;
                }
                else if (K%4 == 1){
                 y+=9;
                 x+=9;
                }
                else if (K%4 == 2){
                    x += 9;
                }
                else ;
            }
            else{
                ll times = K/(x_change.size());
                K%= (x_change.size());
                y = y_change.back() * times + y_change[K];
                x = x_change.back() * times + x_change[K];
            }
        }
        cout << x <<" "<< y<<"\n";
        
        
    }
    return 0;
}
/*
+y, +x, -y , -x

+1 0 -1 0 +1 0 -1 0

1 : 1
2 : 1 2 4 8 7 5 1...
3 : 1 3 9 9 9 9 9 9 9 9 9....
4 : 1 4 7 1...
5 : 1 5 7 8 4 2 1 ...
6 : 1 6 9 9 9 .....
7 : 1 7 4 1 ...
8 : 1 8 1 ...
9 : 1 9 9 9....

m[M] = s
m[M*s] => m[s*s]


*/