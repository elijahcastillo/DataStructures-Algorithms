#pragma once
#include <iostream>


template <typename T>
class MinHeap {
  
  T* heap;
  size_t heap_size;
  size_t heap_capacity;

  //Stored as an array
  // Current node = heap[i]
  // Parent Node = heap[(i-1) / 2]
  // Left Child = arr[(2*i) + 1]
  // Right Child = arr[(2*i) + 2]
  // Root is heap[0]
  //
  //

  public:
  
  MinHeap(size_t initalSize = 10): heap_capacity(initalSize), heap_size(0) {
    heap = new T[heap_capacity];
  }

  ~MinHeap(){
    delete[] heap;
  }

  void resize(){
    size_t newCapacity = heap_capacity * 2;
    T* newHeap = new T[newCapacity];

    //Copy values from old array
    for(int i = 0; i < heap_size; i++){
      newHeap[i] = heap[i];
    }

    delete[] heap;
    heap = newHeap;
    heap_capacity = newCapacity;
  }


  size_t parent(size_t index){
    return (index - 1) / 2;
  }

  size_t leftChild(size_t index){
    return (2 * index) + 1;
  }

  size_t rightChild(size_t index){
    return (2 * index) + 2;
  }

  void swapNodes(size_t node1, size_t node2){
    T temp = heap[node1];
    heap[node1] = heap[node2];
    heap[node2] = temp;
  }

  void insert(T value){

    //Resize to prevent overflow
    if(heap_size >= heap_capacity){
      resize();
    }

    //Insert at bottom of tree
    heap[heap_size] = value;

    //Keep swaping untill its in the right spot (recursivly)
    insertHelper(heap_size);


    heap_size++;
  }

  void insertHelper(size_t currentNode){

    //Base case: If at root && parent of node is not greater than it
    if(currentNode <= 0 || heap[parent(currentNode)] < heap[currentNode]){
      return;
    }

    //Move node up tree
    swapNodes(currentNode, parent(currentNode));

    //Recursivly move up the tree
    insertHelper(parent(currentNode));
  }

/* This function takes in an element index index, and maintains 
 * the min heap propertyby swapping with the smallest element of 
 * its immediate sub-tree or entire tree if the index is 0 which would 
 * mean the subtree is the entire tree
*/
  void maintainHeap(size_t node){
  // Before maintainHeap(0)
  //
  //      6 
  //    /  \
  //   5    4 
  //  / \
  // 8   7   
  //
  // After
  //
  //      4 
  //    /  \
  //   5    6 
  //  / \
  // 8   7   

  size_t smallestNodeInSubtree = node; //Start at node, find smallest
  size_t left = leftChild(node);
  size_t right = rightChild(node);

  //Find smallest in subtree
  if(left < heap_size && heap[left] < heap[smallestNodeInSubtree]){
    smallestNodeInSubtree = left;
  }

  if(right < heap_size && heap[right] < heap[smallestNodeInSubtree]){
    smallestNodeInSubtree = right;
  }

  // If the smallest node is not the current node, swap them
  if (smallestNodeInSubtree != node) {
    swapNodes(node, smallestNodeInSubtree);

    //Recursively ensure min-heap property going into more subtrees
    maintainHeap(smallestNodeInSubtree); 
  }

    
  }

  //Deletes root of heap, which is the min value
  void deleteMinimum(){
    if(heap_size == 0){
      //Cannot remove from empty heap
      return;
    }

    // Replace the root with the last element in the heap
    heap[0] = heap[heap_size - 1];

    // Decrease the heap size
    heap_size--;

    // Reorganize the heap starting from the root
    maintainHeap(0);
  }

  //Look at the min element in heap
  T peek(){
    return heap[0]; //Root
  }

  //Get and remove min element from heap;
  T extractMin(){
    T min = peek();
    deleteMinimum();
    return min;
  };


  // Build a heap from an unsorted array
  void heapify(T* array, size_t arraySize) {
      if (array == nullptr || arraySize == 0)
          return;

      // Allocate memory for heap
      if (heap != nullptr)
          delete[] heap;

      heap = new T[arraySize];
      heap_size = heap_capacity = arraySize;

      // Copy array elements to heap
      for (size_t i = 0; i < arraySize; ++i) {
          heap[i] = array[i];
      }

      // Start heapify from the last non-leaf node
      // In a complete binary tree, the last non-leaf
      // node can be found at index (n/2) - 1, where n 
      // is the number of elements.
      for (int i = (heap_size / 2) - 1; i >= 0; --i) {
          heapify(i);
      }
  }


  size_t size(){
    return heap_size;
  }



  void print(){
    for(int i = 0; i < heap_size; i++){
      std::cout << heap[i] << " ";
    }
    std::cout << "\n";
  }

};
