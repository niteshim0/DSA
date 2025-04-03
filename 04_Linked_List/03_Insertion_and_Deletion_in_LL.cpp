#include<bits/stdc++.h>
using namespace std;
class Node{
  public : 
    int data;
    Node* next;
  public:
   Node(int data,Node* next){
     this->data = data;
    this->next = next;
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
bool searchKey(Node* head, int key) {
  Node* temp = head;
  while(temp!=NULL){
      if(temp->data == key) return true;
      temp = temp->next;
  }
  return false;
}
// Deletion in Linked List
Node*  deleteHead(Node* head){
  if(head == NULL) return head;
  Node* temp = head;
  head = head->next;
  free(temp);
  return head;
}
Node* deleteTail(Node* head){
  if(head == NULL) return head;
  if(head->next == NULL){
    free(head);
    return NULL;
  }
  Node* temp = head;
  while(temp->next->next!=NULL){
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  return head;
}
Node* deleteKth(Node* head,int k){
  if(head == NULL) return head;
  if(k==1){
    return deleteHead(head);
  }
  Node* temp = head;
  Node* prev = NULL;
  int cnt = 0;
  while(temp!=NULL){
    cnt++;
    if(cnt == k){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}
Node* deletebyValue(Node* head,int val){
  if(head == NULL) return head;
  if(head->data==val){
    return deleteHead(head);
  }
  Node* temp = head;
  Node* prev = NULL;
  while(temp!=NULL){
    if(temp->data == val){
      prev->next = prev->next->next;
      free(temp);
      break;
    }
    prev = temp;
    temp = temp->next;
  }
  return head;
}
// Insertion in Linked List
Node* insertAtHead(Node* head,int val){
  return new Node(val,head);
}
Node* insertAtTail(Node* head,int val){
  Node* newNode = new Node(val,NULL);
  if(head == NULL){
    return newNode;
  }
  Node* temp = head;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}
Node* insertAtKth(Node* head,int val,int k){
  if(head == NULL){
    if(k==1){
      return new Node(val,NULL);
    }
    return NULL;
  }
  if(k == 1){
    return insertAtHead(head,val);
  }
  int cnt = 0;
  Node* temp = head;
  while(temp!=NULL){
    cnt++;
    if(cnt == k-1){
      Node* newNode = new Node(val,temp->next);
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }
  return head;
}
Node* insertBeforeValue(Node* head,int val){
  if(head == NULL){
    return head;
  }
  if(head->data == val){
    return insertAtHead(head,val);
  }
  Node* temp = head;
  while(temp!=NULL){
    if(temp->next->data == val){
      Node* newNode = new Node(val,temp->next);
      temp->next = newNode;
      break;
    }
    temp = temp->next;
  }
  return head;
}
int main(){
  vector<int> arr = {12,5,6,7,8,9,19, 7,8};
  Node* head = convertArr2LL(arr);
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
  head = deletebyValue(head,19);
  cout<<endl;
  LLTraversal(head);
  head = insertAtHead(head,5);
  cout<<endl;
  LLTraversal(head);
  head = insertAtTail(head,10);
  cout<<endl;
  LLTraversal(head);
  head = insertAtKth(head,7,7);
  cout<<endl;
  LLTraversal(head);
  head = insertBeforeValue(head,7);
  cout<<endl;
  LLTraversal(head);
}

