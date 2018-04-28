// pl.spoj.com: dachu21

#include <iostream>

using namespace std;

struct trieNode {
  trieNode *next[10] = {NULL};
  bool end = false;
};

void deleteTrie(trieNode *node) {
  if (node->end) {
    delete node;
  } else {
    for (int i = 0; i < 10; i++) {
      if (node->next[i] != NULL) {
        deleteTrie(node->next[i]);
      }
    }
    delete node;
  }
}

void checkConsistency() {

  int n, digit;
  bool isConsistent;
  string phoneNumber;

  cin >> n;
  isConsistent = true;
  trieNode *head = new trieNode;
  trieNode *tail;
  for (int i = 0; i < n; i++) {
    cin >> phoneNumber;
    if (isConsistent) {
      tail = head;
      for (int j = 0; j < phoneNumber.size(); j++) {
        if (tail->end) {
          isConsistent = false;
          break;
        }
        digit = phoneNumber[j] - '0';
        if (tail->next[digit] == NULL) {
          tail->next[digit] = new trieNode;
        }
        tail = tail->next[digit];
      }
      tail->end = true;
      for (int j = 0; j < 10; j++) {
        if (tail->next[j]) {
          isConsistent = false;
          break;
        }
      }
    }
  }
  if (isConsistent) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  deleteTrie(head);
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int testsCount;
  cin >> testsCount;
  for (int i = 0; i < testsCount; i++) {
    checkConsistency();
  };

  return 0;
}