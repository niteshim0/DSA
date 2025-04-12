class Solution {
  public:
    bool isOperand(char ch){
        return ((ch >= 'A' && ch <= 'Z') || 
                (ch >= 'a' && ch <= 'z') || 
                (ch >= '0' && ch <= '9'));
    }
    string preToPost(string s) {
        int n = s.size();
        int i = n-1;
        stack<string> st;
        while(i>=0){
            if(isOperand(s[i])){
                st.push(string(1,s[i]));
            }else{
                string op1 = st.top();st.pop();
                string op2 = st.top();st.pop();
                string con = op1 + op2 + s[i];
                st.push(con);
            }
            i--;
        }
        return st.top();
    }
};
// Time Complexity : O(2N)
// Space Complexity : O(N)