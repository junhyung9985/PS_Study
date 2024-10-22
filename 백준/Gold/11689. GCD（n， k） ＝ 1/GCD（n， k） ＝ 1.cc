/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<int> p;
bool primes[1000001];
map<ll, int> m;

ll Euler(ll k){
    return pow(k,m[k])-pow(k,m[k]-1);
}

int main()
{
    ll N ;
    cin >> N;
    
    for(int i =2; i<=1000000; i++){
        if(!primes[i]){
            p.push_back(i);
            for(int j=i*2; j<=1000000; j+=i)
                primes[j] = true;
        }
    } // Prime numbers
    
    while(N > 1){
        bool flag = true;
        for(int prime : p){
            if(N%prime ==0){
                m[prime]++;
                N/=prime;
                flag = false;
                break;
            }
        }
        if(flag) {
            m[N] = 1;
            N = 1;
        }
    } // Factorization
    
    
    ll cnt = 1;
    for(auto iter = m.begin(); iter != m.end(); iter++){
        cnt *= Euler(iter->first);
    }
    cout << cnt;
    
    return 0;
}
/*
오일러 함수였다고 하네요 네~
https://seongjuk.tistory.com/entry/오일러-𝜑피-또는-파이-함수-서로소-개수-구하기
*/