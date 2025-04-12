class Solution {
  public:
      bool isValid(string s) {
          unordered_map<char,int> mp = {{'(',-1},{'{',-2},{'[',-3},{')',1},{'}',2},{']',3}};
          stack<int> st;
          for(char &ch : s){
              if(mp[ch]<0){
                 st.push(mp[ch]);
              }else{
                  if(st.empty()) return false; // if all the brackets are closing ones
                  char top = st.top();st.pop();
                  if((mp[ch] + top)!=0) return false;
              }
          }
          return st.empty();
      }
  };
// Time Complexity : O(N)
// Space Complexity : O(N)