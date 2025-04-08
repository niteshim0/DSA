class Solution {
  public:
      // Function to merge two sorted linked lists using bottom pointers
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
  
      // Function to flatten the linked list using a queue (iterative approach)
      Node* flatten(Node* root) {
          if (root == NULL || root->next == NULL) return root;
  
          queue<Node*> q;
          Node* temp = root;
  
          // Push all head nodes into the queue
          while (temp != NULL) {
              q.push(temp);
              temp = temp->next;
          }
  
          // Merge lists two at a time
          while (q.size() > 1) {
              Node* list1 = q.front(); q.pop();
              Node* list2 = q.front(); q.pop();
  
              Node* merged = mergeTwoLists(list1, list2);
              q.push(merged);
          }
  
          return q.front(); // Final flattened list
      }
  };

// Time Complexity  = O(N*(N+M))
// Space Complexity = O(N)


class Solution {
  public:
      // Function to merge two sorted linked lists using bottom pointers
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
  
      // Function to flatten the linked list using a queue (iterative approach)
      Node* flatten(Node* root) {
          if (root == NULL || root->next == NULL) return root;
  
          Node* mergedRoot = flatten(root->next);
          
          return  mergeTwoLists(root,mergedRoot);
      }
  };
// Time Complexity : O(N*2M)
// Space Complexity : O(N) // recursion stack space


class Solution {
  public:
      // Function to merge two sorted linked lists using bottom pointers
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
  
      // Function to flatten the linked list using a queue (iterative approach)
      Node* flatten(Node* head) {
          if(head==NULL || head->next==NULL)
              return head;
          Node* prev = head, *nxt = head;
          while(head->next!=NULL) {
              prev = head;
              head = head->next;
              nxt = head->next;
              head = mergeTwoLists(head, prev);
              head->next = nxt;
          }
          return head;
      }
  };
// Time Complexity : O(N*2M)
// Space Complexity : O(1)