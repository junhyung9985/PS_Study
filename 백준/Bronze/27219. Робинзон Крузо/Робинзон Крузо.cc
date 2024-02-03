#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin >> n;
    while(n>=5){cout<<"V";n-=5;}
    for(int i=0;i<n;++i)cout<<"I";
    return 0;
}