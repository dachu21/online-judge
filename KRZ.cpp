// szkopul.edu.pl: dachu21

#include <iostream>

using namespace std;

struct point {
  long long int x;
  long long int y;
  long long int z;
};

point vectorProduct(point vectorA, point vectorB) {
  point product;
  product.x = vectorA.y * vectorB.z - vectorA.z * vectorB.y;
  product.y = vectorA.z * vectorB.x - vectorA.x * vectorB.z;
  product.z = vectorA.x * vectorB.y - vectorA.y * vectorB.x;
  return product;
}

bool isZero(point vector) {
  return (vector.x == 0 && vector.y == 0 && vector.z == 0);
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  point *points = new point[n];
  for (int i = 0; i < n; i++) {
    cin >> points[i].x;
    cin >> points[i].y;
    cin >> points[i].z;
  }

  if (n > 3) {

    point vectorAB, vectorBC, ABxBC;
    int i;
    for (int i = 2; i < n; i++) {

      vectorAB.x = points[i - 2].x - points[i - 1].x;
      vectorAB.y = points[i - 2].y - points[i - 1].y;
      vectorAB.z = points[i - 2].z - points[i - 1].z;
      vectorBC.x = points[i - 1].x - points[i].x;
      vectorBC.y = points[i - 1].y - points[i].y;
      vectorBC.z = points[i - 1].z - points[i].z;
      ABxBC = vectorProduct(vectorAB, vectorBC);
      if (!isZero(ABxBC)) {
        break;
      }
    }

    long long int d = -points[i].x * ABxBC.x - points[i].y * ABxBC.y - points[i].z * ABxBC.z;

    for (int j = 0; j < n; j++) {
      if ( ABxBC.x * points[j].x + ABxBC.y * points[j].y + ABxBC.z * points[j].z + d == 0) {
        continue;
      } else {
        cout << "NIE";
        return 0;
      }
    }
  }

  cout << "TAK";
  return 0;
}