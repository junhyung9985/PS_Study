#include <iostream>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(1);
  cout<<fixed;
  
  double ans = 0.0;
  double low = 0.0;
  double a1, a2;
  double b1, b2;
  double c1, c2;

  cin >> ans;
  cin >> a1 >> a2;
  cin >> b1 >> b2;
  cin >> c1 >> c2;
  
  if(a1 > a2){
    double tmp = a2;
    a2 = a1;
    a1 = tmp;
  }  
  if(b1 > b2){
    double tmp = b2;
    b2 = b1;
    b1 = tmp;
  }  
  if(c1 > c2){
    double tmp = c2;
    c2 = c1;
    c1 = tmp;
  }

  
  double between = 0.0;
  if(a1 != a2){
    between = (a1+a2)/2.0;
    if(ans - between > between){
      low = between;
    }
    else ans = between;
    
    if(b2 > ans){
      b2 = 2*ans - b2;
    }
    if(c2 > ans){
      c2 = 2*ans - c2;
    }
    if(b1 > ans){
      b1 = 2*ans - b1;
    }
    if(c1 > ans){
      c1 = 2*ans - c1;
    }    
    
    if(b1 < low){
        b1 = low*2 - b1;
    }
    if(c1 < low){
        c1 = low*2 - c1;
    }
    if(b2 < low){
        b2 = low*2 - b2;
    }
    if(c2 < low){
        c2 = low*2 - c2;
    }    
    
  }


  if(b1 > b2){
    double tmp = b2;
    b2 = b1;
    b1 = tmp;
  }  
  if(c1 > c2){
    double tmp = c2;
    c2 = c1;
    c1 = tmp;
  }
  
  if(b1 != b2){
    between = (b1+b2)/2.0;
    double coef = low;
    if(ans - between > between-low){
        low = between;
    }
    else ans = between;
    
    //cout << between <<" " << ans <<"\n";
  
    if(c2 > ans){
      c2 = 2*ans - c2;
    }
    if(c1 > ans){
      c1 = 2*ans - c1;
    }
    if(c1 < low){
        c1 = low + (low-c1);
    }
    if(c2 < low){
        c2 = low + (low-c2);
    }
  }
  
  if(c1 > c2){
    double tmp = c2;
    c2 = c1;
    c1 = tmp;
  }
  

  if(c1 != c2){
    between = (c1+c2)/2.0;
    double coef = low;
    if(ans - between > between-low){
      low = between;
    }
    else ans = between;
  }
  cout << ans-low <<"\n";

  return 0;
}