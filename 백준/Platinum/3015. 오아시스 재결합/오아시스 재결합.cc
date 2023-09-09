#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N;
ll arr[500001];
deque<ll> q;
map<ll,ll> m;

int main()
{
    ll ans = 0;
    memset(arr, 0, sizeof(arr));
    
    cin >> N;
    for(int i =0; i<N; i++)
        cin >> arr[i];
    
    q.push_back(N-1);
    m[N-1] = 1;
    
    for(int i =N-2; i>-1; i--){
        //cout << arr[i] <<" ";
        m[i] = 1;
        int idx = q.back();
        int bef = -1;
        while(idx <N-1 && arr[idx] <= arr[i]){
            if(arr[idx] == arr[i]) m[i]+=m[idx];
            ans += m[idx];
            bef = idx;
            q.pop_back();
            idx = q.back();
        }
        if(arr[idx] >= arr[bef])
            ans += 1;
        q.push_back(i);
        //cout << ans <<"\n";
    }
    // for(int i =0; i<N; i++){
    //     cout << m[i] <<" ";
    // }
    // cout <<"\n";
    cout << ans;
    return 0;
}