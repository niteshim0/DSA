class MinStack {
  private:
  stack<pair<int,int>> st;
  public:
      MinStack() {
          
      }
      
      void push(int val) {
          if(st.empty()){
              st.push({val,val});
          }else{
              st.push({val,min(st.top().second,val)});
          }
      }
      
      void pop() {
          st.pop();
      }
      
      int top() {
          return st.top().first;
      }
      
      int getMin() {
          return st.top().second;
      }
  };
// Time Complexity : O(1)
// Space Complexity : O(2*N)

// Approach :: 2 - Better space optimised

class MinStack {
  private:
      stack<long long> st;
      long long mini;
  public:
      MinStack() {
          mini = LONG_MAX;
      }
  
      void push(int val) {
          if(st.empty()) {
              st.push(val);
              mini = val;
          } else {
              if(val >= mini) {
                  st.push(val);
              } else {
                  st.push(2LL * val - mini); // Encode value
                  mini = val;
              }
          }
      }
  
      void pop() {
          if(st.empty()) return;
          long long x = st.top(); st.pop();
          if(x < mini) {
              mini = 2LL * mini - x; // Decode previous mini
          }
      }
  
      int top() {
          if(st.empty()) return -1;
          long long x = st.top();
          return (x < mini) ? mini : x;
      }
  
      int getMin() {
          return mini;
      }
  };
// Time Complexity : O(1)
// Space Complexity : O(N)  