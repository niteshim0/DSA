class Solution {
  public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
          Node* dummyNode = new Node(0);
          Node* temp = dummyNode;
  
          while (list1 != NULL && list2 != NULL) {
              if (list1->data < list2->data) {
                  temp->bottom = list1;
                  list1 = list1->bottom;
              } else {
                  temp->bottom = list2;
                  list2 = list2->bottom;
              }
              temp = temp->bottom;
          }
  
          // Attach the remaining part
          if (list1 != NULL) temp->bottom = list1;
          else temp->bottom = list2;
  
          Node* result = dummyNode->bottom;
          delete dummyNode;
          return result;
      }
    Node *flatten(Node *root) {
        if (root == NULL || root->next == NULL) return root;
  
          queue<Node*> q;
          Node* temp = root;
  
          while (temp != NULL) {
              q.push(temp);
              temp = temp->next;
          }
  
    
          while (q.size() > 1) {
              Node* list1 = q.front(); q.pop();
              Node* list2 = q.front(); q.pop();
  
              Node* merged = mergeTwoLists(list1, list2);
              q.push(merged);
          }
  
          return q.front();
        
    }
};

// we will do more approaches 