ListNode* middleNode(ListNode* head) {
  int cnt = 0;
  ListNode* temp = head;
  while(temp!=NULL){
      cnt++;
      temp = temp->next;
  }
  int nth = cnt/2 + 1;
  temp = head;
  while(temp!=NULL){
      nth--;
      if(nth==0){
          return temp;
      }
      temp = temp->next;
  }
  return NULL;
}
// Time Complexity : O(2N)
// Space Complexity : O(1)
// Two pass solution

// One Pass solution
// Time Complexity : O(N)
// Space Complexity : O(1)
ListNode* middleNode(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while(fast!=NULL && fast->next!=NULL){
      fast = fast->next->next;
      slow = slow->next;
  }
  return slow;
}