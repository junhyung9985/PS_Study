#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    for(char ch : s){
        cout << (char)(ch^(0x20));
    }
}