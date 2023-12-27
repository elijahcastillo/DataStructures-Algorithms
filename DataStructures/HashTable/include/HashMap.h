#pragma once
#include <functional>
#include <string>
#include <iostream>

template <typename t>
struct Hash {
  std::size_t operator()(const t& key) const {
    return std::hash<t>{}(key); //stl generic hash function, default for non specilized types
  }
};


// Specialization of the Hash struct for int type
template <>
struct Hash<int> {
  std::size_t operator()(const int& key) const {
    return std::hash<int>{}(key); 
  }
};

// Specialization of the Hash struct for std::string type
template <>
struct Hash<std::string> {
  std::size_t operator()(const std::string& key) const {
    return std::hash<std::string>{}(key); 
  }
};








template <typename K, typename V, typename Hasher = Hash<K>>
class HashMap {
  
  // Internal structure for storing key-value pairs
  struct keyvalue {
    K key;
    V value;
    bool occupied = false; //Initialized to false when created
  };

  keyvalue* entries;       // Pointer to array of key-value pairs
  size_t entryCount;       // Current number of elements in the hash map
  size_t entryCapacity;    // Total capacity of the hash map
  Hasher hasher; //struct that has overloaded "()" operator so it looks like a function ex: hasher(key)


public:
  HashMap(size_t inital_size = 100): entryCount(0), entryCapacity(inital_size){
    //allocate initial entry array
    entries = new keyvalue[entryCapacity];

  }

  ~HashMap(){
    delete[] entries;
  }


  // Function to compute the hash value of a key
  size_t hash(K key, size_t size){
    return hasher(key) % size; // Modulo operation to ensure it fits within array boundaries
  }


  // Function to handle collisions using linear probing
  size_t handlecollision(size_t collidedIndex){

    /* The handlecollision method can potentially cause an infinite loop if the hash map is full. */

    //Search from the collied index for a new unocccupied index and return it
    while(entries[collidedIndex].occupied){
      collidedIndex = (collidedIndex + 1) % entryCapacity;
    }

    return collidedIndex;


  }

  // Function to resize the hash map when it becomes too full
  void resize(){
    size_t newCapacity = entryCapacity * 2;
    keyvalue* newEntries = new keyvalue[newCapacity];

    std::cout << "Resizing Hashmap from " << entryCapacity << " to " << newCapacity << "\n";


    //Recalculate Hashes in new array
    for (size_t i = 0; i < entryCapacity; ++i) {
      if (entries[i].occupied) {
        size_t index = hash(entries[i].key, newCapacity);
        while (newEntries[index].occupied) {
          index = (index + 1) % newCapacity;
        }
        newEntries[index] = entries[i];
      }
    }


    delete[] entries;
    entries = newEntries;
    entryCapacity = newCapacity;
  }

  void insert(const K& key, const V& value){

    //We dont want to resize only when we reach rull capacity beacuse
    //its not ass efficient due to some hash thing I think
    if (entryCount >= entryCapacity * 0.75) {
      resize();
    }

    size_t index = hash(key, entryCapacity);

    while (entries[index].occupied) {
      if (entries[index].key == key) {  // Update value if key already exists
        entries[index].value = value;
        return;
      }
      index = (index + 1) % entryCapacity;
    }

    //Key not already found, create new kv struct
    entries[index] = keyvalue{key, value, true};
    entryCount++;


  }

  V& get(const K& key){
    
    size_t index = hash(key, entryCapacity);
    while (entries[index].occupied) {

      if (entries[index].key == key) {
        return entries[index].value;
      }

      index = (index + 1) % entryCapacity;
    }

    throw std::runtime_error("Key not found"); 
  }

  bool containsKey(const K& key){

    size_t index = hash(key, entryCapacity);

    while(entries[index].occupied){
      if(entries[index].key == key){
        return true;
      }

      index = (index + 1) % entryCapacity;
    }

    return false;
  }



  //Just allows us to iterate over this hashmap, dont need to know this
  class iterator {
    keyvalue* current;
    keyvalue* end;

    public:
        iterator(keyvalue* start, keyvalue* end) : current(start), end(end) {
          // Find the first occupied entry
          while (current != end && !current->occupied) {
            ++current;
          }
        }

        // Prefix increment
        iterator& operator++() {
          do {
            ++current;
          } while (current != end && !current->occupied);
          return *this;
        }


        // Dereference operator
        keyvalue& operator*() const {
          return *current;
        }

        // Iterator inequality check
        bool operator!=(const iterator& other) const {
          return current != other.current;
        }
  };


    // Begin iterator
    iterator begin() {
      return iterator(entries, entries + entryCapacity);
    }

    // End iterator
    iterator end() {
      return iterator(entries + entryCapacity, entries + entryCapacity);
    }


};
