class Solution {
  public:
      ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
          ListNode* dummyNode = new ListNode(0);
          ListNode* temp = dummyNode;
          while(list1!=NULL && list2!=NULL){
              if(list1->val < list2->val){
                  temp->next = list1;
                  list1 = list1->bottom;
              }else{
                  temp->next = list2;
                  list2 = list2->bottom;
              }
              temp = temp->next;
          }
          list1==NULL ? temp->next = list2 : temp->next = list1;
          temp = dummyNode->next;
          delete dummyNode;
          return temp;
      }
  };
// Time Complexity : O(N+N/2)(logN)
// Space Complexity : O(logN) for recursive stack space