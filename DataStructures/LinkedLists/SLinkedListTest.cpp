
#include <iostream>
#include "include/SLinkedList.h"
// Include the SLinkedList definition here

int main() {
    SLinkedList<int> list;

    // Append elements to the list
    list.append(10);
    list.append(20);
    list.append(30);
    std::cout << "List after appending 10, 20, 30: ";
    list.print(SLinkedList<int>::defaultPrint);

    // Prepend elements to the list
    list.prepend(5);
    std::cout << "List after prepending 5: ";
    list.print(SLinkedList<int>::defaultPrint);

    // Insert at a specific index
    list.insertAt(15, 2); // Insert 15 at index 2
    std::cout << "List after inserting 15 at index 2: ";
    list.print(SLinkedList<int>::defaultPrint);

    // Remove an element by value
    list.remove(20);
    std::cout << "List after removing 20: ";
    list.print(SLinkedList<int>::defaultPrint);

    // Remove an element by index
    list.removeAt(1); // Remove element at index 1
    std::cout << "List after removing element at index 1: ";
    list.print(SLinkedList<int>::defaultPrint);

    // Get an element at a specific index
    try {
        int value = list.get(1);
        std::cout << "Element at index 1: " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Check the length of the list
    std::cout << "Current list length: " << list.length() << std::endl;

    // Check if the list is empty
    std::cout << "Is the list empty? " << (list.isEmpty() ? "Yes" : "No") << std::endl;

    // Reverse the list
    list.reverse();
    std::cout << "List after reversing: ";
    list.print(SLinkedList<int>::defaultPrint);

    return 0;
}

