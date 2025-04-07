class Solution {
  public:
      ListNode* findLastNode(ListNode* head,int len){
          ListNode* temp = head;
          while(len--){
              temp = temp->next;
          }
          return temp;
      }
      ListNode* rotateRight(ListNode* head, int k) {
          if(k==0 || head == NULL) return head;
          ListNode* temp = head;
          ListNode* tail = head;
          int len = 1;
          while(tail->next!=NULL){
              tail = tail->next;
              len++;
          }
          k = k%len;
          if(k==0) return head;
  
          ListNode* lastNode = findLastNode(temp,len-k-1);
          tail->next = head;
          head = lastNode->next;
          lastNode->next = NULL;
          
          return head;
      }
  };
// Time Complexity : O(2N)
// Space Complexity : O(1)