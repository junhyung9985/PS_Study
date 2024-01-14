#include <iostream>
#include <vector>
#include <string>
#define MOD 1000000007
#define FORM_UP(X) for(int i =X.size()-2; i>-1; i--) X[i] = (X[i]%MOD+X[i+1]%MOD)%MOD;
#define PRINT_VECTOR(X) for(int i = 0; i<X.size(); i++){cout << X[i] << " ";} cout << endl;
using namespace std;

vector <unsigned long long int> E;
vector <unsigned long long int> H;
vector <unsigned long long int> W; 
vector <unsigned long long int> twos;


int main(){
  int N;
  int idx;
  string str;
  cin >> N >> str;

  for (char s : str){
    E.push_back(s == 'E' ? 1 : 0);
    H.push_back(s == 'H' ? 1 : 0);
    W.push_back(s == 'W' ? 1 : 0);
  }
  
  twos.push_back(1);
  for (int i =1; i<N+1; i++){
    twos.push_back(((2*twos[i-1]))%MOD);
  }
  
  FORM_UP(E);

  idx = 0;
  for (int i : H){
    if(i){
      H[idx] = (twos[E[idx]]-1-E[idx])%MOD;
    }
    idx += 1;
  }

  FORM_UP(H);

  idx = 0;
  for (int i : W){
      if(i){
        W[idx] = H[idx];
      }
    idx += 1;
  }
  FORM_UP(W);

  cout << W[0];
  
  //PRINT_VECTOR(E);
  


  
  
}