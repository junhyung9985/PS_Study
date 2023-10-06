#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    ll fact = 1;
    ll two = 0, five = 0;
    
    for(int i =1; i<=n ;i++){
        ll tmp = i;
        while(tmp%2 == 0){
            ++two;
            tmp /= 2;
        }
        while(tmp%5 == 0){
            ++five;
            tmp /= 5;
        }
        fact *= tmp;
        fact %= 1000000000;
    }
    
    ll minn = min(two, five);
    two -= minn;
    five -= minn;
    fact %= 100000;
    
    for (int i =0; i<two; ++i){
        fact *= 2;
        fact %= 100000;
    }
    
    for (int i =0; i<five; ++i){
        fact *= 5;
        fact %= 100000;
    }
    int p = 10000;
    while(fact < p){
        cout <<0;
        p/=10;
    }
    cout << fact;
    
    return 0;
} // Math