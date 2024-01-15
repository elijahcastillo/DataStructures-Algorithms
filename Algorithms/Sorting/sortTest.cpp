#include "include/MergeSort.h"
#include "include/QuickSort.h"
#include <vector>


void print_vec(std::vector<int>& vec){
  std::cout << "[ ";
  for(auto x : vec){
    std::cout << x << " ";
  }

  std::cout << "]";
}

int main(){

  std::vector<int> unsorted1 = {9, 3, 1, 2, 8, 0};
  std::cout << "Before MergeSort:"; print_vec(unsorted1); std::cout << "\n";
  Sort::mergeSort(unsorted1, false);
  std::cout << "After MergeSort:"; print_vec(unsorted1); std::cout << "\n";

  std::cout << "\n";

  std::vector<int> unsorted2 = {4, 2, 6, 1, 7, 3};
  std::cout << "Before QuickSort:"; print_vec(unsorted2); std::cout << "\n";
  Sort::quickSort(unsorted2);
  std::cout << "After QuickSort:"; print_vec(unsorted2); std::cout << "\n";




}

