// pl.spoj.com: dachu21

#define MAX_BUGS 2000
#define UNDEFINED (-1)
#define MALE 1
#define FEMALE 0

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool suspiciousFound;

void analyze(vector<int> interactions[], int genders[], int bugNumber) {
  for (int i = 0; i < interactions[bugNumber].size(); i++) {
    int numberOfBugInteractedWith = interactions[bugNumber][i];
    if (genders[numberOfBugInteractedWith] == UNDEFINED) {
      if (genders[bugNumber] == MALE) {
        genders[numberOfBugInteractedWith] = FEMALE;
      } else { // if (genders[bugNumber] == FEMALE)
        genders[numberOfBugInteractedWith] = MALE;
      }
      analyze(interactions, genders, numberOfBugInteractedWith);
    } else if (genders[bugNumber] == genders[numberOfBugInteractedWith]) {
      suspiciousFound = true;
      return;
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testsCount;
  cin >> testsCount;
  for (int i = 0; i < testsCount; i++) {
    suspiciousFound = false;
    int bugsNumber, interactionsNumber;
    cin >> bugsNumber >> interactionsNumber;

    vector<int> interactions[MAX_BUGS + 1];
    int genders[MAX_BUGS + 1];
    memset(genders, UNDEFINED, sizeof(genders));

    for (int i = 1; i <= interactionsNumber; i++) {
      int bug1, bug2;
      cin >> bug1 >> bug2;
      interactions[bug1].push_back(bug2);
      interactions[bug2].push_back(bug1);
    }

    for (int bugNumber = 1; bugNumber <= bugsNumber && !suspiciousFound; bugNumber++) {
      if (genders[bugNumber] == UNDEFINED) {
        genders[bugNumber] = MALE;
        analyze(interactions, genders, bugNumber);
      }
    }

    cout << "Scenario #" << i + 1 << ":\n";
    if (suspiciousFound) {
      cout << "Suspicious bugs found!\n";
    } else {
      cout << "No suspicious bugs found!\n";
    }
  }

  return 0;
}