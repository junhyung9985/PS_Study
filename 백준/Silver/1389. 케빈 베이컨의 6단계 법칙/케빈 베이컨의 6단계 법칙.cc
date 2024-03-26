#include <deque>
#include <iostream>
#include <stdlib.h>
#define INF 987654321
using namespace std;

int **arr;
int N, M;
int foo, bar;

void dij(int start) {
  int idx, d;
  deque<int> deq;
  for (int i = 0; i < N; i++) {
    if (arr[start][i] != INF)
      deq.push_back(i);
  }

  while (!deq.empty()) {
    idx = deq[0];
    deq.pop_front();

    for (int i = 0; i < N; i++) {
      if (arr[idx][i] != INF) {
        if (arr[idx][i] + arr[start][idx] < arr[start][i]) {
          arr[start][i] = arr[idx][i] + arr[start][idx];
          arr[i][start] = arr[idx][i] + arr[start][idx];
          deq.push_back(i);
        }
      }
    }
  }

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     if (arr[i][j] == INF)
  //       cout << "INF ";
  //     else
  //       cout << arr[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  return;
}
int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  arr = (int **)malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++)
    arr[i] = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      arr[i][j] = INF;
    arr[i][i] = 0;
  }

  for (int i = 0; i < M; i++) {
    cin >> foo >> bar;
    arr[foo - 1][bar - 1] = 1;
    arr[bar - 1][foo - 1] = 1;
  }

  for (int i = 0; i < N; i++) {
    dij(i);
  }

  int idx = 0;
  int sum = INF;
  for (int i = 0; i < N; i++) {
    int s = 0;
    for (int j = 0; j < N; j++) {
      s += arr[i][j];
    }
    if (sum > s) {
      sum = s;
      idx = i;
    }
  }

  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < N; j++) {
  //     cout << arr[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  cout << idx + 1;

  return 0;
}