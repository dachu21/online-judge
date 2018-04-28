// pl.spoj.com: dachu21

#include <iostream>
#include <cmath>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testCount;
  double a, b, c, d;
  cin >> testCount;

  for (int i = 0; i < testCount; i++) {

    cin >> a >> b >> c >> d;

    if (c < d) {
      swap(c, d);
    }
    if (a < b) {
      swap(a, b);
    }

	if (c < a && d < b) {
      cout << "TAK\n";
      continue;
    }
	if (c == a && d == b) {
      cout << "NIE\n";
      continue;
    }
    
    if (b > (2 * (c * d * a) + (c * c - d * d) * sqrt(c * c + d * d - a * a)) / (c * c + d * d)) {
      cout << "TAK\n";
      continue;
    }
    cout << "NIE\n";
  }

  return 0;
}