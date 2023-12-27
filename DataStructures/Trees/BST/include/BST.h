#pragma once
#include <iostream>
#include <stdexcept>
#include <vector>


template <typename T>
class BST {
private:

  enum RemoveCase {
    LEAF,
    LEFTSUB,
    RIGHTSUB,
    BOTH,
  };


 
  struct Node {
    T value;
    Node* left;
    Node* right;
    Node(T data): value(data), left(nullptr), right(nullptr){}
  };

  Node* root;

public:
  BST(): root(nullptr) {
  }


  ~BST() {
    clear();  // Reuse the clear function to delete all nodes
  }


    // Function to clear all nodes in the BST
    void clear() {
        clearHelper(root);
    }

    // Helper function for clear
    void clearHelper(Node* node) {
        if (node != nullptr) {
            clearHelper(node->left);  // Recursively clear the left subtree
            clearHelper(node->right); // Recursively clear the right subtree
            delete node;              // Delete the current node
        }
    }



    void print(){
      int h = height();
    }

    void printHelper(){

    }

  //============Insert================

  void insertHelper(Node*& node, T value){
    //Base case, we have reached the bottom of the bst
    if(node == nullptr){
      //Set node with value
      node = new Node(value);
      return;
    }

    //Recursion
    if(value < node->value){
      insertHelper(node->left,  value);
    } else {
      insertHelper(node->right,  value);

    }
  }

  // Public function to insert a value into the BST
  void insert(T value){
    insertHelper(root, value);
  }








  //============Remove================

  // Public function to remove a value from the BST
  void remove(T data){
    removeHelper(root, data);
  }


  // Determines the type of removal case for a node
  RemoveCase getRemoveCase(Node* node){
    if(node->left == nullptr && node->right == nullptr) return LEAF;
    if(node->left != nullptr && node->right == nullptr) return LEFTSUB;
    if(node->left == nullptr && node->right != nullptr) return RIGHTSUB;
    if(node->left != nullptr && node->right != nullptr) return BOTH;
    throw std::runtime_error("Invalid node structure in BST.");
  }

  void removeHelper(Node*& node, T value){
    //Value does note exists in bst
    if(node == nullptr){
      throw std::runtime_error("BST remove: value does not exist");
    }

    if(node->value == value){
      typename BST<T>::RemoveCase removeCase = getRemoveCase(node);

      if(removeCase == LEAF){
        delete node;
        node = nullptr; 
      }

      if(removeCase == LEFTSUB){
        Node* temp = node;
        node = node->left;
        delete temp;
      }

      if(removeCase == RIGHTSUB){
        Node* temp = node;
        node = node->right;
        delete temp;
      }

      if(removeCase == BOTH){
        //Find succesor
        //Either smallest in right subtree
        //Or largest in left subtree
        
        //Left do the smallest in the right
        Node* successor = node->right;
        while(successor->left != nullptr){
          successor = successor->left;
        }

        //Replace value
        node->value = successor->value;

        //Remove successor from tree
        removeHelper(node->right, successor->value);
      }
     
      //Dont search anymore
      return;

    }


    //Recursion to find node with value
    if(value < node->value){
      removeHelper(node->left,  value);
    } else {
      removeHelper(node->right,  value);

    }
  }





  //============Traverse================
  
  enum TraversalType{
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER,
    DEPTH_ORDER
  };

  void traverse(TraversalType type){

    if(type == IN_ORDER) inOrderTraversal(root);

    std::cout << "\n";
  }
  

 // Helper function for in-order traversal
  void inOrderTraversal(Node* node){
    if(node != nullptr){

    inOrderTraversal(node->left);
    std::cout << node->value << " ";
    inOrderTraversal(node->right); 
    }
  }

    void toSortedArray(Node* node, std::vector<T>& nodes){
      if(node == nullptr) return; //Base Case
                                  
      //InOrder traverse into array which would make it sorted
      toSortedArray(node->left, nodes);
      nodes.push_back(node->value);
      toSortedArray(node->right, nodes);

    }  

    // Rebalance the BST
    void balance(){
      std::vector<T> nodeValues;
      toSortedArray(root, nodeValues);


      //Deletes Tree
      clear();

      //Add new tree
      root = buildTreeFromArray(nodeValues, 0, nodeValues.size() - 1);


    };

    Node* buildTreeFromArray(std::vector<T>& nodeValues, int start, int end){
      //Base Case
      if(start > end) return nullptr;

      //Get Middle element in range, to be used at root of tree or subtree
      int mid = (start + end) / 2;
      Node* newRoot = new Node(nodeValues[mid]);


      newRoot->left = nullptr;  // Reset left child
      newRoot->right = nullptr; // Reset right child

      //Recursily construct new balanced bst
      newRoot->left = buildTreeFromArray(nodeValues, start, mid - 1);
      newRoot->right = buildTreeFromArray(nodeValues, mid + 1, end);

      return newRoot;
    }

    // Find function to search for a value in the BST
    Node* find(T value) const {
      return findHelper(root, value);
    };

    Node* findHelper(Node* node, T value){
    //Base case, we have reached the bottom of the bst
    if(node == nullptr){
      //No node with the value found
      return nullptr;
    }

    if(node->value == value){
      return node;
    }

    //Recursion
    if(value < node->value){
      findHelper(node->left,  value);
    } else {
      findHelper(node->right,  value);

    }

    }

    // Retrieve the minimum value in the BST
    T findMin()  {
      return findMinHelper(root);
    };

    T findMinHelper(Node* node){
     //Base case, we have reached the bottom of the bst
     if(node->left == nullptr){
        //Lowest value
        return node->value;
     }

      //Recursion
      findMinHelper(node->left);

    }

    // Retrieve the maximum value in the BST
    T findMax() {
      return findMaxHelper(root);
    };


    T findMaxHelper(Node* node){
    //Base case, we have reached the bottom of the bst
    if(node->right == nullptr){
      //Highest value
      return node->value;
    }

    //Recursion
    findMaxHelper(node->right);

    }

    // Returns the number of nodes in the BST
    size_t size() const;

    int height(){
      return heightHelper(root);
    }

    // Calculates the height of a given node. It does this by calculating the height 
    // of the left and right subtrees of the node and then adding 1 (to account for 
    // the current node). If the node is nullptr, it means we've reached beyond the 
    // leaf nodes, and it returns 0.
    int heightHelper(Node* node) {
      if(node == nullptr) return 0;

      int left_height = heightHelper(node->left);
      int right_height = heightHelper(node->right);

      return std::max(left_height, right_height) + 1;
    };
};
