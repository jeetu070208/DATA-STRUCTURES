#include <iostream>                     // Include input-output stream library
using namespace std;                    // Avoid writing std:: prefix

// Define structure representing an individual node in the linked list
struct Node
{
    int data;                           // Holds integer payload
    Node *next;                         // Stores memory address of subsequent node
};

Node *head = NULL;                      // Global head pointer pointing to the first node

// Append a node at the tail of the list
void insertEnd(int value)
{
    Node *newNode = new Node;           // Allocate memory on heap for new node
    newNode->data = value;              // Store value into node
    newNode->next = NULL;               // Tail node points to NULL

    if (head == NULL)                   // Handle empty list condition
    {
        head = newNode;                 // List becomes just this single node
    }
    else
    {
        Node *temp = head;              // Traversal pointer starting at front

        while (temp->next != NULL)      // Advance until reaching the existing tail node
        {
            temp = temp->next;          // Move to next node
        }

        temp->next = newNode;           // Connect old tail to new node
    }
}

// Remove the front (head) node
void deleteFirst()
{
    if (head == NULL)                   // Guard against underflow on empty list
    {
        cout << "List is empty." << endl; // Alert user
        return;                         // Early return
    }

    Node *temp = head;                  // Save pointer to target node being deleted
    head = head->next;                  // Advance head to the second node
    delete temp;                        // Release heap memory of original head
}

// Remove the terminal (tail) node
void deleteLast()
{
    if (head == NULL)                   // Guard against underflow on empty list
    {
        cout << "List is empty." << endl; // Alert user
        return;                         // Early return
    }

    if (head->next == NULL)             // Special case: list has only one element
    {
        delete head;                    // Free the single node
        head = NULL;                    // Reset head to empty state
        return;                         // Finished deletion
    }

    Node *temp = head;                  // Traversal pointer to find second-to-last node

    while (temp->next->next != NULL)    // Stop when temp points right before the last node
    {
        temp = temp->next;              // Advance forward
    }

    delete temp->next;                  // Free heap memory of the last node
    temp->next = NULL;                  // Sever the link by pointing second-to-last node to NULL
}

// Remove the node situated immediately after the node matching 'key'
void deleteAfter(int key)
{
    Node *temp = head;                  // Traversal pointer starting at head

    // Traverse until matching key is located or list ends
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;              // Move forward
    }

    if (temp == NULL)                   // Check if key does not exist in list
    {
        cout << "Given node not found." << endl; // Notify key was missing
        return;                         // Exit function
    }

    if (temp->next == NULL)             // Check if target node is already the last node
    {
        cout << "No node exists after " << key << "." << endl; // Nothing to delete
        return;                         // Exit function
    }

    Node *deleteNode = temp->next;      // Save reference to the node targeted for deletion
    temp->next = deleteNode->next;      // Bypass the deleted node by rewiring pointers
    delete deleteNode;                  // Deallocate memory of targeted node
}

// Output list contents sequentially
void display()
{
    Node *temp = head;                  // Traversal pointer starting at head

    while (temp != NULL)                // Loop across all valid nodes
    {
        cout << temp->data << " -> ";   // Print payload with chaining arrow
        temp = temp->next;              // Step forward
    }

    cout << "NULL" << endl;             // Print NULL marker denoting list termination
}

int main()
{
    // Populate list: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    insertEnd(10);                      // Add 10 to end
    insertEnd(20);                      // Add 20 to end
    insertEnd(30);                      // Add 30 to end
    insertEnd(40);                      // Add 40 to end
    insertEnd(50);                      // Add 50 to end

    cout << "Original Linked List:" << endl; // Section label
    display();                          // Output: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    // Remove first element (10)
    deleteFirst();                      // List becomes: 20 -> 30 -> 40 -> 50 -> NULL

    cout << "\nAfter deleting first node:" << endl; // Section label
    display();                          // Output: 20 -> 30 -> 40 -> 50 -> NULL

    // Remove last element (50)
    deleteLast();                       // List becomes: 20 -> 30 -> 40 -> NULL

    cout << "\nAfter deleting last node:" << endl; // Section label
    display();                          // Output: 20 -> 30 -> 40 -> NULL

    // Target node after 20 (deletes 30)
    deleteAfter(20);                    // List becomes: 20 -> 40 -> NULL

    cout << "\nAfter deleting node after 20:" << endl; // Section label
    display();                          // Output: 20 -> 40 -> NULL

    return 0;                           // Exit program cleanly
}
