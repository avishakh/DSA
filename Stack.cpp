#include <iostream>
#define MAX_SIZE 100
using namespace std;

class Stack {
private:
    int top;
    int stack[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int element) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        stack[++top] = element;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return stack[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return stack[top];
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\nStack Operations:";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Check if Empty";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                value = s.pop();
                if (value != -1) cout << "Popped: " << value << endl;
                break;
            case 3:
                value = s.peek();
                if (value != -1) cout << "Top element: " << value << endl;
                break;
            case 4:
                if (s.isEmpty())
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is not Empty" << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}

