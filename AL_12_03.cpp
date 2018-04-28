// pl.spoj.com: dachu21

#include <iostream>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n, p;
  bool aliceTurn;
  while (cin >> n) {
    p = 1;
    aliceTurn = true;
    do {
      if (aliceTurn)
        p *= 9;
      else
        p *= 2;
      aliceTurn = !aliceTurn;
    } while (p < n);
    if (aliceTurn)
      cout << "B\n";
    else
      cout << "A\n";
  }

  return 0;
}