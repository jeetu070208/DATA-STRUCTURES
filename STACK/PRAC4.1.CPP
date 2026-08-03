#include <iostream>     // Used for input and output (cin, cout)
#include <cstring>      // Used for C-style string functions (not necessary here but commonly included)
#include <cctype>       // Used for isalnum() function
using namespace std;    // So we don't need to write std:: before cin and cout

// Stack array to store operators
char stack[50];

// Top keeps track of the top element of the stack
// Initially stack is empty, so top = -1
int top = -1;

// Function to insert an element into the stack
void push(char ch)
{
    // Increase top by 1 and store the character
    stack[++top] = ch;
}

// Function to remove the top element from the stack
char pop()
{
    // Return the top element and decrease top
    return stack[top--];
}

// Function to return the precedence of operators
int precedence(char ch)
{
    // Highest precedence
    if (ch == '^')
        return 3;

    // Medium precedence
    else if (ch == '*' || ch == '/')
        return 2;

    // Lowest precedence
    else if (ch == '+' || ch == '-')
        return 1;

    // Not an operator
    else
        return 0;
}

int main()
{
    // Array to store input expression
    char infix[50];

    // Array to store output postfix expression
    char postfix[50];

    // i is used for traversing infix
    // j is used for storing postfix characters
    int i, j = 0;

    // Take expression from user
    cout << "Enter Infix Expression: ";
    cin >> infix;

    // Traverse every character until end of string
    for (i = 0; infix[i] != '\0'; i++)
    {
        // Store current character
        char ch = infix[i];

        // If character is alphabet or digit
        if (isalnum(ch))
        {
            // Directly put operand into postfix
            postfix[j++] = ch;
        }

        // If left bracket
        else if (ch == '(')
        {
            // Push into stack
            push(ch);
        }

        // If right bracket
        else if (ch == ')')
        {
            // Pop until left bracket is found
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            // Remove '(' from stack
            pop();
        }

        // If operator (+,-,*,/,^)
        else
        {
            // Pop operators having greater or equal precedence
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            // Push current operator
            push(ch);
        }
    }

    // Pop remaining operators from stack
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    // End postfix string
    postfix[j] = '\0';

    // Display result
    cout << "Postfix Expression: " << postfix;

    // Program ends successfully
    return 0;
}
