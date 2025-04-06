class Solution {
  public:
      int length(ListNode* head){
          int cnt = 0;
          ListNode* temp = head;
          while(temp!=NULL){
              cnt++;
              temp = temp->next;
          }
          return cnt;
      }
      ListNode* deleteMiddle(ListNode* head) {
          int mid = length(head);
          if(mid<=1){
              return NULL;
          }
          int res = mid/2-1;
          ListNode* temp = head;
          while(res!=0){
              res--;
              temp = temp->next;
          }
          ListNode* delNode = temp->next;
          temp->next = temp->next->next;
          delete delNode;
          return head;
      }
};
// Time Complexity : O(N + N/2)
// Space Complexity : O(1)
// Two Pass Solution

ListNode* deleteMiddle(ListNode* head) {
  if(head==NULL || head->next == NULL){
      return NULL;
  }
  ListNode* slow = head;
  ListNode* fast = head;
  fast = fast->next->next;
  while(fast!=NULL && fast->next!=NULL){
      slow = slow->next;
      fast = fast->next->next;
  }
  ListNode* delNode = slow->next;
  slow->next = slow->next->next;
  delete delNode;
  return head;
}
// Time Complexity : O(N)
// Space Complexity : O(1)

