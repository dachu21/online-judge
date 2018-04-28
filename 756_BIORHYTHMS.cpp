// uva.onlinejudge.org.com: dachu21

#include <iostream>

using namespace std;

const int P_LENGTH = 23, E_LENGTH = 28, I_LENGTH = 33;

int mod(int a, int n) {
  while (a < 0) {
    a += n;
  }
  return a % n;
}

int euclidean(int b, int n) {
  int a = n;
  long int x1 = 0, x2 = 1, q;

  while (true) {
    q = a / b;
    a %= b;
    if (a == 0) {
      return mod(x2, n);
    }
    x1 -= q * x2;

    q = b / a;
    b %= a;
    if (b == 0) {
      return mod(x1, n);
    }
    x2 -= q * x1;
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int lenghtsProduct = P_LENGTH * E_LENGTH * I_LENGTH;

  int pMinusProduct = E_LENGTH * I_LENGTH;
  int eMinusProduct = P_LENGTH * I_LENGTH;
  int iMinusProduct = P_LENGTH * E_LENGTH;

  int pEuclidean = euclidean(pMinusProduct, P_LENGTH);
  int eEuclidean = euclidean(eMinusProduct, E_LENGTH);
  int iEuclidean = euclidean(iMinusProduct, I_LENGTH);

  int pMod = mod(pMinusProduct * pEuclidean, lenghtsProduct);
  int eMod = mod(eMinusProduct * eEuclidean, lenghtsProduct);
  int iMod = mod(iMinusProduct * iEuclidean, lenghtsProduct);

  int p, e, i, d, result, caseCount = 1;

  while (cin >> p >> e >> i >> d && !(p == -1 && e == -1 && i == -1 && d == -1)) {
    result = p * pMod + e * eMod + i * iMod - d;
    result = mod(result, lenghtsProduct);

    cout << "Case " << caseCount++ << ": the next triple peak occurs in "
         << (result ? result : lenghtsProduct) << " days.\n";
  }

  return 0;
}