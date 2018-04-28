// codeforces.com: dachu21

#include <iostream>
#include <map>

using namespace std;

map<char, bool> getLettersMap() {
  map<char, bool> lettersMap =
      {{'A', false}, {'B', false}, {'C', false}, {'D', false}, {'E', false}, {'F', false},
       {'G', false}, {'H', false}, {'I', false}, {'J', false}, {'K', false}, {'L', false},
       {'M', false},
       {'N', false}, {'O', false}, {'P', false}, {'Q', false}, {'R', false}, {'S', false},
       {'T', false}, {'U', false}, {'V', false}, {'W', false}, {'X', false}, {'Y', false},
       {'Z', false}};
  return lettersMap;
};

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const int MOD = 1000000007;
  long long combination = 1;

  short wordsCount, lettersCount;
  cin >> wordsCount >> lettersCount;

  char **lettersPositions = new char *[wordsCount];
  for (int word = 0; word < wordsCount; word++) {
    lettersPositions[word] = new char[lettersCount];
  }

  for (int word = 0; word < wordsCount; word++) {
    cin >> lettersPositions[word];
  }

  for (int position = 0; position < lettersCount; position++) {
    map<char, bool> lettersAlreadyPresent = getLettersMap();
    short possibleLettersCount = 0;
    for (int word = 0; word < wordsCount; word++) {
      if (!lettersAlreadyPresent.at(lettersPositions[word][position])) {
        possibleLettersCount++;
        lettersAlreadyPresent.at(lettersPositions[word][position]) = true;
      }
    }
    combination = (combination * possibleLettersCount) % MOD;
  }

  cout << combination;

  return 0;
}