#include <bits/stdc++.h>

using namespace std;

bool cmp(int a, int b) {
  bool flag = true;
  string tmp_a = to_string(a) + to_string(b),
         tmp_b = to_string(b) + to_string(a);
  int idx = 0;
  while (idx < tmp_a.length()) {
    if (tmp_a[idx] == tmp_b[idx])
      idx++;
    else
      break;
  }
  if (idx == tmp_a.length())
    idx--;
  return (tmp_a[idx] > tmp_b[idx]);
}

int main() {
  int N;
  long long tmp, foo, bar;
  string ans = "";
  vector<int> arr;

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int flag = 0;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    foo = 0;
    bar = 0;
    if (tmp != 0)
      flag = 1;
    arr.push_back(tmp);
  }
  if (flag == 0) {
    cout << "0";
    return 0;
  }
  sort(arr.begin(), arr.end(), cmp);

  for (int i : arr) {
    ans += to_string(i);
  }
  cout << ans;

  return 0;
}

/*


 3434 34


*/
