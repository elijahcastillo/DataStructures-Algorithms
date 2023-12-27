
#pragma once
#include "MinHeap.h"

template <typename T>
class PriorityQueue {
private:
    MinHeap<T> minHeap;

public:
    PriorityQueue(size_t initialSize = 10) : minHeap(initialSize) {}

    void enqueue(T value) {
        // Insert the value into the min heap.
        minHeap.insert(value);
    }

    T dequeue() {
        // Extract the minimum value (highest priority) from the min heap.
        return minHeap.extractMin();
    }

    T peek() {
        // Get the minimum value (highest priority) without removing it.
        return minHeap.peek();
    }

    size_t size() {
        // Return the current size of the priority queue.
        return minHeap.size();
    }

    bool isEmpty() {
        // Check if the priority queue is empty.
        return size() == 0;
    }

    void print() {
        // Print all elements in the priority queue.
        minHeap.print();
    }
};
