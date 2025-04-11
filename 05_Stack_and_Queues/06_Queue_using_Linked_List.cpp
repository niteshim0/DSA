#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
   int data;
   Node* next;

  Node(int val){
    this->data = val;
    this->next = NULL;
  }
};

class Queue{
  private:
   Node* front;
   Node* rear;
  
  public:
   Queue(){
    front = rear = NULL;
   }

   void enqueue(int x){
    Node* newNode = new Node(x);
    if(front == NULL){
      front = rear = newNode;
      return;
    }
    rear->next = newNode;
    rear = newNode;
   }

   bool isEmpty(){
    return front==NULL;
   }

   int dequeue(){
    if(isEmpty()){
      cout<<"Queue is Empty"<<endl;
      return -1;
    }
    int x = front->data;
    Node* temp = front;
    front = front->next;
    if(front == NULL){
      rear = NULL;
    }
    delete temp;
    return x;
   }

   int peek(){
    if(isEmpty()){
      cout<<"Queue is Empty"<<endl;
      return -1;
    }
    return front->data;
   }

   int getSize() {
    int size = 0;
    Node* temp = front;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
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