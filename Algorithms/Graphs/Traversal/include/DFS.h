
#pragma once
#include <stack>
#include <unordered_set>
#include "../../Graph.h"

namespace Traversal {

  // Perform BFS on a graph from a starting node
  void DFS(Graph* graph, std::string starting_node){
    std::stack<std::string> s; // Stack to manage the nodes to visit
    std::unordered_set<std::string> visited; // Set to keep track of visited nodes

    s.push(starting_node); // Start from the given node

    while(!s.empty()){
      std::string current_node = s.top();
      s.pop();

      if (visited.find(current_node) != visited.end()) {
          continue; // Skip if the node has already been visited
      }

      visited.insert(current_node); // Mark the current node as visited
      std::cout << current_node << " "; // Process the current node

      for(Node n : graph->list[current_node]){
        if (visited.find(n.name) == visited.end()) {
            s.push(n.name); // Add unvisited neighboring nodes to the queue
        }
      }
    }
  }


}
