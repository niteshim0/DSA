## Stack Data Structure

A stack is a linear data structure that follows the Last In First Out (LIFO) principle. This means that the last element added to the stack will be the first one to be removed. Stacks are often compared to a stack of plates, where you can only add or remove the top plate.

### Applications of Stack

- **Function Call Management**: Stacks are used to manage function calls in programming languages. When a function is called, its context is pushed onto the stack, and when it returns, the context is popped off.
- **Expression Evaluation**: Stacks are used in parsing expressions, such as converting infix expressions to postfix or prefix notation.
- **Backtracking Algorithms**: Stacks are used in algorithms that require backtracking, such as depth-first search (DFS) in graphs or trees.
- **Undo Mechanism**: Many applications use stacks to implement an undo feature, where the last action can be reversed by popping the last state off the stack.
- **Memory Management**: Stacks are used in memory management for local variables and function calls in programming languages.  
- **Syntax Parsing**: Stacks are used in compilers and interpreters to parse syntax and check for balanced parentheses or brackets.
- **Browser History**: Stacks can be used to manage the history of web pages visited, allowing users to go back to the previous page.
- **Expression Conversion**: Stacks are used to convert infix expressions to postfix or prefix notation, which is useful in compilers and calculators.
- **Depth-First Search (DFS)**: Stacks are used in graph algorithms like DFS to keep track of the nodes to be explored next.
- **Memory Allocation**: Stacks are used in programming languages for memory allocation of local variables and function calls.
- **Data Parsing**: Stacks are used in data parsing applications, such as parsing XML or JSON data structures.
- **Game Development**: Stacks are used in game development for managing game states, such as saving and loading game progress.


### Stack Operations

- **Push**: Add an element to the top of the stack.
- **Pop**: Remove the top element from the stack and return it.
- **Peek/Top**: Return the top element of the stack without removing it.
- **isEmpty**: Check if the stack is empty.
- **Size**: Return the number of elements in the stack.

### Stack Implementation using Array

```c++
#include <iostream>
using namespace std;

#define MAX 100 // Maximum size of the stack

class Stack {
private:
    int arr[MAX]; // Array to store stack elements
    int top; // Index of the top element

public:
    Stack() {
        top = -1; // Initialize top to -1 (stack is empty)
    }

    // Push an element onto the stack
    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x; // Increment top and add element
    }

    // Pop an element from the stack
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1; // Return -1 if stack is empty
        }
        return arr[top--]; // Return top element and decrement top
    }

    // Peek at the top element of the stack
    int peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return -1; // Return -1 if stack is empty
        }
        return arr[top]; // Return top element
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top < 0); // Return true if top is less than 0
    }

    // Get the size of the stack
    int size() {
        return (top + 1); // Return size of the stack
    }
};

int main() {
    Stack s; // Create a stack object

    s.push(10); // Push 10 onto the stack
    s.push(20); // Push 20 onto the stack
    s.push(30); // Push 30 onto the stack

    cout << "Top element is: " << s.peek() << endl; // Peek at the top element

    cout << "Stack size is: " << s.size() << endl; // Get the size of the stack

    cout << "Popped element is: " << s.pop() << endl; // Pop an element from the stack

    cout << "Stack size after pop is: " << s.size() << endl; // Get the size of the stack after pop

    return 0;
}
```




