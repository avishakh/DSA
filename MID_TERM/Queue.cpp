#include <iostream>
using namespace std;

#define MAX_SIZE 100 // Maximum size of the queue

class Queue {
private:
    int front, rear; // Front and rear pointers
    int queue[MAX_SIZE]; // Array to store queue elements

public:
    // Constructor to initialize queue
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    // Function to add an element to the queue (Enqueue)
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        if (front == -1) front = 0; // Set front to 0 if inserting first element
        queue[++rear] = element;
        cout << "Enqueued: " << element << endl;
    }

    // Function to remove an element from the queue (Dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int element = queue[front++];
        if (front > rear) { // Reset queue when all elements are dequeued
            front = -1;
            rear = -1;
        }
        return element;
    }

    // Function to return the front element without removing it (Peek)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return queue[front];
    }
};

// Main function to handle user input
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\nQueue Operations:";
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Peek";
        cout << "\n4. Check if Empty";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";

        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear();  // Clear error flag
            cin.ignore(10000, '\n'); // Ignore invalid input
            choice = -1; // Assign invalid value to trigger default case
        }

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;

                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input! Enter an integer.\n";
                    break;
                }

                q.enqueue(value);
                break;

            case 2:
                value = q.dequeue();
                if (value != -1) cout << "Dequeued: " << value << endl;
                break;

            case 3:
                value = q.peek();
                if (value != -1) cout << "Front Element: " << value << endl;
                break;

            case 4:
                cout << (q.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 5.\n";
        }

    } while (choice != 5);

    return 0;
}
