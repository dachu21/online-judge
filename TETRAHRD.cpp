// spoj.com: dachu21

#include <iostream>
#include <cstring>

using namespace std;

const unsigned long long K = 4;
const unsigned long long SIZE = 5;
const unsigned long long MOD = 1000000007;
const unsigned long long FORMULA_MATRIX[SIZE][SIZE] = {{0, 1, 0, 0, 0},
                                                       {0, 0, 1, 0, 0},
                                                       {0, 0, 0, 1, 0},
                                                       {1, 1, 1, 1, 0},
                                                       {1, 1, 1, 1, 1},
};

struct Vector {
  unsigned long long v[SIZE] = {};
};

struct Matrix {
  unsigned long long m[SIZE][SIZE] = {{}};
};

Vector matVecProduct(Matrix matrix, unsigned long long vec[SIZE]) {

  Vector ret;
  Matrix tmp;

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      tmp.m[i][j] = matrix.m[i][j] * vec[j];
      ret.v[i] += tmp.m[i][j];
    }
  }

  return ret;
}

Matrix matMatProduct(Matrix matrix1, Matrix matrix2) {

  Matrix ret;

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      for (int k = 0; k < SIZE; k++) {
        ret.m[i][j] += (matrix1.m[i][k] * matrix2.m[k][j]);
        ret.m[i][j] %= MOD;
      }
    }
  }

  return ret;
}

Matrix matPow(Matrix base, unsigned long long exponent) {

  Matrix ret;

  for (int i = 0; i < SIZE; i++) {
    ret.m[i][i] = 1;
  }
  while (exponent != 0) {
    if (exponent % 2 == 1) {
      ret = matMatProduct(ret, base);
      exponent--;
    } else {
      base = matMatProduct(base, base);
      exponent /= 2;
    }
  }

  return ret;
}

unsigned long long sum(unsigned long long m, unsigned long long n) {

  unsigned long long sumN, sumM, sum;
  unsigned long long startVector[] = {0, 0, 0, 1, 1};
  Matrix matrix;

  memcpy(matrix.m, FORMULA_MATRIX, sizeof(FORMULA_MATRIX));

  if (n < 3)
    sumN = 0;
  else
    sumN = matVecProduct(matPow(matrix, n - (K - 1)), startVector).v[SIZE - 1];

  if (m < 4)
    sumM = 0;
  else
    sumM = matVecProduct(matPow(matrix, m - (K - 1) - 1), startVector).v[SIZE - 1];

  sum = sumN - sumM;

  return (sum + MOD) % MOD;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testsCount;
  unsigned long long m, n;

  cin >> testsCount;
  for (int i = 0; i < testsCount; i++) {
    cin >> m >> n;
    cout << sum(m, n) << "\n";
  }

  return 0;
}