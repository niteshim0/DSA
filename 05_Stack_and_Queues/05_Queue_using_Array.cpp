#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
class Queue{
  private:
  int front, rear, size;
  int arr[MAX];

  public:
    Queue(){
      front = 0;
      rear = -1;
      size = 0;
    }

    void enqueue(int x){
      if(size == MAX){
        cout<<"Queue is Full"<<endl;
        return;
      }
      rear = (rear+1)%MAX;
      size++;
      arr[rear] = x;
    }

    int dequeue(){
      if(size == 0){
        cout<<"Queue is empty"<<endl;
        return -1;
      }
      int x = arr[front];
      front = (front+1)%MAX;
      size--;
      return x;
    }

    int peek(){
      if(size == 0){
        cout<<"Queue is empty"<<endl;
        return -1;
      }
      return arr[front];
    }

    bool isEmpty(){
      return size==0;
    }

    int getSize(){
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