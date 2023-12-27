
#include <iostream>
#include <string>
#include "include/PriorityQueue.h"

// Task structure
struct Task {
    int priority;
    std::string description;

    // Overload the < operator for the min heap.
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

int main() {
    PriorityQueue<Task> taskQueue;

    // Adding tasks to the queue
    taskQueue.enqueue(Task{3, "Write report"});
    taskQueue.enqueue(Task{1, "Fix critical bug"});
    taskQueue.enqueue(Task{2, "Attend team meeting"});
    taskQueue.enqueue(Task{4, "Refactor code"});

    // Executing tasks based on priority
    std::cout << "Executing tasks in order of priority:" << std::endl;
    while (!taskQueue.isEmpty()) {
        Task currentTask = taskQueue.dequeue();
        std::cout << "Priority " << currentTask.priority << ": " << currentTask.description << std::endl;
    }

    return 0;
}
