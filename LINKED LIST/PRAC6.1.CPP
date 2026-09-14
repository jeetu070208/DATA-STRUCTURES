#include <iostream>
#include <cstdlib> // Required for malloc() and free()
using namespace std;

// Definition of the Node structure
struct Node {
    int data;          // Holds the integer value stored in the node
    Node* next;        // Self-referential pointer to the next node
};

// Helper function to allocate and initialize a new node using malloc
Node* createNode(int val) {
    // Allocate heap memory equal to the size of struct Node
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Check if memory allocation was successful
    if (newNode == nullptr) {
        cout << "Memory allocation failed!" << endl;
        exit(1); // Terminate if system is out of memory
    }

    newNode->data = val;     // Set data field
    newNode->next = nullptr; // Initialize next pointer to null
    return newNode;          // Return pointer to freshly allocated node
}

// Class representing the Singly Linked List
class SinglyLinkedList {
private:
    Node* head; // Pointer to the first node

public:
    // Constructor initializes head to nullptr
    SinglyLinkedList() {
        head = nullptr; // List starts empty
    }

    // 1. Insert a new node at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = createNode(val); // Allocate node using malloc helper
        newNode->next = head;            // Link new node to current head
        head = newNode;                  // Move head pointer to new node
    }

    // 2. Insert a new node at the end
    void insertAtEnd(int val) {
        Node* newNode = createNode(val); // Allocate node using malloc helper

        // Case 1: If list is empty, new node becomes the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Case 2: Traverse to the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;           // Advance pointer
        }

        // Attach new node at the end
        temp->next = newNode;
    }

    // 3. Insert a new node after a given node value
    void insertAfter(int targetVal, int newVal) {
        Node* temp = head; // Start search from the head

        // Scan list until target value is found or end is reached
        while (temp != nullptr && temp->data != targetVal) {
            temp = temp->next;           // Move forward
        }

        // If target node does not exist in the list
        if (temp == nullptr) {
            cout << "Node with value " << targetVal << " not found." << endl;
            return;
        }

        // Target found: allocate and link new node
        Node* newNode = createNode(newVal); // Allocate node using malloc helper
        newNode->next = temp->next;         // New node points to target's next
        temp->next = newNode;               // Target node points to new node
    }

    // Traversal and display
    void display() {
        Node* temp = head; // Start from head
        while (temp != nullptr) {
            cout << temp->data << " -> "; // Print data
            temp = temp->next;            // Advance to next
        }
        cout << "NULL" << endl;           // End marker
    }

    // Destructor to release all allocated memory using free()
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next; // Save pointer to next node
            free(current);                  // Release current node memory
            current = nextNode;             // Move to saved node
        }
        head = nullptr; // Reset head
    }
};

int main() {
    SinglyLinkedList list;

    // Insert at beginning
    list.insertAtBeginning(20);
    list.insertAtBeginning(10);
    cout << "After inserting 10 and 20 at beginning:" << endl;
    list.display();

    // Insert at end
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    cout << "\nAfter inserting 40 and 50 at end:" << endl;
    list.display();

    // Insert after given node
    list.insertAfter(20, 30);
    cout << "\nAfter inserting 30 after node 20:" << endl;
    list.display();

    // Insert after nonexistent node
    cout << "\nTrying to insert 99 after nonexistent node 100:" << endl;
    list.insertAfter(100, 99);

    return 0;
}
