#include "include/MergeSort.h"
#include <vector>


int main(){

  std::vector<int> unsorted = {4, 2, 6, 1, 7, 3};
  std::vector<int> small_unsorted = {9, 3, 1, 2};

  Sort::mergeSort(unsorted, true);
}

