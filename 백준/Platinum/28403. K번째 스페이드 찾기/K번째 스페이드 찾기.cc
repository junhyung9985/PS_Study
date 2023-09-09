#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    
    ll N;
    ll arr[1000005];
    cin >> N;
    memset(arr,0,sizeof(arr));
    for(int i =0; i<N; i++){
        char ch;
        cin >> ch;
        if(ch == 'S') arr[i] = 1;
        if(i > 0) arr[i]+= arr[i-1];
    }
    
    for(int k =1; k<=N; k++){
        ll to_check = k-1;
        ll now = k;
        ll cnt = 0;
        while(to_check < N){
            cnt++;
            if(arr[to_check] == k) break;
            now = k-arr[to_check];
            to_check += now;
        }
        cout << cnt<<" ";
    }
    
    
    return 0;
}