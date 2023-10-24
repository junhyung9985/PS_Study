#include <bits/stdc++.h>

#define ll long long

using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    vector<int> arr;
    cin >> N >> K;
    queue<int> q;
    q.push(N);
    
    for(int i =0; i<200001; i++)
        arr.push_back(200001);
    
    arr[N] = 0;
    
        
    while(!q.empty()){
        int i = q.front();
        q.pop();
        if(i<=100000)
            if(arr[2*i] > (arr[i]+1)){
                arr[2*i] = arr[i]+1;
                q.push(2*i);
            }
        if(i<200000)
            if(arr[i+1] > (arr[i]+1)){
                arr[i+1] = arr[i]+1;
                q.push(i+1);
            }
        if(i > 0)
            if(arr[i-1] > (arr[i]+1)){
                arr[i-1] = arr[i]+1;
                q.push(i-1);
            }
    }
    // for(int i =1; i <N+K; i++){
    //     cout << arr[i] <<" ";
    // }
    // cout <<"\n";
    
    cout << arr[K];
    
    return 0;
}