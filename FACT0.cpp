// spoj.com: dachu21

#include <iostream>
#include <cmath>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long number, k, kCount;

  cin >> number;
  while (number != 0) {
    k = 2;
    while (number > 1 && k <= sqrt(number)) {
      kCount = 0;
      while (number % k == 0) {
        number /= k;
        kCount++;
      }
      if (kCount > 0) {
        cout << k << "^" << kCount << " ";
      }
      k++;
    }
    if (number > 1) {
      cout << number << "^1";
    }
    cout << "\n";

    cin >> number;
  }

  return 0;
}