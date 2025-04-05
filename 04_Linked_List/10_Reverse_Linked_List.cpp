ListNode* reverseList(ListNode* head) {
  stack<int> st;
  ListNode* temp = head;
  while(temp!=NULL){
      st.push(temp->val);
      temp = temp->next;
  }
  temp = head;
  while(temp!=NULL){
      temp->val = st.top();
      st.pop();
      temp = temp->next;
  }
  return head;
}
// Reversal in terms of data not links
// Time Complexity : O(N)
// Space Complexity : O(N)

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
// Time Complexity : O(N)
// Space Complexity : O(1)