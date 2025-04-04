ListNode* oddEvenList(ListNode* head) {
  if(head == NULL || head->next == NULL) return head;
  ListNode* oddHead = head;
  ListNode* evenHead = head->next;
  ListNode* even = evenHead;
  ListNode* odd = oddHead;
  while(even!=NULL && even->next!=NULL){
      odd->next = odd->next->next;
      even->next = even->next->next;

      odd = odd->next;
      even = even->next;
  }
  odd->next = evenHead;
  return oddHead;
}
// Time Complexity : O(N)
// Space Complexity : O(1)