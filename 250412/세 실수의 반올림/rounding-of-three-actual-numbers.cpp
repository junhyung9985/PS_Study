#include <iostream>
#include<cmath>
using namespace std;

int main() {
    double a,b,c;
    cout.precision(3);
    cout << fixed;
    cin >> a >> b >> c;
    a = round(a*1000)/1000;
    b = round(b*1000)/1000;
    c = round(c*1000)/1000;
    cout << a <<"\n"<<b <<"\n"<<c;
    // Please write your code here.
    return 0;
}