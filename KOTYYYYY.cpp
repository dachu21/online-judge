// pl.spoj.com: dachu21

#include <iostream>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testCount, firstAge, firstLoc, secondAge, secondLoc;
  cin >> testCount;
  for (int i = 0; i < testCount; i++) {
    cin >> firstAge >> firstLoc >> secondAge >> secondLoc;
    int fieldsBetween = abs(firstLoc - secondLoc) - 1;
    if (fieldsBetween % 3 == 0) {
      if (firstAge > secondAge) {
        cout << 0 << "\n";
      } else {
        cout << 1 << "\n";
      }
    } else {
      if (firstAge > secondAge) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    }
  }

  return 0;
}