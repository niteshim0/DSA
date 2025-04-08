class Solution {
  public:
      Node* flatten(Node* head) {
          Node* current = head;
          Node* tail = head;
          stack<Node*> st;
          while(current){
              if(current->child){
                  if(current->next){
                      st.push(current->next);
                      current->next->prev = NULL;
                  }
                  current->next = current->child;
                  current->next->prev = current;
                  current->child = NULL;
              }
              tail = current;
              current = current->next;
          }
          while(!st.empty()){
              Node* list = st.top();
              st.pop();
              current = list;
              tail->next = current;
              current->prev = tail;
              while(current){
                  tail = current;
                  current = current->next;
              }
          }
          return head;
      }
  };

// Time Complexity : O(N)
// Space Complexity : O(No. of childs)