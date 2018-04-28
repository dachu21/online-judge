// pl.spoj.com: dachu21

#define MAX_NODES 10000

#include <iostream>
#include <vector>
#include <cstring>

int deepestNode = 0;
int maxDepth = 0;

using namespace std;

void dfs(int currentNode, int currentDepth, vector<int> treeEdges[], bool visitedNodes[]) {
  visitedNodes[currentNode] = true;
  if (currentDepth > maxDepth) {
    maxDepth = currentDepth;
    deepestNode = currentNode;
  }
  for (int i = 0; i < treeEdges[currentNode].size(); i++) {
    if (!visitedNodes[treeEdges[currentNode][i]]) {
      dfs(treeEdges[currentNode][i], currentDepth + 1, treeEdges, visitedNodes);
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int nodesNumber;
  vector<int> treeEdges[MAX_NODES + 1];
  bool visitedNodes[MAX_NODES + 1];

  cin >> nodesNumber;
  for (int i = 0; i < nodesNumber - 1; i++) {
    int node1, node2;
    cin >> node1 >> node2;
    treeEdges[node1].push_back(node2);
    treeEdges[node2].push_back(node1);
  }

  dfs(1, 0, treeEdges, visitedNodes);
  memset(visitedNodes, false, sizeof(visitedNodes));
  dfs(deepestNode, 0, treeEdges, visitedNodes);

  cout << maxDepth;

  return 0;
}