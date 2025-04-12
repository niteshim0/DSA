class Solution {
  public:
   bool isOperand(char ch){
        return ((ch >= 'A' && ch <= 'Z') || 
                (ch >= 'a' && ch <= 'z') || 
                (ch >= '0' && ch <= '9'));
    }
    string postToPre(string s) {
        int n = s.size();
        int i = 0;
        stack<string> st;
        while(i<n){
            if(isOperand(s[i])){
                st.push(string(1,s[i]));
            }else{
                string op1 = st.top();st.pop();
                string op2 = st.top();st.pop();
                string con = s[i] + op2 + op1;
                st.push(con);
            }
            i++;
        }
        return st.top();
    }
};
// Time Complexity : O(2N)
// Space Complexity : O(N)