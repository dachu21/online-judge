// pl.spoj.com: dachu21

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip>

using namespace std;

struct Sheep {

  int x;
  int y;
  int number;

  Sheep(int x, int y, int number) : x(x), y(y), number(number) {}

  // FOR SORTING
  bool operator<(const Sheep &s) const {
    if (y < s.y)
      return true;
    if (y == s.y)
      if (x < s.x)
        return true;
    return false;
  }

  // FOR SET
  bool operator==(const Sheep &s) const {
    return y == s.y && x == s.x;
  }
};

double calculateLength(Sheep a, Sheep b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int calculateCrossProduct(Sheep o, Sheep a, Sheep b) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<Sheep> getSheepsVector() {

  int x, y, sheepsCount;

  cin >> sheepsCount;
  set<Sheep> sheepsInput;

  for (int i = 0; i < sheepsCount; i++) {
    cin >> x >> y;
    sheepsInput.insert(Sheep(x, y, i + 1));
  }

  vector<Sheep> sheepsVector(sheepsInput.begin(), sheepsInput.end());
  sheepsInput.clear();

  return sheepsVector;
}

void buildTheFence() {

  vector<Sheep> sheeps = getSheepsVector();

  // OUTPUT (if only one sheep)
  if (sheeps.size() == 1) {
    cout << "0.00\n1\n\n";
    return;
  }

  // ALGORITHM
  sort(sheeps.begin(), sheeps.end());

  vector<int> corners(2 * sheeps.size());

  int k = 0;
  for (int i = 0; i < sheeps.size(); i++) {
    while (k >= 2 &&
        calculateCrossProduct(sheeps[corners[k - 2]], sheeps[corners[k - 1]], sheeps[i]) <= 0) {
      k--;
    }
    corners[k++] = i;
  }
  for (int i = sheeps.size() - 2, t = k + 1; i >= 0; i--) {
    while (k >= t &&
        calculateCrossProduct(sheeps[corners[k - 2]], sheeps[corners[k - 1]], sheeps[i]) <= 0) {
      k--;
    }
    corners[k++] = i;
  }

  corners.resize(k - 1);

  // CALCULATING LENGTH
  double totalLength = 0;
  int previous = corners[0];
  for (int i = 1; i < corners.size(); i++) {
    totalLength += calculateLength(sheeps[corners[i]], sheeps[previous]);
    previous = corners[i];
  }
  totalLength += (calculateLength(sheeps[corners[0]], sheeps[corners[corners.size() - 1]]));

  // OUTPUT
  cout << setprecision(2) << fixed << totalLength << "\n";
  for (int corner : corners) {
    cout << sheeps[corner].number << " ";
  }
  cout << "\n\n";

  sheeps.clear();
  corners.clear();
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testsCount;
  cin >> testsCount;
  for (int i = 0; i < testsCount; i++) {
    buildTheFence();
  }

  return 0;
}