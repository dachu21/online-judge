// spoj.com: dachu21

#include <iostream>
#include <algorithm>

using namespace std;

long long getFactorial(long long number) {
  static bool firstTime = true;
  static long long factorials[16];
  if (firstTime) {
    factorials[0] = 1;
    for (int i = 1; i < 16; i++) {
      factorials[i] = i * (factorials[i - 1]);
    }
    firstTime = false;
  }
  return factorials[number];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long testsCount, inputDistance;
  string word, wordSorted;

  cin >> testsCount;
  for (int i = 0; i < testsCount; i++) {
    cin >> word >> inputDistance;

    wordSorted = word;
    sort(wordSorted.begin(), wordSorted.end());

    long long startTotalDistance = 0;
    for (int j = 0; j < word.size(); j++) {
      long long letterDistance;
      for (letterDistance = 0; word[j] != wordSorted[letterDistance]; letterDistance++) {};
      wordSorted.erase(letterDistance, 1);
      startTotalDistance += letterDistance * getFactorial(word.size() - j - 1);
    }
    inputDistance = inputDistance + startTotalDistance;

    string result;
    sort(word.begin(), word.end());
    while (!word.empty()) {
      long long f = getFactorial(word.size() - 1);
      long long i = inputDistance / f;
      char x = word[i];
      inputDistance = inputDistance % f;
      result.append(1, x);
      word.erase(i, 1);
    }

    cout << result << "\n";
  }

  return 0;
}