#pragma once
#include <queue>
#include <unordered_set>
#include "../../Graph.h"

namespace Traversal {

  // Perform BFS on a graph from a starting node
  void BFS(Graph* graph, std::string starting_node){
    std::queue<std::string> q; // Queue to manage the nodes to visit
    std::unordered_set<std::string> visited; // Set to keep track of visited nodes

    q.push(starting_node); // Start from the given node

    while(!q.empty()){
      std::string current_node = q.front();
      q.pop();

      if (visited.find(current_node) != visited.end()) {
          continue; // Skip if the node has already been visited
      }

      visited.insert(current_node); // Mark the current node as visited
      std::cout << current_node << " "; // Process the current node

      for(Node n : graph->list[current_node]){
        if (visited.find(n.name) == visited.end()) {
            q.push(n.name); // Add unvisited neighboring nodes to the queue
        }
      }
    }
  }


}
