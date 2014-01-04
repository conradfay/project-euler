#include "graph.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

void Graph::addAdjacency(node_handle A, node_handle B) {
  adjList[A].push_back(B);
} /* Graph::addAdjacency */

node_handle Graph::addNode() {

  Node node;
  nodes.push_back(node);
  node_handle nodeHandle = nodes.size() - 1;
  std::vector<node_handle> vector;
  adjList[nodeHandle] = vector;
  return nodeHandle;

} /* Graph::addNode */

long long Graph::countPaths() {

  // Use BFS to search all paths from first to last node.
  std::queue<node_handle> nodeQueue;
  long long count = 0;
  // Queue first node.
  nodeQueue.push(0);
  while (!nodeQueue.empty()) {
    node_handle nodeHandle = nodeQueue.front();
    nodeQueue.pop();
    //std::cout << "node handle: " << nodeHandle << std::endl;

    if (nodeHandle == nodes.size() - 1)
      count++;

    const Node& node = nodes[nodeHandle];
    for (unsigned int adjNode = 0; adjNode < adjList[nodeHandle].size(); adjNode++) {
      nodeQueue.push(adjList[nodeHandle][adjNode]);
    }
  }

  return count;

} /* Graph::countPaths */

void Graph::printAdjList() {

  for (node_handle node = 0; node < nodes.size(); node++) {
    std::cout << node << ": ";
    std::vector<node_handle> adjacencies = adjList[node];
    for (unsigned int adjNode = 0; adjNode < adjacencies.size(); adjNode++)
      std::cout << adjacencies[adjNode] << ", ";
    std::cout << std::endl;
  }

} /* Graph::printAdjList */
