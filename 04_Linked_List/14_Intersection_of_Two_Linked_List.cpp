ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  set<ListNode*> st;
  ListNode* temp = headA;
  while(temp!=NULL){
      st.insert(temp);
      temp = temp->next;
  }
  temp = headB;
  while(temp!=NULL){
      if(st.find(temp)!=st.end()){
          return temp;
      }
      temp = temp->next;
  }
  return NULL;
}
// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
  public:
      int length(ListNode* head){
          ListNode* temp = head;
          int cnt = 0;
          while(temp!=NULL){
              cnt++;
              temp = temp->next;
          }
          return cnt;
      }
      ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
          int cnt1 = length(headA);
          int cnt2 = length(headB);
          int diff = abs(cnt1-cnt2);
          ListNode* temp1 = headA;
          ListNode* temp2 = headB;
          if(cnt1>cnt2){
              while(diff!=0){
                  diff--;
                  temp1 = temp1->next;
              }
          }
          if(cnt1<cnt2){
              while(diff!=0){
                  diff--;
                  temp2 = temp2->next;
              }
          }
          while(temp1!=NULL && temp2!=NULL){
              if(temp1==temp2) return temp1;
              temp1 = temp1->next;
              temp2 = temp2->next;
          }
          return NULL;
      }
      // Time Complexity : O(N+M)
      // Space Complexity : O(1)
    };


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode* A = headA;
      ListNode* B = headB;
      while(A!=B){
          A = A==NULL ? headB : A->next;
          B = B==NULL ? headA : B->next;
      }
      return A;
}

// Time Complexity : O(N+M)
// Space Complexity : O(1)
