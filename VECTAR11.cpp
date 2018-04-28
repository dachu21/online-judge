// spoj.com: dachu21

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1000000;
bool winners[MAX + 1] = {false};

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  for (int i = 1; i <= MAX; i++) {
    for (int j = 1; j <= sqrt(MAX); j++) {
      int index = i - j * j;
      if (index >= 0 && (index == 0 || !winners[index])) {
        winners[i] = true;
        break;
      }
    }
  }

  int testsCount, number;
  cin >> testsCount;
  for (int i = 0; i < testsCount; i++) {
    cin >> number;
    if (winners[number]) {
      cout << "Win\n";
    } else {
      cout << "Lose\n";
    }
  }

  return 0;
}