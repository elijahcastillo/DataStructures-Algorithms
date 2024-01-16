#include "../Graph.h"
#include "include/BFS.h"
#include "include/DFS.h"



int main(){
  Graph g;
  g.addEdge("A", "B");
  g.addEdge("A", "D");
  g.addEdge("D", "B");
  g.addEdge("D", "E");
  g.addEdge("B", "C");
  g.addEdge("E", "C");
  g.printGraph();

  Traversal::BFS(&g, "A");
  std::cout << "\n";
  Traversal::DFS(&g, "A");

}
