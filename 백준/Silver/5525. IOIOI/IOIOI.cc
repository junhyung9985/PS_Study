#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    string S;
    cin >> N >> M >> S;
    
    int idx = 0;
    ll streak = 0;
    ll ans = 0;
    
    while(idx < M){
        while(S[idx] == 'O' && idx < M) ++idx;
        while(idx +2 <M){
            if(S[idx+1] == 'O' && S[idx+2] == 'I'){
                ++streak;
                idx+=2;
            }
            else {
                break;
            }
        }
        ans += max((ll)0, streak - N+1);
        streak = 0;
        ++idx;
    }
    
    cout << ans;
    
    return 0;
} // String, Greedy -> O(M)