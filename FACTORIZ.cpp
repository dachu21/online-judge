// pl.spoj.com: dachu21

#include <iostream>
#include <cmath>

using namespace std;

int MAX_VALUE = 8000000;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int number, numbersCount;

  int * sieve = new int[MAX_VALUE+1];
  int maxPrime = (int)sqrt(MAX_VALUE);

  for (int i = 0; i <= MAX_VALUE; i++) {
    sieve[i] = i;
  }

  for (int i = 2; i <= maxPrime; i++ ) {
    if (sieve[i] == i) {
      for (int j = i*i; j <= MAX_VALUE; j += i) {
        if (sieve[j] == j) {
          sieve[j] = i;
        }
      }
    }
  }

  cin >> numbersCount;
  while (numbersCount--) {
    cin >> number;
    if (number <= 3) {
      cout << number << "\n";
    } else {
      while (number != 1) {
        cout << sieve[number];
        number /= sieve[number];
        if (number != 1) {
          cout << "*";
        } else {
          cout << "\n";
        }
      }
    }
  }

  return 0;
}