Node* segregate(Node* head) {
  int cnt0 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  Node* temp = head;
  while(temp!=NULL){
      if(temp->data == 0) cnt0++;
      if(temp->data == 1) cnt1++;
      if(temp->data == 2) cnt2++;
      temp = temp->next;
  }
  temp = head;
  while(temp!=NULL){
      if(cnt0!=0){
          temp->data = 0;
          cnt0--;
      }else if(cnt1!=0){
          temp->data = 1;
          cnt1--;
      }else if(cnt2!=0){
          temp->data = 2;
          cnt2--;
      }
      temp = temp->next;
  }
  return head;
}
// Time Complexity : O(N)
// Space Complexity : O(3)

// One Pass Solution
Node* segregate(Node* head) {
  Node* zeroHead = new Node(-1);
  Node* oneHead = new Node(-1);
  Node* twoHead = new Node(-1);
  Node* temp = head;
  Node* zero = zeroHead;
  Node* one = oneHead;
  Node* two = twoHead;
  while(temp!=NULL){
      if(temp->data == 0){
          zero->next = temp;
          zero = zero->next;
      }else if(temp->data == 1){
          one->next = temp;
          one = one->next;
      }else if(temp->data == 2){
          two->next = temp;
          two = two->next;
      }
      temp = temp->next;
  }
  two->next = nullptr;
  one->next = twoHead->next:
  zero->next = oneHead->next;
  
  Node* newHead = zeroHead->next;
  
  delete zeroHead;
  delete oneHead;
  delete twoHead;
  
  return newHead;

}
// Time Complexity : O(n)
// Space Complexity : O(1)