#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll N, M;
    ll start = 1;
    
    cin >> N >> M;
    bool can = true;
    for(int i =0; i<N-1; i++){
        ll cnt;
        ll r[2];
        char c[2];
        cin >> cnt;
        for(int i=0; i<cnt; i++)
            cin >> r[i] >> c[i];
        
        if(cnt == 1){
            if(c[0] == 'L'){
                start = max(start, r[0]+1);
            }
            else {
                can = can && (start < r[0]);
            }
        }
        if(cnt == 2){
            if(c[0] == 'R' && c[1] == 'L'){
                if(r[1] == M){
                    can = can &&(start < r[0]);
                }
                else if(r[0] == 1){
                    start = max(start, r[1]+1);
                }
                else{
                    if(start > r[0]){
                        start = max(start, r[1]+1);
                    }
                }
            }
            else if(c[0] =='L' && c[1] =='R'){
                start =max(start, r[0]+1);
                can = can&&(start < r[1]);
            }
            else if(c[0] =='L' && c[1] == 'L'){
                start =max(start, r[1]+1);
            }
            else {
               can = can &&(start < r[0]); 
            }
        }
        
    }
    
    can = can &&(start <=M);
    
    if(can){
        cout <<"YES";
    }
    else cout <<"NO";
    
    return 0;
}
/*
식지마스터를 넘어 잠입마스터까지... 최은규 화이팅!

1,1 -> N,M
move : UDLR or nothing

2개
   ---
---  ---


많은 조건분기? 역겹다;;

*/