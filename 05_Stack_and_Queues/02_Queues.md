## Queue Data Structure

A queue is a linear data structure that follows the First In First Out (FIFO) principle. This means that the first element added to the queue will be the first one to be removed. Queues are commonly used in scenarios where order matters, such as in scheduling tasks or managing resources


### Basic Operations

1. **Enqueue**: Add an element to the end of the queue.
2. **Dequeue**: Remove and return the element from the front of the queue.
3. **Peek/Front**: Return the element at the front of the queue without removing it.
4. **IsEmpty**: Check if the queue is empty.
5. **Size**: Return the number of elements in the queue.


### Implementation using Array

```c++
#include <iostream>
using namespace std;

#define MAX 1000

class Queue {
    int front, rear, size;
    int arr[MAX];
public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    void enqueue(int x) {
        if (size == MAX) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % MAX;
        size--;
        return x;
    }

    int peek() {
        if (size == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl; // 10
    cout << "Dequeue: " << q.dequeue() << endl; // 10
    cout << "Front element: " << q.peek() << endl; // 20

    return 0;
}
```

### Implementation using Linked List

```c++
#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
    Node* front;
    Node* rear;
public:

    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return x;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

    int getSize() {
        int size = 0;
        Node* temp = front;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        return size;
    }

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl; // 10
    cout << "Dequeue: " << q.dequeue() << endl; // 10
    cout << "Front element: " << q.peek() << endl; // 20

    return 0;
}
```
## Applications of Queues






