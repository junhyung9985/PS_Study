#include <iostream>

using namespace std;

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  int two = 0, five = 0;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 0 || i % 5 == 0) {
      int tmp = i;
      while (tmp % 2 == 0) {
        two++;
        tmp /= 2;
      }
      tmp = i;
      while (tmp % 5 == 0) {
        five++;
        tmp /= 5;
      }
    }
  }

  cout << min(two, five) << "\n";

  return 0;
}