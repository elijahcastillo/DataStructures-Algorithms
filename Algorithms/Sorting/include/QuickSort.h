#pragma once
#include <vector>
#include <iostream>


namespace Sort {

  void swap(std::vector<int>& arr, int idx1, int idx2){
    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
  }

  void quickSortHelper(std::vector<int>& array, int startIdx, int endIdx){

    // Base case: When the start index is greater or equal to the end index,
    // it means the array or sub-array has one or no element and is already sorted.
    if(startIdx >= endIdx) return;

    // Choosing the pivot element. In this case, the pivot is always the last element of the array.
    int pivotIdx = endIdx;

    // 'i' tracks the last position where a swap happened.
    int i = startIdx - 1;

    // 'j' is used to iterate through the array.
    int j = startIdx;


    while(j < pivotIdx){

      // If the current element is smaller than the pivot,
      // increment 'i' and swap the elements at 'i' and 'j'.
      if(array[j] < array[pivotIdx]){
        i++;
        swap(array, i, j);
      }

      j++;
    }

    // After partitioning, swap the pivot element with the element at 'i + 1' position.
    // This places the pivot in its correct sorted position.
    i++;
    swap(array, i, pivotIdx);


  // Recursively apply the same logic to the two sub-arrays, 
  // one before the pivot and one after the pivot.
  quickSortHelper(array, startIdx, i - 1); // Sort the left sub-array
  quickSortHelper(array, i + 1, endIdx);   // Sort the right sub-array

  }

  void quickSort(std::vector<int>& array){
    quickSortHelper(array, 0, array.size() - 1);
  }



}
