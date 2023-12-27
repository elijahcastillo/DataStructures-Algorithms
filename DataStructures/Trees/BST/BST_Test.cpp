
#include "include/BST.h"  // Assuming your BST implementation is in BST.h
#include <iostream>

int main() {
    BST<int> bst;

    // Inserting values
    bst.insert(40);
    bst.insert(20);
    bst.insert(60);
    bst.insert(10);
    bst.insert(30);
    bst.insert(50);
    bst.insert(70);

    // Display the tree in in-order traversal
    std::cout << "In-order traversal: ";
    bst.traverse(BST<int>::IN_ORDER);

    // Display the size and height of the tree
    std::cout << "Height of the tree: " << bst.height() << std::endl;

    // Find min and max value in the tree
    std::cout << "Minimum value: " << bst.findMin() << std::endl;
    std::cout << "Maximum value: " << bst.findMax() << std::endl;

    // Removing a value
    std::cout << "Removing 20 from the tree." << std::endl;
    bst.remove(20);

    // Display the tree after removal
    std::cout << "In-order traversal after removal: ";
    bst.traverse(BST<int>::IN_ORDER);

    // Balancing the tree
    std::cout << "Balancing the tree." << std::endl;
    bst.balance();

    // Display the tree after balancing
    std::cout << "In-order traversal after balancing: ";
    bst.traverse(BST<int>::IN_ORDER);

    // Display the size and height of the tree after balancing
    std::cout << "Height of the tree after balancing: " << bst.height() << std::endl;

    return 0;
}


