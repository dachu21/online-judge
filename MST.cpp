// pl.spoj.com: dachu21

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int nodeI;
  int nodeJ;
  int weight;

  Edge(int nodeI, int nodeJ, int weight) {
    this->nodeI = nodeI;
    this->nodeJ = nodeJ;
    this->weight = weight;
  }
  bool operator<(const Edge &e) const {
    return weight < e.weight;
  }
};

int findFunc(int node, vector<int> &parents) {
  if (parents[node] == 0) {
    return node;
  } else {
    return findFunc(parents[node], parents);
  }
}

int unionFunc(int nodeI, int nodeJ, vector<int> &parents) {
  nodeI = findFunc(nodeI, parents);
  nodeJ = findFunc(nodeJ, parents);
  if (nodeI != nodeJ) {
    parents[nodeI] = nodeJ;
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  unsigned int nodesNumber, edgesNumber;
  cin >> nodesNumber >> edgesNumber;

  vector<Edge> edges;
  edges.reserve(edgesNumber);
  for (int i = 0; i < edgesNumber; i++) {
    int nodeI, nodeJ, weight;
    cin >> nodeI >> nodeJ >> weight;
    edges.emplace_back(nodeI, nodeJ, weight);
  }
  sort(edges.begin(), edges.end());

  vector<int> parents;
  parents.resize(nodesNumber + 1);

  int nodeI, nodeJ, weight;
  long long totalWeight = 0;
  for (int i = 0; i < edgesNumber; i++) {
    weight = edges[i].weight;
    nodeI = edges[i].nodeI;
    nodeJ = edges[i].nodeJ;
    if (findFunc(nodeI, parents) != findFunc(nodeJ, parents)) {
      totalWeight += weight;
      unionFunc(nodeI, nodeJ, parents);
    }
  }

  cout << totalWeight;

  return 0;
}