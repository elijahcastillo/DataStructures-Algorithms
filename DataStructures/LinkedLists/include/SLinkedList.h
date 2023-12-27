#include <iostream>

// Node structure definition
template <typename T>
struct Node {
    T data;       // Holds the data of the node
    Node* next;   // Pointer to the next node in the list

    // Constructor for creating a new node with given data
    Node(T data): data(data), next(nullptr) {};
};

// Singly Linked List class definition
template <typename T>
class SLinkedList {
    Node<T>* head;  // Pointer to the first node in the list
    unsigned int size;  // Tracks the number of elements in the list

public:
    // Constructor to initialize an empty list
    SLinkedList(): head(nullptr), size(0) {};

    // Destructor to clean up all nodes in the list
    ~SLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    // Adds a new element at the end of the list
    void append(T data) {
        Node<T>* node = new Node<T>(data);
        if (head == nullptr) {
            head = node; // List is empty, new node becomes head
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next; // Traverse to the last node
            }
            current->next = node; // Link last node to the new node
        }
        size++;
    }

    // Adds a new element at the beginning of the list
    void prepend(T data) {
        Node<T>* node = new Node<T>(data);
        node->next = head; // New node points to the current head
        head = node; // New node becomes the new head
        size++;
    }

    // Inserts a new element at the specified index (0-based)
    void insertAt(T data, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index cannot be negative or greater than the list size.");
        }

        if (index == 0) {
            prepend(data); // Insert at the beginning
            return;
        }

        Node<T>* node = new Node<T>(data);
        Node<T>* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next; // Traverse to the node before the insertion point
        }
        node->next = current->next; // Link new node to the next node
        current->next = node; // Link current node to the new node
        size++;
    }

    // Removes the first occurrence of the specified data
    void remove(T data) {
        if (head == nullptr) {
            return; // List is empty, nothing to remove
        }

        if (head->data == data) {
            Node<T>* temp = head;
            head = head->next; // New head is the second node
            delete temp; // Delete the old head
            size--;
            return;
        }

        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != data) {
            current = current->next; // Traverse until the node before the target
        }

        if (current->next != nullptr) {
            Node<T>* temp = current->next;
            current->next = temp->next; // Unlink the target node
            delete temp; // Delete the target node
            size--;
        }
    }

    // Removes the element at the specified index
    void removeAt(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds.");
        }

        if (index == 0) {
            Node<T>* temp = head;
            head = head->next; // New head is the second node
            delete temp; // Delete the old head
            size--;
            return;
        }

        Node<T>* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next; // Traverse to the node before the target
        }

        Node<T>* temp = current->next;
        current->next = temp->next; // Unlink the target node
        delete temp; // Delete the target node
        size--;
    }

    // Retrieves the data at the specified index
    T get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds.");
        }

        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next; // Traverse to the target node
        }
        return current->data; // Return the data of the target node
    }

    // Returns the number of elements in the list
    int length() const {
        return size;
    }

    // Checks if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Reverses the order of the elements in the list
    void reverse() {
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        Node<T>* next = nullptr;
        while (current != nullptr) {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the link
            prev = current; // Move prev to current node
            current = next; // Move to the next node
        }
        head = prev; // New head is the last visited node
    }

    // Displays the list using a custom print function
    void print(void (*customPrint)(T)) {
        Node<T>* current = head;
        while (current != nullptr) {
            customPrint(current->data); // Print current node data
            std::cout << "  ->  ";
            current = current->next; // Move to next node
        }
        std::cout << "null\n\n";
    }

    // Example custom print function
    static void defaultPrint(T data) {
        std::cout << data;
    }
};
