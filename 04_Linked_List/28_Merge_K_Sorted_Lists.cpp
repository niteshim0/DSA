class Solution {
  public:
      ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
          ListNode* dummyNode = new ListNode(0);
          ListNode* temp = dummyNode;
          while(list1!=NULL && list2!=NULL){
              if(list1->val < list2->val){
                  temp->next = list1;
                  list1 = list1->next;
              }else{
                  temp->next = list2;
                  list2 = list2->next;
              }
              temp = temp->next;
          }
          list1==NULL ? temp->next = list2 : temp->next = list1;
          temp = dummyNode->next;
          delete dummyNode;
          return temp;
      }
      ListNode* mergeKLists(vector<ListNode*>& lists) {
          if(lists.size()==0) return NULL;
          queue<ListNode*> q;
          for(int i = 0;i<lists.size();i++){
              if(lists[i]!=NULL){
                  q.push(lists[i]);
              }
          }
          if(q.size()==0) return NULL;
          while (q.size() > 1) {
              ListNode* list1 = q.front(); q.pop();
              ListNode* list2 = q.front(); q.pop();
  
              ListNode* merged = mergeTwoLists(list1, list2);
              q.push(merged);
          }
  
          return q.front();
      }
  };
// Time Complexity : O(N*N*N)
// Space Complexity : O(N)

class Solution {
  public:
      ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
          ListNode* dummyNode = new ListNode(0);
          ListNode* temp = dummyNode;
          while(list1!=NULL && list2!=NULL){
              if(list1->val < list2->val){
                  temp->next = list1;
                  list1 = list1->next;
              }else{
                  temp->next = list2;
                  list2 = list2->next;
              }
              temp = temp->next;
          }
          list1==NULL ? temp->next = list2 : temp->next = list1;
          temp = dummyNode->next;
          delete dummyNode;
          return temp;
      }
      ListNode* mergeKLists(vector<ListNode*>& lists) {
          if(lists.size()==0) return NULL;
          ListNode* head = lists[0];
          int n = lists.size();
          for(int i = 1;i<n;i++){
              head = mergeTwoLists(head,lists[i]);
          }
          return head;
}
// Time Complexity : O(N*K*K)
// Space Complexity : O(1)

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<pair<int,ListNode*>,
            vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
            int n = lists.size();
            for(int i = 0;i<n;i++){
                if(lists[i]){
                    pq.push({lists[i]->val,lists[i]});//kLogk
                }
            }
            ListNode* dummyNode = new ListNode(-1);
            ListNode* temp = dummyNode;
            while(!pq.empty()){
              auto el = pq.top(); pq.pop();
              if(el.second->next){
                pq.push({el.second->next->val,el.second->next});
              }
              temp->next = el.second;
              temp = temp->next;
            }
            temp = dummyNode->next;
            delete dummyNode;
            return temp;
        }
    };

// Time Complexity : K*N*LogK*N
// Space Complexity : O(1)