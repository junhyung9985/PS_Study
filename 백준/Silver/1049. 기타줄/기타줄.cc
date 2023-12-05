#include <iostream>

using namespace std;
int v[107];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    int a, b;
        
    cin >> N >> M;
    
    v[0] = 0;
    for(int i =1; i<=N+6; ++i)
        v[i] = 100000001;
    
    for(int i =0; i<M; ++i){
        cin >> a >> b;
        for(int j =0; j<=N+6; ++j){
            if(v[j+1] > v[j]+b) v[j+1] = v[j]+b;
            if(j < N){
                if(v[j+6] > v[j]+a) v[j+6] = v[j]+a;
            }
        }
    }
    for(int i =1; i<=6; ++i)
        v[N] = min(v[N], v[N+i]);
    
    cout << v[N];
    
    return 0;
} // DP