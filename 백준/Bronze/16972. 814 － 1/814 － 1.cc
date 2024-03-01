#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << 0 << " "<< 0<<"\n";
    for(int i =0; i<813; i++){
        cout << i <<" "<<i+1<<"\n";
    }
    return 0;
}

/*
(0,0)
(1,0)
(2,1)
(3,2)
(4,3)
()
(4,6)
(5,)



(1,1)         
(1,3) (2,2) (3,1)
(2,4) (3,3)( 4,2) ( 5,1)

1,1 -> 1,3 -> 4,2 -> 2,6

flip, +1 +1 , (짝수번째 때) -1 +1 


(1,4)
(1,2) (2,3) (3,4)
(2,1) (3,2) (4,3)
(4,1)
(1,2)

1 3 2
 

-1 -1 (+cnt , -cnt) or (-cnt, +cnt)
cnt++ 짝수번째 때

 1  o  2  4
 6  x  o  x 
 x o  x  5
 o 3  o  x

*/