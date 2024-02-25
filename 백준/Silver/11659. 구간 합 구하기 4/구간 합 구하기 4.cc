#include <iostream>
#include <vector>

using namespace std;
vector <int> arr;
vector <int> cumulative;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
    int N, M;
    int foo, bar;
    foo = 0;
    cin >> N >> M;
    arr.resize(N,0);
    cumulative.resize(N+1,0);
    while(N--){
        cin >> arr[foo];
        cumulative[foo+1] = cumulative[foo]+arr[foo];
        foo ++;
        
    }
    
    while(M--){
        cin >> foo >> bar;
        cout << cumulative[bar]-cumulative[foo-1] << "\n";
    }
   return 0;
}


