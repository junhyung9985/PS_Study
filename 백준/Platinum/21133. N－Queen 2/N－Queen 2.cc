#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    ll N;
    cin >> N;
    for(int i =1; i<=N; i+=2){
        cout << i <<"\n";
    }
    for(int i=2; i<=N; i+=2){
        cout << i<<"\n";
    }

    return 0;
}
/*
1 3 5 7 ... 2k-1
2 4 6 8 ... 2k


*/