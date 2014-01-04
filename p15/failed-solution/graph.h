#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <map>
#include <vector>

class Node {
  
};

typedef unsigned int node_handle;

class Graph {
  public:
    void addAdjacency(node_handle A, node_handle B);
    node_handle addNode();
    long long countPaths();
    void printAdjList();
    std::map< node_handle, std::vector<node_handle> > adjList;
    std::vector< Node > nodes;
};

#endif /* GRAPH_H */

