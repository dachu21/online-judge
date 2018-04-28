// codeforces.com: dachu21c

#include <iostream>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  short tabsNumber, position, leftBound, rightBound;
  cin >> tabsNumber >> position >> leftBound >> rightBound;
  short a = 1, b = tabsNumber;

  bool tabsToCloseOnLeft = (leftBound != a);
  bool tabsToCloseOnRight = (rightBound != b);
  int seconds = 0;
  if (tabsToCloseOnLeft && tabsToCloseOnRight) {
    if (abs(position - leftBound) < abs(rightBound - position)) {
      seconds += (abs(position - leftBound)) + (abs(rightBound - leftBound)) + 2;
    } else {
      seconds += (abs(rightBound - position)) + (abs(rightBound - leftBound)) + 2;
    }
  } else if (tabsToCloseOnLeft) {
    seconds += (abs(position - leftBound)) + 1;
  } else if (tabsToCloseOnRight) {
    seconds += (abs(rightBound - position)) + 1;
  }
  cout << seconds;

  return 0;
}