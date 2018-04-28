// adjule.pl: dachu21

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {

  short x;
  short y;

  Point(short x, short y) : x(x), y(y) {}

  bool operator<(const Point &p) const {
    if (x < p.x)
      return true;
    if (x == p.x)
      if (y < p.y)
        return true;
    return false;
  }
};

int calculateDistance(Point a, Point b) {

  short xDiff = static_cast<short>(abs(a.x - b.x));
  short yDiff = static_cast<short>(abs(a.y - b.y));
  xDiff = min(xDiff, static_cast<short>(4000 - xDiff));
  yDiff = min(yDiff, static_cast<short>(4000 - yDiff));
  return xDiff * xDiff + yDiff * yDiff;
}

void findClosestPoints() {

  short n, x, y;
  cin >> n;
  vector<Point> points;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    points.emplace_back(x, y);
  }
  sort(points.begin(), points.end());

  int minDistance = calculateDistance(points[0], points[1]);
  Point first = points[0];
  Point second = points[1];

  for (int i = 0; i < points.size() - 1; i++) {
    for (int j = i + 1; j < points.size(); j++) {
      int distance = calculateDistance(points[i], points[j]);
      if (distance < minDistance) {
        minDistance = distance;
        first = points[i];
        second = points[j];
      }
    }
  }

  cout << first.x << " " << first.y << " " << second.x << " " << second.y << "\n";

  points.clear();
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  short testsCount;
  cin >> testsCount;
  for (int i = 0; i < testsCount; i++) {
    findClosestPoints();
  }

  return 0;
}