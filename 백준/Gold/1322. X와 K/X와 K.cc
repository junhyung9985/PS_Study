#include <iostream>
#include <vector>
#define PRINT(X) for (int i =0; i < X.size(); i++){ cout << X[i] <<" ";} cout << "\n";
#define llu unsigned long long int
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<llu> arr;
    llu X, K;
    
    cin >> X >> K;
    llu a = ~X;
    llu tmp = 1;
    while(a>0){
        if(a%2) {
            arr.push_back(tmp);
            a--;
        }
        tmp*=2;
        a/=2;
    }
    //PRINT(arr);
    llu ans = 0;
    int idx = 0;
    while(K>0){
        if(K%2){
            ans += arr[idx];
            K--;
        }
        idx++;
        K/=2;
    } 
    
    cout << ans;
    return 0;
}
