bool isPalindrome(ListNode* head) {
  stack<int> st;
  ListNode* temp = head;
  while(temp!=NULL){
      st.push(temp->val);
      temp = temp->next;
  }
  temp = head;
  while(temp!=NULL){
      if(temp->val != st.top()){
         return false;
      }
      st.pop();
      temp = temp->next;
  }
  return true;
}
// Time Complexity : O(2N)
// Space Complexity : O(N)


ListNode* middleNode(ListNode* head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while(fast!=NULL && fast->next!=NULL){
      fast = fast->next->next;
      slow = slow->next;
  }
  return slow;
}
ListNode* reverseList(ListNode* head) {
  ListNode* current = head;
  ListNode* prev = NULL;
  while(current!=NULL){
      ListNode* next = current->next;
      current->next = prev;
      prev = current;
      current = next;
  }
  return prev;
}
bool isPalindrome(ListNode* head) {
  ListNode* middle = middleNode(head);
  ListNode* first = head;
  ListNode* second = reverseList(middle);
  while(second!=NULL){
      if(first->val !=second->val){
          reverseList(middle);
          return false;
      }else{
          first = first->next;
          second = second->next;
      }
  }
  reverseList(middle);
  return true;
}

// Time Complexity : O(2N)
// Space Complexity : O(1)