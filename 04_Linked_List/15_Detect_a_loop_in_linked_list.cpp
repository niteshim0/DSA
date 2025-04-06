bool hasCycle(ListNode *head) {
  set<ListNode*> st;
  ListNode* temp = head;
  while(temp!=NULL){
      if(st.find(temp)!=st.end()) return true;
      st.insert(temp);
      temp = temp->next;
  }
  return false;
}
// Time Complexity : O(NlogN)
// Space Complexity : O(N)

bool hasCycle(ListNode *head) {
  ListNode* slow = head;
  ListNode* fast = head;
  while(fast!=NULL && fast->next!=NULL){
      fast = fast->next->next;
      slow = slow->next;
      if(slow == fast) return true;
  }
  return false;
}
// Time Complexity : O(N)
// Space Complexity : O(1)