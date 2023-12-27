#include <iostream>
#include "include/Stack.h" // Assuming the Stack class is in Stack.h



int main() {
    // Create a stack of integers
    Stack<int> intStack;

    // Push elements onto the stack
    for (int i = 0; i < 10; ++i) {
        intStack.push(i);
    }

    // Print the stack
    std::cout << "Stack after pushing elements: ";
    intStack.print(Stack<int>::defaultPrint);
    std::cout << std::endl;

    // Pop a few elements
    for (int i = 0; i < 5; ++i) {
        intStack.pop();
    }

    // Print the stack after popping
    std::cout << "Stack after popping elements: ";
    intStack.print(Stack<int>::defaultPrint);
    std::cout << std::endl;

    // Copy stack to a new stack and print
    Stack<int> copiedStack = intStack;
    std::cout << "Copied stack: ";
    intStack.print(Stack<int>::defaultPrint);
    std::cout << std::endl;

    return 0;
}
