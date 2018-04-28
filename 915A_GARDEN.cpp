// codeforces.com: dachu21c

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  short bucketsNumber, gardenLength, segmentLength;
  vector<int> buckets;

  cin >> bucketsNumber >> gardenLength;
  for (int i = 0; i < bucketsNumber; i++) {
    cin >> segmentLength;
    buckets.push_back(segmentLength);
  }
  sort(buckets.begin(), buckets.end());

  for (int i = bucketsNumber-1; i >=0; i--) {
    if (gardenLength % buckets[i] == 0) {
      cout << gardenLength / buckets[i];
      return 0;
    }
  }

  return 0;
}