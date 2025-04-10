class Solution {
  public:
      Node* copyRandomList(Node* head) {
          Node* temp = head;
          map<Node*,Node*> mp;
          // creating [original,copy] list
          while(temp!=NULL){
              mp[temp] = new Node(temp->val);
              temp = temp->next;
          }
  
          // making the deep copy
          temp = head;
          while(temp!=NULL){
              mp[temp]->next = mp[temp->next];
              mp[temp]->random = mp[temp->random];
              temp = temp->next;
          }
          return mp[head];
      }
  };
  // Time Complexity : O(2N)
  // Space Complexity : O(N)

// Removing the space :: Optimal solution

class Solution {
  public:
      Node* copyRandomList(Node* head) {
          Node* temp = head;
          // creating upper list
          while(temp!=NULL){
              Node* copyNode = new Node(temp->val);
              copyNode->next = temp->next;
              temp->next = copyNode;
              temp  = temp->next->next;
          }
          // creating random pointers;
          temp = head;
          while(temp!=NULL){
              Node* copyNode = temp->next;
              copyNode->random = temp->random==NULL ? NULL : temp->random->next;
              temp = temp->next->next;
          }
          // restoring the original list 
          // creating the deep copy by connecting them with next pointers;
          Node* dummy = new Node(0);
          Node* res = dummy;
          temp = head;
          while(temp!=NULL){
              res->next = temp->next;
              temp->next = temp->next->next;
              res = res->next;
              temp = temp->next;
          }
          res = dummy->next;
          delete dummy;
          return res;
      }
  };
// Time Complexity : O(3N)
// Space Complexity : O(N) // because question demands we are not using it for 
// calculating the answer