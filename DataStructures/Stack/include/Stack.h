#pragma once
#include <stdexcept>
#include <iostream>


template <typename T>
class Stack {
  private:
    T* m_data;
    size_t m_capacity; //Total storage avaible
    
    //Basically the same thing but who cares
    size_t m_size; // Total elements currently in stack
    size_t m_top; //-1 when stack is empty


public:
    Stack(int initial_capacity = 100): m_top(-1), m_capacity(initial_capacity), m_size(0){
      m_data = new T[m_capacity];
    }

    ~Stack(){
      delete[] m_data;
    }

    //Copy Constructor  Ex: Stack s2 = s1;
    Stack(const Stack& other)
    : m_capacity(other.m_capacity), m_size(other.m_size), m_top(other.m_top) {
        m_data = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    //Assignemnt Operator  Ex  s3 = s2;
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] m_data;

            m_capacity = other.m_capacity;
            m_size = other.m_size;
            m_top = other.m_top;

            m_data = new T[m_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }

    void resize(){
      int newCapacity = m_capacity * 2;
      T* newData = new T[newCapacity];
      
      //Copy into new array
      for(int i = 0; i < m_size; i++){
        newData[i] = m_data[i];
      }

      //Remove old array
      delete[] m_data;

      //Update
      m_data = newData;
      m_capacity = newCapacity;
    }

    void push(const T& element){
      if(m_size >= m_capacity){
        //Resize to prevent stack overflow
        resize();
      }

      //Move to next space
      m_top++;

      //Insert into stack
      m_data[m_top] = element;
      m_size++;

    };

    void pop(){
      if(isEmpty()){
        throw std::out_of_range("pop: Stack is Empty");
      }

      //Move down
      m_top--;
      m_size--;
      

    };
    T top(){
      if(isEmpty()){
        throw std::out_of_range("top: Stack is Empty");
      }

      return m_data[m_top];

    };

    bool isEmpty(){
      if(m_top == -1 || m_size == 0){
        return true;
      } else {
        return false;
      }
    };
    size_t size(){
      return m_size;
    };


    // Displays the list using a custom print function
    void print(void (*customPrint)(T)) {
        for (size_t i = 0; i < m_size; i++){
            customPrint(m_data[i]); // Call the custom print function directly
            std::cout << " ";
        }
        std::cout << "\n";
    }

    // Example custom print function
    static void defaultPrint(T data) {
        std::cout << data;
    }
};
