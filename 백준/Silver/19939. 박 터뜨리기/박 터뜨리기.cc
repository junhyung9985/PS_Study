#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, K;
    cin >> N >> K;
    
    ll sum =0;
    for(int i =1; i<=K; ++i){
        sum += i;
    }
    if(sum > N){
        cout << -1;
    }
    else if((N-sum)%K == 0){
        cout << K-1;
    }
    else cout << K;
    
    return 0;
}// Math