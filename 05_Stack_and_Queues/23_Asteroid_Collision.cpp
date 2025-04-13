class Solution {
  public:
      vector<int> asteroidCollision(vector<int>& asteroids) {
          vector<int> st;
          for(int x : asteroids){
              if(x>0){
                  st.push_back(x);
              }else{
                  while(!st.empty() && st.back()>0 && -x > st.back()){
                      st.pop_back();
                  }
                  if(st.empty() || st.back()<0){
                      st.push_back(x);
                  }
                  if(st.back()==-x){
                      st.pop_back();
                  }
              }
          }
          return st;
      }
  };
  // Time Complexity : O(2N)
  // Space Complexity : O(N)