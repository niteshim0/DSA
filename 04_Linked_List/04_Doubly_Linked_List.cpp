#include<bits/stdc++.h>
using namespace std;
class Node{
  public : 
   int data;
   Node* next;
   Node* prev;
  
  public : 
   Node(int data,Node* next,Node* prev){
     this->data = data;
     this->next = next;
     this->prev = prev;
   }
   Node(int data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
   }
};
void LLTraversal(Node* head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
}
Node* converArr2DLL(vector<int>& arr){
  Node* head = new Node(arr[0]);
  Node* prev = head;
  int n = arr.size();
  for(int i = 1;i<n;i++){
    Node* newNode = new Node(arr[i],NULL,prev);
    prev->next = newNode;
    prev = newNode;
  }
  return head;
}
Node* deleteHead(Node* head){
  if(head == NULL) return NULL;
  if(head->next == NULL){
    free(head);
    return NULL;
  }
  Node* prev = head;
  head = head->next;
  head->prev = NULL;
  prev->next = NULL;
  free(prev);
  return head;
}
Node* deleteTail(Node* head){
  if(head == NULL) return NULL;
  if(head->next == NULL){
    free(head);
    return NULL;
  }
  Node* tail = head;
  while(tail->next!=NULL){
    tail = tail->next;
  }
  Node* prev = tail->prev;
  prev->next = NULL;
  tail->prev = NULL;
  free(tail);
  return head;
}
Node* deleteKth(Node* head,int k){
  if(head == NULL) return NULL;
  Node* temp = head;
  int cnt = 0;
  while(temp!=NULL){
     cnt++;
     if(cnt == k) break;
     temp = temp->next;
  }
  Node* prev = temp->prev;
  Node* front = temp->next;
  if(prev == NULL && front == NULL){
    free(temp);
    return NULL;
  }else if(prev == NULL){
    return deleteHead(head);
  }else if(front == NULL){
    return deleteTail(head);
  }
  prev->next = front;
  front->prev = prev;
  temp->next = NULL;
  temp->prev = NULL;
  free(temp);
  return head;
}
Node* deleteNode(Node* head,int val){
  if(head == NULL) return NULL;
  Node* temp = head;
  while(temp!=NULL){
    if(temp->data == val) break;
    temp = temp->next;
  }
  Node* front = temp->next;
  Node* prev = temp->prev;
  if(front == NULL && prev == NULL){
     free(temp);
     return NULL;
  }else if(prev == NULL){
    head = head->next;
    temp->next = NULL;
    free(temp);
    return head;
  }else if(front == NULL){
    prev->next = NULL;
    temp->prev = NULL;
    free(temp);
    return head;
  }
  prev->next = front;
  front->prev = prev;
  temp->next = temp->prev = NULL;
  return head;
}
// Insertion in Doubly Linked List
Node* insertBeforeHead(Node* head,int val){
  Node* newNode = new Node(val,head,NULL);
  head->prev = newNode;
  head = newNode;
  return head;
}
Node* insertBeforeTail(Node* head,int val){
  if(head == NULL) return NULL;
  if(head->next == NULL){
    return insertBeforeHead(head,val);
  }
  Node* newNode = new Node(val);
  Node* tail = head;
  while(tail->next!=NULL){
    tail = tail->next;
  }
  Node* prev = tail->prev;
  newNode->next = tail;
  newNode->prev = prev;
  prev->next = newNode;
  tail->prev = newNode;
  return head;
}
Node* insertBeforeKth(Node* head,int val,int k){
  if(head == NULL) return NULL;
  if(k == 1){
    return insertBeforeHead(head,val);
  }
  Node* temp = head;
  int cnt = 0;
  while(temp!=NULL){
    cnt++;
    if(cnt == k) break;
    temp = temp->next;
  }
  if(temp == NULL) return head;
  Node* prev = temp->prev;
  Node* front = temp->next;
  Node* newNode = new Node(val,front,prev);
  prev->next = newNode;
  front->prev = newNode;
  return head;
}
void insertBeforeNode(Node* node,int val){
  Node* prev = node->prev;
  Node* newNode = new Node(val,node,prev);
  prev->next = newNode;
  node->prev = newNode;
}
int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8,9};
  Node* head = converArr2DLL(arr);
  LLTraversal(head);
  head = deleteHead(head);
  cout<<endl;
  LLTraversal(head);
  head = deleteTail(head);
  cout<<endl;
  LLTraversal(head);
  head = deleteKth(head,1);
  cout<<endl;
  LLTraversal(head);
  head = deleteKth(head,6);
  cout<<endl;
  LLTraversal(head);
  head = deleteKth(head,3);
  cout<<endl;
  LLTraversal(head);
  head = deleteNode(head,4);
  cout<<endl;
  LLTraversal(head);
  head = insertBeforeHead(head,4);
  cout<<endl;
  LLTraversal(head);
  head = insertBeforeTail(head,8);
  cout<<endl;
  LLTraversal(head);
  head = insertBeforeKth(head,8,5);
  cout<<endl;
  LLTraversal(head);
  insertBeforeNode(head->next,8);
  cout<<endl;
  LLTraversal(head);
}