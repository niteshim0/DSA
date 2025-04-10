class DLLNode{
  public:
  string data;
  DLLNode* next;
  DLLNode* prev;
  DLLNode(string data){
      this->data = data;
      this->next = NULL;
      this->prev = NULL;
  }
  DLLNode(string data,DLLNode* prev){
      this->data = data;
      this->prev = prev;
      this->next = NULL;
  }
  DLLNode(string data,DLLNode* next,DLLNode* prev){
      this->data = data;
      this->next = next;
      this->prev = prev;
  }
};


class BrowserHistory {
  DLLNode* current;
public:
  BrowserHistory(string homepage) {
     
      current = new DLLNode(homepage);
  }
  
  void visit(string url) {
      current->next = new DLLNode(url,current);
      current = current->next;
  }
  
  string back(int steps) {
      while(steps>0){
          if(current->prev){
              current = current->prev;
          }else{
              break;
          }
          steps--;
      }
      return current->data;
  }
  
  string forward(int steps) {
      while(steps>0){
          if(current->next){
              current = current->next;
          }else{
              break;
          }
          steps--;
      }
      return current->data;
  }
};
// Time Complexity  : O(2N)

// Space Complexity : O(no. of visits + 1)