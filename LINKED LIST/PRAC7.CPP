#include <iostream>
using namespace std;

struct Node                    // Creates a node
{
    int data;                  // Stores data
    Node *next;                // Stores address of next node
};

Node *head = NULL;             // Head points to first node


// INSERT AT BEGINNING
void insertBeginning()
{
    int value;                 // Variable for data
    cout << "Enter value: ";
    cin >> value;

    Node *newNode = new Node;  // Creates new node
    newNode->data = value;     // Stores value in node

    if (head == NULL)          // Checks if list is empty
    {
        head = newNode;        // New node becomes first node
        newNode->next = head;  // Node points to itself
    }
    else
    {
        Node *temp = head;     // Temp starts from head

        while (temp->next != head) // Finds last node
            temp = temp->next;

        newNode->next = head;  // New node points to old head
        head = newNode;        // New node becomes head
        temp->next = head;     // Last node points to new head
    }

    cout << "Node inserted at beginning.\n";
}


// INSERT AT END
void insertEnd()
{
    int value;                 // Variable for data
    cout << "Enter value: ";
    cin >> value;

    Node *newNode = new Node;  // Creates new node
    newNode->data = value;     // Stores value in node

    if (head == NULL)          // Checks if list is empty
    {
        head = newNode;        // New node becomes head
        newNode->next = head;  // Node points to itself
    }
    else
    {
        Node *temp = head;     // Temp starts from head

        while (temp->next != head) // Finds last node
            temp = temp->next;

        temp->next = newNode;  // Last node points to new node
        newNode->next = head;  // New node points to head
    }

    cout << "Node inserted at end.\n";
}


// INSERT AFTER GIVEN NODE
void insertAfter()
{
    int key, value;            // Key is searched value
    cout << "Enter node after which to insert: ";
    cin >> key;

    cout << "Enter value: ";
    cin >> value;

    if (head == NULL)          // Checks if list is empty
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;         // Temp starts from head

    do
    {
        if (temp->data == key) // Checks given node
        {
            Node *newNode = new Node; // Creates new node
            newNode->data = value;    // Stores value
            newNode->next = temp->next; // Connects new node
            temp->next = newNode;      // Given node points to new node

            cout << "Node inserted.\n";
            return;
        }

        temp = temp->next;     // Moves to next node
    }
    while (temp != head);      // Stops after full circular list

    cout << "Node not found.\n";
}


// DELETE FIRST NODE
void deleteFirst()
{
    if (head == NULL)          // Checks if list is empty
    {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == head)    // Checks if only one node exists
    {
        delete head;           // Deletes the only node
        head = NULL;           // List becomes empty
    }
    else
    {
        Node *temp = head;     // Temp stores old head
        Node *last = head;     // Finds last node

        while (last->next != head)
            last = last->next;

        head = head->next;     // Moves head to next node
        last->next = head;     // Last points to new head
        delete temp;           // Deletes old first node
    }

    cout << "First node deleted.\n";
}


// DELETE LAST NODE
void deleteLast()
{
    if (head == NULL)          // Checks if list is empty
    {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == head)    // Checks if only one node exists
    {
        delete head;           // Deletes the only node
        head = NULL;           // List becomes empty
    }
    else
    {
        Node *temp = head;     // Starts from head

        while (temp->next->next != head) // Finds second last node
            temp = temp->next;

        Node *last = temp->next; // Stores last node
        temp->next = head;       // Second last points to head
        delete last;             // Deletes last node
    }

    cout << "Last node deleted.\n";
}


// DELETE NODE AFTER GIVEN NODE
void deleteAfter()
{
    int key;                   // Stores given node value
    cout << "Enter node after which to delete: ";
    cin >> key;

    if (head == NULL)          // Checks if list is empty
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;         // Temp starts from head

    do
    {
        if (temp->data == key) // Checks given node
        {
            Node *del = temp->next; // Node to be deleted

            if (del == head)         // If deleting head
            {
                if (head->next == head) // Only one node
                {
                    delete head;     // Deletes only node
                    head = NULL;     // List becomes empty
                    cout << "Node deleted.\n";
                    return;
                }

                head = head->next;   // Move head forward
            }

            temp->next = del->next;  // Skip deleted node
            delete del;              // Delete the node

            cout << "Node deleted.\n";
            return;
        }

        temp = temp->next;       // Move to next node
    }
    while (temp != head);        // Stops after full list

    cout << "Node not found.\n";
}


// DISPLAY ALL NODES
void display()
{
    if (head == NULL)            // Checks if list is empty
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;            // Starts from head

    cout << "Circular Linked List: ";

    do
    {
        cout << temp->data << " "; // Prints node data
        temp = temp->next;         // Moves to next node
    }
    while (temp != head);          // Stops when head comes again

    cout << endl;
}


// MAIN FUNCTION
int main()
{
    int choice;                   // Stores menu choice

    do
    {
        cout << "\n--- SINGLY CIRCULAR LINKED LIST ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Given Node\n";
        cout << "4. Delete First Node\n";
        cout << "5. Delete Last Node\n";
        cout << "6. Delete Node After Given Node\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertBeginning();       // Calls beginning insertion
                break;

            case 2:
                insertEnd();             // Calls end insertion
                break;

            case 3:
                insertAfter();           // Calls insertion after node
                break;

            case 4:
                deleteFirst();           // Calls first deletion
                break;

            case 5:
                deleteLast();            // Calls last deletion
                break;

            case 6:
                deleteAfter();           // Calls deletion after node
                break;

            case 7:
                display();               // Displays all nodes
                break;

            case 8:
                cout << "Program ended.\n"; // Exits program
                break;

            default:
                cout << "Invalid choice.\n"; // Handles wrong choice
        }

    }
    while (choice != 8);                 // Repeats until exit

    return 0;                            // Ends program
}
