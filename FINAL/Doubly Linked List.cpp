#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Inserts a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head == nullptr) {
            tail = newNode;
        } else {
            head->prev = newNode;
        }
        head = newNode;
        cout << value << " inserted at the beginning.\n";
    }

    // Inserts a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (tail == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        cout << value << " inserted at the end.\n";
    }

    // Inserts a new node at a specific position
    void insertAtPosition(int value, int position) {
        if (position < 1) {
            cout << "Position cannot be less than 1. Insertion failed.\n";
            return;
        }

        if (position == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node();
        newNode->data = value;

        Node* current = head;
        for (int i = 1; i < position - 1 && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Position out of bounds. Insertion failed.\n";
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode; // If inserting at the end
        }
        current->next = newNode;
        cout << value << " inserted at position " << position << ".\n";
    }

    // Deletes the node from the beginning of the list
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }

        cout << temp->data << " deleted from the beginning.\n";
        delete temp;
    }

    // Deletes the node from the end of the list
    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;

        if (tail == nullptr) {
            head = nullptr;
        } else {
            tail->next = nullptr;
        }

        cout << temp->data << " deleted from the end.\n";
        delete temp;
    }

    // Deletes a node from a specific position
    void deleteFromPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }
        if (position < 1) {
            cout << "Position cannot be less than 1. Deletion failed.\n";
            return;
        }
        if (position == 1) {
            deleteFromBeginning();
            return;
        }

        Node* current = head;
        for (int i = 1; i < position && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Position out of bounds. Deletion failed.\n";
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev; // If deleting the tail node
        }

        cout << current->data << " deleted from position " << position << ".\n";
        delete current;
    }

    // Searches for a value in the list
    void search(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot search.\n";
            return;
        }
        Node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << value << " found at position " << position << ".\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << value << " not found in the list.\n";
    }

    // Traverses and displays the list
    void traverse(bool forward = true) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (forward) {
            Node* temp = head;
            cout << "Doubly Linked List (Forward): ";
            while (temp != nullptr) {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
        } else {
            Node* temp = tail;
            cout << "Doubly Linked List (Reverse): ";
            while (temp != nullptr) {
                cout << temp->data << " <-> ";
                temp = temp->prev;
            }
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value, position;

    while (true) {
        cout << "\nDoubly Linked List Operations:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Specific Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Specific Position\n";
        cout << "7. Search\n";
        cout << "8. Traverse (Forward)\n";
        cout << "9. Traverse (Reverse)\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position to insert at: ";
                cin >> position;
                list.insertAtPosition(value, position);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete from: ";
                cin >> position;
                list.deleteFromPosition(position);
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;
            case 8:
                list.traverse(true); // Forward traversal
                break;
            case 9:
                list.traverse(false); // Reverse traversal
                break;
            case 10:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
