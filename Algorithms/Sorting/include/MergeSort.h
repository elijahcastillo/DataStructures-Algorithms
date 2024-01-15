#pragma once

#include <iostream>
#include <vector>


namespace Sort {

  void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& original_arr){
    //**Note** - orignal_arr is the array before the split, we modify oringal array

    int right_size = right.size();
    int left_size = left.size();

    //Keep track of where we are in each array
    int original_idx = 0;
    int left_idx = 0;
    int right_idx = 0;

    //Check the conditions for merging
    while(left_idx < left.size() && right_idx < right.size()){
      //Find smaller element
      if(left[left_idx] < right[right_idx]){
        //Element in left is smaller, copy to original array
        original_arr[original_idx] = left[left_idx];

        //Update Index
        left_idx++;
        original_idx++;

      } else {
        //Element in right is smaller, copy to original array
        original_arr[original_idx] = right[right_idx];

        //Update Index
        right_idx++;
        original_idx++;

      }
    }

    //Copy any remaining Elements left in either array
    while(left_idx < left.size()){
      original_arr[original_idx] = left[left_idx];

      //Update Index
      left_idx++;
      original_idx++;
    }

    while(right_idx< right.size()){
      original_arr[original_idx] = right[right_idx];

      //Update Index
      right_idx++;
      original_idx++;
    }


  }

  void mergeSort(std::vector<int>& array, bool debug = false){
   
      int array_len = array.size();

      //Base case if array only has one element in it 
      if(array_len <= 1){
        if (debug) {
          std::cout << "Merge Sort Base Case: [" << array[0] << "]\n";
        }
        return;
      }

      //Make two new arrays to split original into
      int middle = array_len / 2;
      std::vector<int> left(middle);
      std::vector<int> right(array_len - middle);

      //Copy from original array into split arrays
      int i = 0; // left array index
      int j = 0; // right array index

      for(; i < array_len; i++){
        if(i < middle){
          //Copy into left array
          left[i] = array[i];
        } else {
          //Copy into right array
          right[j] = array[i];
          j++;
        }
      }

      //Recursive calls to keep spliting arrays untill there is 1 element 
      mergeSort(left, debug);
      mergeSort(right, debug);

      // Debugging: Print the merging process
      if (debug) {
          std::cout << "Merging arrays -> [";
          for (size_t i = 0; i < left.size(); ++i) {
              std::cout << left[i];
              if (i < left.size() - 1) {
                  std::cout << " ";
              }
          }
          std::cout << "] and [";
          for (size_t i = 0; i < right.size(); ++i) {
              std::cout << right[i];
              if (i < right.size() - 1) {
                  std::cout << " ";
              }
          }
          std::cout << "]\n";
      }


      //Merge the two unsorted arrays togeter into one sorted array
      merge(left, right, array);

      if (debug) {
          std::cout << "Merged arrays into sorted array : [";
          for (size_t i = 0; i < array.size(); ++i) {
              std::cout << array[i];
              if (i < array.size() - 1) {
                  std::cout << " ";
              }
          }
          std::cout << "]\n";
      }

  }






}
