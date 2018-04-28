// pl.spoj.com: dachu21

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int W, N;
  while (cin >> W >> N && !(W == 0 && N == 0)) {

    // FEES AND FUN VALUES ARRAYS
    int *weights = new int[N + 1];
    int *values = new int[N + 1];

    // FEES AND FUN VALUES INPUT
    weights[0] = 0;
    values[0] = 0;
    for (int i = 1; i <= N; i++) {
      cin >> weights[i] >> values[i];
    }

    // MATRIX INITIALIZATION (0)
    int **M = new int *[N + 1];
    for (int i = 0; i <= N; i++) {
      M[i] = new int[W + 1];
      fill_n(M[i], W + 1, 0);
    }

    // ALGORITHM
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j <= W; j++) {
        if (weights[i] > j) {
          M[i][j] = M[i - 1][j];
        } else {
          M[i][j] = max(M[i - 1][j], M[i - 1][j - weights[i]] + values[i]);
        }
      }
    }

    // EXTRACTING MAX FUN VALUE
    int maxValue = M[N][W];

    // FINDING TOTAL FEE
    int totalCost = 0;
    for (int i = 0; i <= W; i++) {
      if (M[N][i] == maxValue) {
        totalCost = i;
        break;
      };
    }

    // OUTPUT
    cout << totalCost << " " << maxValue << "\n";

    // MEMORY CLEAR
    delete[] weights;
    delete[] values;
    for (int i = 0; i <= N; i++) {
      delete[] M[i];
    }
    delete[] M;
  }

  return 0;
}