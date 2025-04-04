ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* sumList = new ListNode(0);
  ListNode* dummyHead = sumList;
  int carry = 0;
  while(l1!=NULL || l2!=NULL){
      int sum = carry;
      if(l1) sum+=l1->val;
      if(l2) sum+=l2->val;
      dummyHead->next = new ListNode(sum%10);
      carry = sum/10;
      dummyHead = dummyHead->next;
      if(l1) l1 = l1->next;
      if(l2) l2 = l2->next;
  }
  if(carry!=0){
      dummyHead->next = new ListNode(carry);
  }
  ListNode* temp = sumList;
  ListNode* newHead = temp->next;
  return newHead;;
}

// Time Complexity : O(N)
// Space Complexity : O(N)