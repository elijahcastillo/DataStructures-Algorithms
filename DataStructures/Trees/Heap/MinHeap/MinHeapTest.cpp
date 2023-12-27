
#include <iostream>
#include "include/MinHeap.h" // Assuming your MinHeap class is in MinHeap.h

int main() {
    // Create a MinHeap instance of type int
    MinHeap<int> minHeap;

    // Insert elements into the heap
    std::cout << "Inserting elements into the heap...\n";
    minHeap.insert(10);
    minHeap.insert(4);
    minHeap.insert(9);
    minHeap.insert(1);
    minHeap.insert(7);
    minHeap.insert(5);

    std::cout << "Heap after insertion: ";
    minHeap.print();

    // Extracting the minimum element
    std::cout << "Extracting the minimum element: " << minHeap.extractMin() << std::endl;
    std::cout << "Heap after extracting minimum: ";
    minHeap.print();

    // Inserting more elements
    std::cout << "Inserting more elements...\n";
    minHeap.insert(2);
    minHeap.insert(8);

    std::cout << "Heap after more insertions: ";
    minHeap.print();

    // Deleting the minimum element
    std::cout << "Deleting the minimum element...\n";
    minHeap.deleteMinimum();

    std::cout << "Heap after deleting minimum: ";
    minHeap.print();

    return 0;
}

