class MyStack {
  private:
    queue<int> q;
  public:
      MyStack() {
          
      }
      
      void push(int x) {
          q.push(x);
          int sz = q.size();
          for(int i = 1;i<sz;i++){
              q.push(q.front());
              q.pop();
          }
      }
      
      int pop() {
          int temp = q.front();
          q.pop();
          return temp;
      }
      
      int top() {
          return q.front();
      }
      
      bool empty() {
          return q.size()==0;
      }
};
  