class Node{
  public:
      int key;
      int value;
      Node* next;
      Node* prev;
      Node(int key, int value, Node* next = nullptr, Node* prev = nullptr) {
          this->key = key;
          this->value = value;
          this->next = next;
          this->prev = prev;
      }
  };
  
  class LRUCache {
  public:
      int capacity;
      unordered_map<int,Node*> mp;
      Node* head = new Node(-1, -1);
      Node* tail = new Node(-1, -1);
  
      LRUCache(int capacity) {
          this->capacity = capacity;
          head->next = tail;
          tail->prev = head;
      }
  
      void insertAfterHead(Node* node) {
          node->next = head->next;
          head->next->prev = node;
          head->next = node;
          node->prev = head;
      }
  
      void deleteNode(Node* node) {
          Node* afterNode = node->next;
          Node* prevNode = node->prev;
          afterNode->prev = prevNode;
          prevNode->next = afterNode;
      }
  
      int get(int key) {
          if(mp.find(key) == mp.end()) return -1;
          Node* node = mp[key];
          deleteNode(node);
          insertAfterHead(node);
          return node->value;
      }
  
      void put(int key, int value) {
          if(mp.find(key) != mp.end()) {
              Node* node = mp[key];
              node->value = value;
              deleteNode(node);
              insertAfterHead(node);
          } else {
              if(mp.size() == capacity) {
                  Node* node = tail->prev;
                  mp.erase(node->key);  
                  deleteNode(node);
              }
              Node* newNode = new Node(key, value);
              insertAfterHead(newNode);
              mp[key] = newNode;
          }
      }
  };
  