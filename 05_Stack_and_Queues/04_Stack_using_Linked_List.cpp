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

class Stack{
  private:
    Node* top;

  public : 
    Stack(){
      top = NULL;
    }
     
    void push(int x){
      Node* newNode = new Node(x);
      newNode->next = top;
      top = newNode;
    }

    bool isEmpty(){
      return top==NULL;
    }

    int peek(){
      if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return -1;
      }
      return top->data;
    }

    int pop(){
      if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return -1;
      }
      Node* temp = top;
      int poppedValue = top->data;
      top = top->next;
      delete temp;
      return poppedValue;
    }

    int size(){
      Node* temp = top;
      int current = 0;
      while(temp!=NULL){
        current++;
        temp = temp->next;
      }
      return current;
    }
};

int main(){

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