ListNode *detectCycle(ListNode *head) {
  set<ListNode*> st;
  ListNode* temp = head;
  while(temp!=NULL){
      if(st.find(temp)!=st.end()){
          return temp;
      }
      st.insert(temp);
      temp = temp->next;
  }
  return temp;
}
// Time Complexity : O(NlogN)
// Space Complexity : O(N)

ListNode *detectCycle(ListNode *head) {
  ListNode* fast = head;
  ListNode* slow = head;
  while(fast!=NULL && fast->next!=NULL){
      fast = fast->next->next;
      slow = slow->next;
      if(slow == fast){
          slow = head;
          while(slow!=fast){
              slow = slow->next;
              fast = fast->next;
          }
          return slow;
      }
  }
  return NULL;
}
// Time Complexity : O(N)
// Space Complexity : O(1)
