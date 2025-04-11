#include <bits/stdc++.h>
using namespace std;

#define MAX 100 

class Stack {
private:
    int arr[MAX]; 
    int top;

public:
    Stack() {
        top = -1; 
    }

    void push(int x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = x; 
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1; 
        }
        return arr[top--]; 
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top]; 
    }

    bool isEmpty() {
        return (top < 0); 
    }

    int size() {
        return (top + 1); 
    }
};

int main() {
    Stack s; 

    s.push(10); 
    s.push(20); 
    s.push(30); 

    cout << "Top element is: " << s.peek() << endl; 

    cout << "Stack size is: " << s.size() << endl; 

    cout << "Popped element is: " << s.pop() << endl;

    cout << "Stack size after pop is: " << s.size() << endl;

    return 0;
}