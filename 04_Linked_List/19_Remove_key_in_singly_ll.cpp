ListNode* removeElements(ListNode* head, int val) {
  ListNode* prev = NULL;
  ListNode* current = head;
  while(current!=NULL){
      if(current->val == val){
          if(current == head){
              head = head->next;
          }else if(current->next == NULL){
              prev->next = NULL;
          }else{
              prev->next = current->next;
              current = prev;
          }
      }
      prev = current;
      current = current->next;
  }
  return head;
}
// Time Complexity : O(N)
// Space Complexity : O(1)