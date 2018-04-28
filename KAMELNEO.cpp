// pl.spoj.com: dachu21

#include <iostream>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int humpsCount, queriesCount, humpNumber, impulseNumber, answer;

  cin >> humpsCount;
  int *A = new int[humpsCount + 1];
  for (int i = 1; i <= humpsCount; i++) {
    cin >> A[i];
  }
  cin >> queriesCount;
  while (queriesCount--) {
    cin >> humpNumber >> impulseNumber;

    answer = humpNumber;
    for (int i = 1; i <= impulseNumber;) {
      answer = A[answer];
      if (answer == humpNumber) {
        i += ((impulseNumber - i) / i) * i + 1;
      } else {
        i++;
      }
    }

    cout << answer << "\n";
  }

  return 0;
}