
#include "include/Queue.h"  // Assuming your Queue class is in Queue.h
#include <iostream>

// Custom print function for integers
void printInt(int data) {
    std::cout << data;
}

int main() {
    Queue<int> q;

    std::cout << "Enqueuing elements: 10, 20, 30\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Current Queue: ";
    q.print(printInt);
    std::cout << "\n";

    std::cout << "Dequeue one element\n";
    q.dequeue();

    std::cout << "Current Queue after one dequeue: ";
    q.print(printInt);
    std::cout << "\n";

    std::cout << "Front element (peek): " << q.peek() << "\n";

    std::cout << "Is the Queue empty? " << (q.isEmpty() ? "Yes" : "No") << "\n";

    std::cout << "Queue size: " << q.size() << "\n";

    std::cout << "Enqueueing more elements: 40, 50\n";
    q.enqueue(40);
    q.enqueue(50);

    std::cout << "Current Queue: ";
    q.print(printInt);
    std::cout << "\n";

    std::cout << "Creating a copy of the current Queue\n";
    Queue<int> q2 = q;

    std::cout << "Contents of the copied Queue: ";
    q2.print(printInt);
    std::cout << "\n";

    return 0;
}
