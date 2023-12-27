#pragma once
#include <iostream>

template <typename T>
struct DNode {
  T data;
  DNode* next;
  DNode* prev;

  DNode(T data): data(data), next(nullptr), prev(nullptr){};
};


template <typename T>
class DLinkedList{
  DNode<T>* head;
  unsigned int size;

public:
  DLinkedList(): head(nullptr){};
 
  void append(T data){
    DNode<T>* node = new DNode<T>(data);

    if(head == nullptr){
      head = node;
      size++;
      return;
    }

    DNode<T>* current = head;
    while(current->next != nullptr){
      current = current->next;
    }
    node->prev = current;
    current->next = node;
    size++;
  }


  void prepend(T data){
    DNode<T>* node = new DNode<T>(data);

    if(head == nullptr){
      head = node;
      size++;
      return;
    }

    head->prev = node;
    node->next = head;
    head = node;
    size++;


  }


  void insertAt(T data, int index){
    //3
    //0  1  2  3  4
    //      .
    if (index < 0 || index > size) {
        throw std::out_of_range("Index cannot be negative OR out of range");
    }

    if(index == 0){
      prepend(data);
      return;
    }



    DNode<T>* node = new DNode<T>(data);

    int currentIdx = 0;
    DNode<T>* current = head;
    while (current->next != nullptr && currentIdx < index - 1) {
        current = current->next;
        currentIdx++;
    }
     DNode<T>* temp = current->next;
     current->next = node;
     node->prev = current;
     node->next = temp;
     temp->prev = node;
     size++;


    




  }


  void removeAt(int index){
    if (index < 0 || index > size) {
        throw std::out_of_range("Index cannot be negative OR out of range");
    }


    if(index == 0){
      DNode<T>* temp = head;
      head = head-> next;
      delete temp;
    }
    
    int currentIdx = 0;
    DNode<T>* current = head;
    while(current->next != nullptr && currentIdx < index - 1){
      current = current->next;
      currentIdx++;
    }

    // 0 1 2 3
    //   .

    DNode<T>* temp = current->next;
    current->next  = temp->next;
    temp->next->prev = current;
    delete temp;
    size--;


  }


  // Function to display the linked list using a custom print function
  void print(void (*customPrint)(T)) {
        DNode<T>* current = head;
        while (current != nullptr) {
            customPrint(current->data);
            std::cout << "  <->  ";
            current = current->next;
        }
        std::cout << "null";
        std::cout << std::endl;
    }


    // Example custom print function
    static void defaultPrint(T data) {
        std::cout << data;
    }
};
