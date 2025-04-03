#include<bits/stdc++.h>
using namespace std;
class Node{
  public : 
    int data;
    Node* next;
  public:
   Node(int data,Node* next){
     this->data = data;
    this->next = NULL;
  }
};
Node* convertArr2LL(vector<int>& arr){
  Node* head = new Node(arr[0],NULL);
  Node* temp = head;
  int i = 1;
  while(i<arr.size()){
    Node* newNode = new Node(arr[i++],NULL);
    temp->next = newNode;
    temp = temp->next;
  }
  return head;
}
void LLTraversal(Node* head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}
int main(){
  vector<int> arr = {12,5,6,7,8};
  Node* LL = convertArr2LL(arr);
  LLTraversal(LL);
}

