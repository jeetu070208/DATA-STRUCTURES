#include<iostream>              // Includes the input-output library for using cin and cout

using namespace std;            // Allows us to use cout, cin, etc. without writing std::

#define SIZE 5                  // Defines a constant named SIZE with value 5 (maximum queue size)

// ---------------------- Global Variables ----------------------

int queue[SIZE];                // Declares an integer array named queue of size 5

int front = -1;                 // front stores the index of the first element
                                // -1 means the queue is currently empty

int rear = -1;                  // rear stores the index of the last element
                                // -1 means no element has been inserted yet

// ---------------------- Enqueue Function ----------------------

void enqueuer()                 // Function to insert an element into the queue
{
    int value;                  // Variable to store the value entered by the user

    // Check if the queue is already full
    if (rear == SIZE - 1)
    {
        // SIZE-1 is the last valid index (4)
        cout << "\nQueue Overflow!\n";   // Cannot insert more elements
    }
    else
    {
        // If queue is empty before insertion
        if (front == -1)
        {
            front = 0;          // Set front to the first index
        }

        // Ask the user for the value to insert
        cout << "Enter the value to insert: ";

        cin >> value;           // Take input from the user

        rear++;                 // Move rear one position forward

        queue[rear] = value;    // Store the value at the rear position

        // Display successful insertion message
        cout << value << " inserted successfully.\n";
    }
}

// ---------------------- Dequeue Function ----------------------

void dequeuer()                 // Function to delete the front element
{
    // Queue is empty if front is -1
    // OR if front has crossed rear
    if (front == -1 || front > rear)
    {
        cout << "\nQueue Underflow! The queue is empty.\n";
    }
    else
    {
        // Display the element that is being deleted
        cout << "\nDeleted element: " << queue[front] << "\n";

        // Move front to the next element
        front++;

        // If all elements are deleted
        if (front > rear)
        {
            // Reset both pointers to indicate an empty queue
            front = -1;
            rear = -1;
        }
    }
}

// ---------------------- Display Function ----------------------

void display()                  // Function to display all queue elements
{
    // Check if queue is empty
    if (front == -1)
    {
        cout << "\nQueue is empty!\n";
    }
    else
    {
        cout << "\nQueue elements are: ";

        // Start from front and print till rear
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";     // Print each queue element
        }

        cout << "\n";                    // Move to the next line
    }
}

// ---------------------- Main Function ----------------------

int main()                      // Program execution starts from here
{
    int choice;                 // Variable to store the user's menu choice

    // Infinite loop to repeatedly show the menu
    while (true)
    {
        // Display menu options
        cout << "\n*** QUEUE MENU ***\n";
        cout << "1. Enqueue (Insert)\n";
        cout << "2. Dequeue (Delete)\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        // Ask the user to choose an option
        cout << "Enter your choice (1-4): ";

        cin >> choice;          // Read the user's choice

        // Execute the selected option
        switch (choice)
        {
            case 1:
                // Call enqueue function
                enqueuer();
                break;

            case 2:
                // Call dequeue function
                dequeuer();
                break;

            case 3:
                // Call display function
                display();
                break;

            case 4:
                // Exit the program
                cout << "\nExiting program. Goodbye!\n";
                return 0;       // Ends the program successfully

            default:
                // Executes when the user enters an invalid choice
                cout << "\nInvalid choice! Please try again.\n";
        }
    }

    // This line is never reached because of the infinite loop,
    // but it is kept as a standard practice.
    return 0;
}
