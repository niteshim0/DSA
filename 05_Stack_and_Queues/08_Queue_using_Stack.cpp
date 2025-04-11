// Approach-1 :: If push operations are less , other operation are more

class MyQueue {
  stack<int> s1;
  stack<int> s2;
public:
  MyQueue() {
      
  }
  
  void push(int x) {
      while(!s1.empty()){
          s2.push(s1.top());
          s1.pop();
      }
      s1.push(x);
      while(!s2.empty()){
          s1.push(s2.top());
          s2.pop();
      }
  }
  
  int pop() {
      int x = s1.top();
      s1.pop();
      return x;
  }
  
  int peek() {
      return s1.top();
  }
  
  bool empty() {
      return s1.empty();
  }
};


// Approach-2 :: If push operations are more

class MyQueue {
  stack<int> s1;
  stack<int> s2;
public:
  MyQueue() {
      
  }
  
  void push(int x) {
      s1.push(x);
  }
  
  int pop() {
      if(!s2.empty()){
          int x = s2.top();
          s2.pop();
          return x;
      }
      while(!s1.empty()){
          s2.push(s1.top());
          s1.pop();
      }
      int x = s2.top();
      s2.pop();
      return x;
  }
  
  int peek() {
      if(!s2.empty()){
          return s2.top();
      }
      while(!s1.empty()){
          s2.push(s1.top());
          s1.pop();
      }
      return s2.top();
  }
  
  bool empty() {
      return s2.empty() && s1.empty();
  }
};