#include <iostream>
#include "include/DLinkedList.h"

int main(){
  DLinkedList<int> list;

  list.append(1);
  list.append(2);
  list.append(3);
  list.append(4);
  list.prepend(0);

  list.print(DLinkedList<int>::defaultPrint);
  list.insertAt(8, 1);
  list.print(DLinkedList<int>::defaultPrint);
  list.removeAt(12);
  list.print(DLinkedList<int>::defaultPrint);
}
