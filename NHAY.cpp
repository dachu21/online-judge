// pl.spoj.com: dachu21

#include <iostream>

using namespace std;

void buildTableT(int *T, int &needleLength, string &needle) {
  T[0] = -1;
  for (int i = 0; i < needleLength; i++) {
    T[i + 1] = T[i];
    while (T[i + 1] > -1 && needle[T[i + 1]] != needle[i]) {
      T[i + 1] = T[T[i + 1]];
    }
    T[i + 1]++;
  }
}

void kmp(int *T, int &needleLength, string &needle, string &haystack) {
  int s = 0;
  for (int i = 0; i < haystack.length(); i++) {
    while (s > -1 && haystack[i] != needle[s]) {
      s = T[s];
    }
    s++;
    if (s == needleLength) {
      s = T[needleLength];
      cout << i - needleLength + 1 << "\n";
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int needleLength;
  string needle, haystack;
  while (cin >> needleLength >> needle >> haystack) {
    int T[needleLength + 1];
    buildTableT(T, needleLength, needle);
    kmp(T, needleLength, needle, haystack);
    cout << "\n";
  }

  return 0;
}