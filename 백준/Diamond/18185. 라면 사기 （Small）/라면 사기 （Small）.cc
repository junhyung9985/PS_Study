#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N;
    cin >> N;
    vector<ll> v(N+3);

    for(int i =1; i<=N; ++i){
        cin >> v[i];
    }

    ll ans = 0;
    for(int i =1; i<=N; ++i){
        if(v[i+1] > v[i+2]){ // 앞에 두 개 가지고 평평하게, 만든 후에 최대한 다 빼기
            ll minn = min(v[i], v[i+1]-v[i+2]);
            ans += 5 * minn;
            v[i] -= minn;
            v[i+1]-=minn;
            
            minn = min(v[i], min(v[i+1], v[i+2]));
            ans += 7 * minn;
            v[i] -= minn;
            v[i+1] -= minn;
            v[i+2] -= minn;
        }
        else {
            ll minn = min(v[i], min(v[i+1], v[i+2]));
            ans += 7 * minn;
            v[i] -= minn;
            v[i+1] -= minn;
            v[i+2] -= minn;
            
            minn = min(v[i], v[i+1]);
            ans += 5 * minn;
            v[i] -= minn;
            v[i+1] -= minn;
        }
        ans += 3*v[i];
    }
    
    cout << ans;
    return 0;
}
/*

Greedy - Solution 참고 및 이해

https://oh2279.tistory.com/133
https://youngyojun.github.io/contest/review/2020/02/15/iamcoder-2019-yearend-contest/

*/
