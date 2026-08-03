#include <iostream>     // Used for cin and cout
using namespace std;    // Avoid writing std:: every time

// Stack array to store integer values
int stack[50];

// Top points to the current top element
// Initially stack is empty
int top = -1;

// Function to push a value into stack
void push(int value)
{
    // Increase top and store value
    stack[++top] = value;
}

// Function to remove top value from stack
int pop()
{
    // Return top value and decrease top
    return stack[top--];
}

int main()
{
    // Array to store postfix expression
    char postfix[50];

    // Loop variable
    int i;

    // Variables to store operands and result
    int op1, op2, result;

    // Take postfix expression from user
    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    // Traverse each character
    for (i = 0; postfix[i] != '\0'; i++)
    {
        // Store current character
        char ch = postfix[i];

        // Check if current character is a digit
        if (ch >= '0' && ch <= '9')
        {
            // Convert character into integer
            // Example: '5' becomes 5
            push(ch - '0');
        }

        // If current character is an operator
        else
        {
            // Pop second operand
            op2 = pop();

            // Pop first operand
            op1 = pop();

            // Perform operation
            switch (ch)
            {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    result = op1 / op2;
                    break;
            }

            // Push calculated result back into stack
            push(result);
        }
    }

    // Final answer is the only value left in stack
    cout << "Result = " << pop();

    // End program
    return 0;
}
