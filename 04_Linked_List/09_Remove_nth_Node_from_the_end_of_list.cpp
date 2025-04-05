ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* temp = head;
  int cnt = 0;
  while(temp!=NULL){
      cnt++;
      temp = temp->next;
  }
  if(cnt==n){
          ListNode* first = head;
          head = head->next;
          delete first;
          return head;
  }
  int res = cnt-n;
  temp = head;
  while(temp!=NULL){
      res--;
      if(res==0){
          break;
      }
      temp  = temp->next;
  }
  ListNode* delNode = temp->next;
  temp->next = temp->next->next;
  delete delNode;
  return head;
}
// Time Complexity : O(len + N)
// Space Complexity : O(1)
// Two pass solution

// One pass Solution
// Time Complexity : O(N)
// Space Complexity : O(2)

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* fast = head;
  for(int i = 0;i<n;i++){
      fast = fast->next;
  }
  if(fast == NULL){
      ListNode* temp = head;
      head = head->next;
      delete temp;
      return head;
  }
  ListNode* slow = head;
  while(fast->next!=NULL){
      fast = fast->next;
      slow = slow->next;
  }
  ListNode* temp = slow->next;
  slow->next = slow->next->next;
  delete temp;
  return head;
}