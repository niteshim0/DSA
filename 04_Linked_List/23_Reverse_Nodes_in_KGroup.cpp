class Solution {
  public:
      int  listLen(ListNode* head){
          int cnt = 0;
          ListNode* temp = head;
          while(temp!=NULL){
              cnt++;
              temp = temp->next;
          }
          return cnt;
      }
      ListNode* reverseKGroup(ListNode* head, int k) {
          if(k<=1 || head == NULL){
              return head;
          }
  
          int div = listLen(head)/k;
  
          ListNode* prev = NULL;
          ListNode* current = head;
          
          while(div--){
              ListNode* last = prev;
              ListNode* newEnd = current;
  
              for(int i = 0;i<k&&current!=NULL;i++){
                  ListNode* next = current->next;
                  current->next = prev;
                  prev = current;
                  current = next;
              }
              if(last!=NULL){
                  last->next = prev;
              }else{
                  head = prev;
              }
  
              newEnd->next = current;
              prev = newEnd;
          }
          return head;
      }
  };

// Time Complexity : O(2N)
// Space Complexity : O(1)


// Another Approach(Personally I like the first one)
class Solution {
  public:
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
      ListNode* findKth(ListNode* head,int k){
          ListNode* temp = head;
          k-=1;
          while(temp!=NULL && k>0){
              temp = temp->next;
              k--;
          }
          return temp;
      }
      ListNode* reverseKGroup(ListNode* head, int k) {
          ListNode* temp = head;
          ListNode* prevLast = NULL;
          while(temp!=NULL){
              ListNode* KthNode = findKth(temp,k);
              if(KthNode == NULL){
                  if(prevLast){
                      prevLast->next = temp;
                  }
                  break;
              }
              ListNode* nextNode = KthNode->next;
              KthNode->next = NULL;
              reverseList(temp);
              if(temp == head){
                  head = KthNode;
              }else{
                  prevLast->next = KthNode;
              }
              prevLast = temp;
              temp = nextNode;
          }
          return head;
      }
  };
// Time Complexity : O(2N)
// Space Complexity : O(1)