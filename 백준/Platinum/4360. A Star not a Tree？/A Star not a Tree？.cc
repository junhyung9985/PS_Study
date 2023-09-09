#include <bits/stdc++.h>
#define ll long long
#define tmp (x[i]-a)*(x[i]-a) + (y[i]-b)*(y[i]-b)
using namespace std;

long double N;
long double x[101];
long double y[101];
long double a = 0, b = 0;

int main()
{
    long double ans = 0;
    
    cin >> N;
    for(int i =0; i <N; i++){
        cin >> x[i] >> y[i];
    }
    
    a = x[0]*1.0;
    b = y[0]*1.0;
    long double p = 1.0;
    long double r = 1.0;
    
    
    while(p || r){
    p = 0, r = 0;
    for(int i =0; i <N ; i++){
        if(tmp !=0){
            p += ((x[i]-a)/sqrt(tmp));
            r += ((y[i]-b)/sqrt(tmp));
            
        }
    }
    if(abs(p) < 0.000000001) p = 0;
    if(abs(r) < 0.000000001) r = 0;
    
    a += p;
    b += r;
    //cout << a <<" " << b <<"\n";

    }

    
    
    for(int i=0; i <N; i++){
        ans += sqrt(tmp);
    }
    
    cout << round(ans);
    
    
    return 0;
}