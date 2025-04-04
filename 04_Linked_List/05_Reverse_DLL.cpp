// Brute Force
DLLNode* reverseDLL(DLLNode* head) {
  DLLNode* temp = head;
  stack<int> st;
  while(temp!=NULL){
      st.push(temp->data);
      temp = temp->next;
  }
  temp = head;
  while(temp!=NULL){
      temp->data = st.top();
      st.pop();
      temp = temp->next;
  }
  return head;
}
// Time Complexity : O(N)
// Space Complexity : O(N)

DLLNode* reverseDLL(DLLNode* head) {
  if(head == NULL || head->next == NULL){
      return head;
  }
  DLLNode* current = head;
  DLLNode* last = NULL;
  while(current!=NULL){
      last = current->prev;
      current->prev = current->next;
      current->next = last;
      current = current->prev;
  }
  head = last->prev;
  return head;
}
// Time Complexity : O(N)