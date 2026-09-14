#include <iostream>
#include <cstdlib> // Required for malloc() and free()
using namespace std;

// Definition of the Node structure
struct Node {
    int data;          // Stores the data value of the node
    Node* next;        // Pointer to the next node in the list
};

// Class representing the Singly Linked List focused on Deletion
class SinglyLinkedList {
private:
    Node* head; // Points to the first node of the list

public:
    // Constructor initializes an empty list
    SinglyLinkedList() {
        head = nullptr; // Set head pointer to null
    }

    // Helper function to insert nodes using malloc (used to populate the list)
    void append(int val) {
        // Allocate heap memory for a new node
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == nullptr) {
            cout << "Memory allocation failed!" << endl;
            exit(1);
        }
        newNode->data = val;     // Assign data
        newNode->next = nullptr; // Initialize next pointer to null

        // If list is empty, make newNode the head
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Traverse to find the last node
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Advance to next node
        }
        temp->next = newNode;  // Link last node to new node
    }

    // --- DELETION OPERATIONS ---

    // 1. Delete node at the beginning
    void deleteAtBeginning() {
        // Underflow check: check if the list is already empty
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        Node* temp = head;   // Temporarily store pointer to current head node
        head = head->next;   // Shift head pointer to the second node
        free(temp);          // Release memory of the deleted node using free()
    }

    // 2. Delete node at the end
    void deleteAtEnd() {
        // Underflow check: check if the list is empty
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        // Special case: list has only one node
        if (head->next == nullptr) {
            free(head);      // Free the single node's memory
            head = nullptr;  // Reset head pointer to null
            return;
        }

        // Traverse to the second-to-last node
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next; // Advance to next node
        }

        // Free memory of the last node
        free(temp->next);     // Release dynamically allocated memory using free()
        temp->next = nullptr; // Set second-to-last node's next pointer to null
    }

    // 3. Delete a node by value (first occurrence)
    void deleteByValue(int targetVal) {
        // Underflow check: check if the list is empty
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        // Special case: the target value is in the head node
        if (head->data == targetVal) {
            Node* temp = head; // Store pointer to head node
            head = head->next; // Move head pointer forward
            free(temp);        // Deallocate old head node
            return;
        }

        // Traverse to find the node right before the target node
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != targetVal) {
            temp = temp->next; // Advance to next node
        }

        // Check if value was not found in the list
        if (temp->next == nullptr) {
            cout << "Value " << targetVal << " not found in the list." << endl;
            return;
        }

        // Target found: bypass and deallocate the target node
        Node* nodeToDelete = temp->next; // Hold address of node to be deleted
        temp->next = nodeToDelete->next; // Link predecessor to successor node
        free(nodeToDelete);              // Deallocate target node memory using free()
    }

    // Display the list elements
    void display() {
        Node* temp = head; // Start from head
        while (temp != nullptr) {
            cout << temp->data << " -> "; // Print current node's data
            temp = temp->next;            // Move to next node
        }
        cout << "NULL" << endl;           // Indicate end of list
    }

    // Destructor to free any remaining nodes
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next; // Save pointer to next node
            free(current);                  // Release current node memory
            current = nextNode;             // Move forward
        }
        head = nullptr; // Ensure head is reset
    }
};

// Main function demonstrating deletion operations
int main() {
    SinglyLinkedList list;

    // Populate initial list: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    cout << "Initial list:" << endl;
    list.display();

    // 1. Delete at beginning (removes 10)
    list.deleteAtBeginning();
    cout << "\nAfter deleteAtBeginning():" << endl;
    list.display();

    // 2. Delete at end (removes 50)
    list.deleteAtEnd();
    cout << "\nAfter deleteAtEnd():" << endl;
    list.display();

    // 3. Delete by value (removes 30)
    list.deleteByValue(30);
    cout << "\nAfter deleteByValue(30):" << endl;
    list.display();

    // 4. Attempt to delete a nonexistent value
    cout << "\nTrying to delete nonexistent value 99:" << endl;
    list.deleteByValue(99);

    return 0;
}
