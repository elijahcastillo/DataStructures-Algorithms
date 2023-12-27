#pragma once

#include <stdexcept>
#include <iostream>


template <typename T>
class Queue {
  private:
    T* m_data; // Pointer to the dynamic array that holds queue elements.
    size_t m_capacity; // Total storage available in the queue.
    size_t m_size; // Total elements currently in the queue.

    size_t m_front; // Index of the front of the queue.
    size_t m_rear; // Index of the rear of the queue.


public:

    // Constructor: Initializes the queue with a specific capacity.
    // Sets m_front and m_rear to 0, indicating an empty queue.
    Queue(int initial_capacity = 100): m_front(0), m_rear(0), m_capacity(initial_capacity), m_size(0){
      m_data = new T[m_capacity];
    }

    ~Queue(){
      delete[] m_data;
    }

    //Copy Constructor  Ex: Stack s2(this) = s1(other);
    Queue(const Queue& other)
    : m_capacity(other.m_capacity), m_size(other.m_size), m_front(0), m_rear(other.m_size) {
        m_data = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[(other.m_front + i) % other.m_capacity];
        }
    }

    // Assignemnt Operator  Ex  s3(this) = s2(other);
    // Assigns the content of one queue to another.
    // It first checks for self-assignment, and then performs a deep copy.
    Queue& operator=(const Queue& other) {
        if (this != &other) {
            delete[] m_data;
    
            m_capacity = other.m_capacity;
            m_size = other.m_size;
            m_front = other.m_front;
            m_rear = other.m_rear;
    
            m_data = new T[m_capacity];
            for (size_t i = 0; i < m_size; ++i) {
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }



    // Resizes the queue when it runs out of capacity.
    // Doubles the capacity and rearranges the elements linearly.
    void resize(){
      int newCapacity = m_capacity * 2;
      T* newData = new T[newCapacity];
      
      //Copy into new array, wont need to wrap arround anymore so it will be linear when resized
      for(int i = 0; i < m_size; i++){
        newData[i] = m_data[(m_front + i) % m_capacity];
      }

      //Remove old array
      delete[] m_data;

      //Update
      m_data = newData;
      m_capacity = newCapacity;
      m_front = 0;
      m_rear = m_size;
    }


    // Increments an index and wraps it around if it reaches the capacity.
    // This is crucial for maintaining the circular nature of the queue.
    void incrementIndex(size_t& index){
      //Using mod to keep inside of the array
      index = (index + 1) % m_capacity;
    }



    // Adds an element to the back of the queue
    void enqueue(const T& item){
      if(isFull()){
        //Prevents Overflow
        resize();
      }

      //Add to queue at rear
      incrementIndex(m_rear);
      m_data[m_rear] = item;

      if (m_size == 0) {
          m_front = m_rear;
      }

      m_size++;

    };

    // Removes and returns the front element of the queue
    T dequeue(){
      if(isEmpty()){
        throw std::out_of_range("dequeue: Queue is Empty");
      }

      //Get current queue value
      T value = m_data[m_front];

      //Remove from queue
      incrementIndex(m_front);
      m_size--;

      // Resets indices if the queue becomes empty after dequeue.
      if (m_size == 0) {
          m_front = 0;
          m_rear = 0;
      }

      return value;

    };

    // Returns the front element of the queue without removing it
    T peek() const {
      if(isEmpty()){
        throw std::out_of_range("dequeue: Queue is Empty");
      }

      //Get current queue value
      T value = m_data[m_front];


      return value;
    };

    // Checks if the queue is empty
    bool isEmpty() const{
      return m_size == 0;
    };

    bool isFull() const {
      return m_size >= m_capacity;
    }

    // Returns the number of elements in the queue
    size_t size() const {
      return m_size;
    };


    // Displays the contents of the queue using a custom print function.
    // Iterates over the queue in a circular manner using modulo arithmetic.
    void print(void (*customPrint)(T)) {
        for (size_t i = 0; i < m_size; i++){
            customPrint(m_data[(m_front + i) % m_capacity]); // Call the custom print function directly
            std::cout << " ";
        }
        std::cout << "\n";
    }

    // Example custom print function
    static void defaultPrint(T data) {
        std::cout << data;
    }
};
