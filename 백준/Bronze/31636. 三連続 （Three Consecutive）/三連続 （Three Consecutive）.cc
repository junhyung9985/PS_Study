#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N; cin >> N;
    int count = 0;
    for(int i =0; i<N; ++i){
        char ch;
        cin >> ch;
        if(ch == 'o'){
            ++count;
        }
        else count = 0;
        if(count == 3){
            cout <<"Yes";
            return 0;
        }
    }
    cout <<"No";
    return 0;
}