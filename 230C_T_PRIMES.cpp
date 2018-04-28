// codeforces.com: dachu21c

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long number) {
  if (number == 2) {
    return true;
  }
  if (number % 2 == 0 || number == 1) {
    return false;
  }
  for (int i = 3; i <= sqrt(number); i += 2) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  long long number;
  for (int i = 0; i < n; i++) {
    cin >> number;
    long long sqrtNumber = static_cast<long long>(sqrt(number));
    if (isPrime(sqrtNumber) && sqrtNumber * sqrtNumber == number) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}