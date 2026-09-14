#include <iostream>             // Include standard input-output stream library
using namespace std;            // Use standard namespace to avoid prefixing std::

// Define the blueprint for a singly linked list node
struct Node
{
    int data;                   // Holds the integer value of the node
    Node *next;                 // Pointer to store the address of the next node
};

Node *head = NULL;              // Global pointer tracking the start of the list (initially empty)

// Function to insert a new node at the very beginning of the list
void insertBeginning(int value)
{
    Node *newNode = new Node;   // Allocate memory dynamically on the heap for a new node

    newNode->data = value;      // Assign the input data to the new node
    newNode->next = head;       // Point the new node's next to the current head node
    head = newNode;             // Update head to make the new node the first element
}

// Function to insert a new node at the end of the list
void insertEnd(int value)
{
    Node *newNode = new Node;   // Allocate heap memory for the new node

    newNode->data = value;      // Set the node's data
    newNode->next = NULL;       // Since it will be the last node, set its next pointer to NULL

    if (head == NULL)           // Check if the list is currently empty
    {
        head = newNode;         // If empty, the new node becomes the head
    }
    else
    {
        Node *temp = head;      // Create a temporary pointer initialized to head for traversal

        while (temp->next != NULL) // Loop until reaching the last existing node
        {
            temp = temp->next;  // Move forward one node at a time
        }

        temp->next = newNode;   // Link the previous last node to the new node
    }
}

// Function to insert a new node immediately after a node containing a target 'key'
void insertAfter(int key, int value)
{
    Node *temp = head;          // Pointer to traverse and search through the list

    // Search until list ends or target key is found
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;      // Move to the next node in the list
    }

    if (temp == NULL)           // If temp reaches NULL, the target key does not exist
    {
        cout << "Given node not found." << endl; // Notify that the target was not found
        return;                 // Exit the function early
    }

    Node *newNode = new Node;   // Allocate heap memory for the new node

    newNode->data = value;      // Set the new node's value
    newNode->next = temp->next; // Point new node to the node currently following temp
    temp->next = newNode;       // Re-link temp to point to the new node
}

// Function to traverse and print all elements in the linked list
void display()
{
    Node *temp = head;          // Temporary pointer initialized to head for non-destructive traversal

    while (temp != NULL)        // Traverse every node until reaching the end (NULL)
    {
        cout << temp->data << " -> "; // Print the current node's data with an arrow
        temp = temp->next;      // Advance pointer to the next node
    }

    cout << "NULL" << endl;     // Print NULL to denote the end of the list followed by a newline
}

int main()
{
    // Insert 20, then 10 at the start (list becomes: 10 -> 20 -> NULL)
    insertBeginning(20);        // Insert 20 at front
    insertBeginning(10);        // Insert 10 at front

    cout << "After insertion at beginning:" << endl; // Output label to console
    display();                  // Print current list contents

    // Append 30 and 40 to the end (list becomes: 10 -> 20 -> 30 -> 40 -> NULL)
    insertEnd(30);              // Append 30 at end
    insertEnd(40);              // Append 40 at end

    cout << "After insertion at end:" << endl; // Output label to console
    display();                  // Print current list contents

    // Insert 25 directly after node 20 (list becomes: 10 -> 20 -> 25 -> 30 -> 40 -> NULL)
    insertAfter(20, 25);        // Search for 20 and insert 25 right after it

    cout << "After inserting 25 after node 20:" << endl; // Output label to console
    display();                  // Print current list contents

    return 0;                   // Indicate successful program execution
}
